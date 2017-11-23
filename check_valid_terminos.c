/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_terminos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:30:27 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/23 15:29:12 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"

void	check_valid_terminos(char **ar, size_t size)
{
	int	point;
	int	sl;
	int	n;
	int i;

	while (size--)
	{
		i = 0;
		point = 0;
		sl = 0;
		n = 0;
		while (*ar[i])
		{
			if (*ar[i] == '.')
				point++;
			else if (*ar[i] == '#')
				sl++;
			else if (*ar[i] == '\n')
				n++;
			i++;
		}
		if (point != 12 && sl != 4 && n != 3)
		{
			ft_putstr("error\n");
			exit(1);
		}
	}
}
