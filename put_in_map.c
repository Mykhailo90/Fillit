/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:19:19 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/25 20:19:21 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"
#include <stdio.h>

static void set_termino(char **map, t_list *l, int i, int n)
{
	map[i][n] = l->ch;
	map[l->y[1] - l->y[0] + i][n + l->x[1] - l->x[0]] = l->ch;
	map[l->y[2] - l->y[0] + i][n + l->x[2] - l->x[0]] = l->ch;
	map[l->y[3] - l->y[0] + i][n + l->x[3] - l->x[0]] = l->ch;
}

static int check_set_termino(char **map, t_list *l, int i, int n, int size_map)
{
	if ((l->y[1] - l->y[0] + i < size_map) &&
		(l->x[1] - l->x[0] + n < size_map) &&
		map[l->y[1] + i][l->x[1] - l->x[0] + n] == '.' &&
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

static int	count_map_len(char ** map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char		**put_in_map(char **map, t_list *l)
{
	int i;
	int n;
	int check;
	
	t_list *start;
	int	size_map;
		
	start = l;	
	n = 0;
	check = 0;	
	i = 0;
	size_map = count_map_len(map);

	while (l)
	{		
		size_map = count_map_len(map);
		while (map[i])
		{			

			n = 0;
			while (map[i][n] != '\0')
			{		
				if (map[i][n] == '.')
				{
					check = check_set_termino(map, l, i, n, size_map);
					if (check) 
					{
						set_termino(map, l, i, n);
						if (l->next)
							l = l->next;
						else
						{
							l = NULL;
							return (map);
						}
						n = 0;
						i = 0;
					}
					else					
						n++;
				}
				else
					n++;

			}
			i++;
		}		
						
		if (l)
		{			
			map = creat_map(i);
			map = put_in_map(map, start);
			
		}
		if (l->next)
			l = l->next;
		else
			return (map);
			
	}
	return (map);
}
