#include "../pipex.h"

char    **getpath(char **envp)
{
    int i;
    char    **tmpath;
    
    i = 0;
    while (envp[i] != NULL)
    {
        if (ft_strncmp(envp[i], "PATH=", 5))
            tmpath = ft_split(envp[i] + 5, ':');
        i++;
    }
    return (tmpath);
}

char    *findpath(char *command, char **envp)
{
    char *slash;
    char **splitenv;
    char *jcommand;
    int i;

    i = 0;
    if (ft_strchr(command, '/'))
    {
        if (!access(command, F_OK))
            return (command);
        else
            return (0);
    }
    else
    {
        splitenv = getpath(envp);
        while(splitenv[i])
        {
            slash = ft_strjoin(splitenv[i], "/");
            jcommand = ft_strjoin(slash, command);
            if (!access(jcommand , F_OK))
                return (jcommand);
            i++;
        }
    }
    return (0);
}