/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_set_termino.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:54:58 by msarapii          #+#    #+#             */
/*   Updated: 2017/12/14 12:13:39 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"

int	check_set_termino(char **map, t_list *l, int i, int n)
{
	int size_map;

	size_map = count_map_len(map);
	if (i < size_map && n < size_map &&
		map[i][n] == '.' &&
		(l->y[1] - l->y[0] + i < size_map) &&
		(l->x[1] - l->x[0] + n < size_map) &&
		map[l->y[1] - l->y[0] + i][l->x[1] - l->x[0] + n] == '.' &&
		(l->y[2] - l->y[0] + i < size_map) &&
		(l->x[2] - l->x[0] + n < size_map) &&
		map[l->y[2] - l->y[0] + i][l->x[2] - l->x[0] + n] == '.' &&
		(l->y[3] - l->y[0] + i < size_map) &&
		(l->x[3] - l->x[0] + n < size_map) &&
		map[l->y[3] - l->y[0] + i][l->x[3] - l->x[0] + n] == '.')
		return (1);
	else
		return (0);
}
