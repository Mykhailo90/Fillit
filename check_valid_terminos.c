/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_terminos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:30:27 by msarapii          #+#    #+#             */
/*   Updated: 2017/12/14 12:15:05 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"

static void		check_one_termino(char *str)
{
	int			point;
	int			sl;
	int			n;

	point = 0;
	sl = 0;
	n = 0;
	while (*str != '\0')
	{
		if (*str == '.')
			point++;
		else if (*str == '#')
			sl++;
		else if (*str == '\n')
			n++;
		str++;
	}
	if (point != 12 || sl != 4 || n != 4)
	{
		ft_putstr("error\n");
		exit(1);
	}
}

static void		check_one_termino2(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str != '\n')
			i++;
		else if (*str == '\n' && i != 4)
		{
			ft_putstr("error\n");
			exit(1);
		}
		else
			i = 0;
		str++;
	}
}

static void		check_one_termino3(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n' && str[i + 2] == '\n')
		{
			ft_putstr("error\n");
			exit(1);
		}
		i++;
	}
}

void			check_valid_terminos(char **ar)
{
	int			j;

	j = 0;
	while (ar[j])
	{
		check_one_termino(ar[j]);
		check_one_termino2(ar[j]);
		check_one_termino3(ar[j]);
		j++;
	}
}
