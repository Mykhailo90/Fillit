/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_termino.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:50:27 by msarapii          #+#    #+#             */
/*   Updated: 2017/12/14 12:46:38 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"

void	set_termino(char **map, t_list *l, int i, int n)
{
	map[i][n] = l->ch;
	map[l->y[1] - l->y[0] + i][n + l->x[1] - l->x[0]] = l->ch;
	map[l->y[2] - l->y[0] + i][n + l->x[2] - l->x[0]] = l->ch;
	map[l->y[3] - l->y[0] + i][n + l->x[3] - l->x[0]] = l->ch;
}
