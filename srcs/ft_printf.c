/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajdoub <omajdoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:10:27 by omajdoub          #+#    #+#             */
/*   Updated: 2023/02/04 19:10:34 by omajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_pstr(char *str)
{
	int	retu;

	retu = 0;
	if (!str)
	{
		retu += write(2, "(null)", 6);
	}
	else
	{
		while (str[retu])
			write(2, &str[retu++], 1);
	}
	return (retu);
}

void	ft_printf(const char *specif, ...)
{
	int		i;
	va_list	args;

	va_start(args, specif);
	i = 0;
	while (specif[i])
	{
		if (specif[i] == 37)
		{
			i++;
			if (specif[i] == 's')
			{
				ft_pstr(va_arg(args, char *));
			}
		}	
		else
			write(2, &specif[i], 1);
		i++;
	}
}
