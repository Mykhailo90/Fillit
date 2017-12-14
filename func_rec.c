/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:26:09 by msarapii          #+#    #+#             */
/*   Updated: 2017/12/14 12:30:06 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"

int		func_rec(char **map, t_list *l, int size)
{
	t_xy	xy;

	xy.y = 0;
	if (!l)
		return (1);
	while (xy.y < size)
	{
		xy.x = 0;
		while (xy.x < size)
		{
			if (check_set_termino(map, l, xy.y, xy.x))
			{
				set_termino(map, l, xy.y, xy.x);
				if (l == NULL)
					return (0);
				if (func_rec(map, l->next, size))
					return (1);
				else
					map = delete_tetrimoino(map, l->ch);
			}
			xy.x++;
		}
		xy.y++;
	}
	return (0);
}
