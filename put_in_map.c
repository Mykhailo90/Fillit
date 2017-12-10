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

int 	search_point(char **map, t_list *l, int *x, int *y)
{
	int size_map;
		
	size_map = count_map_len(map);
	while (y < size_map)
	{
		x = 0;
		while (x < size_map)
		{
			if (map[y][x] == '.')
			{
				if(check_set_termino(map, l, y, x, size_map))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

char		**put_in_map(char **map, t_list *l, int x, int y)
{	
	t_list *start;	
	char **prev_map;
	
	prev_map = map;
	start = l;
	while (l)
	{

	if (search_point(map, l, &x, &y))
	{		
		set_termino(map, l, y, x);
		prev_map = map;
		if (l->next)
		{
			l = l->next;
			map = put_in_map(map, l, x, y)
		}
		else
		{
			l = NULL;
			return (map);
		}					
	}
	else
	{
		if (l->prev)
		{
			l = l->prev;
			map = put_in_map(prev_map, l, x)
		}
		map = creat_map(count_map_len(map) + 1);
		map = put_in_map(map, l, x, y);
	}
	}
	
	/*
	while (l)
	{
		size_map = count_map_len(map);
		while (map[y])
		{
			x = 0;
			while (map[y][x] != '\0')
			{	
				if (map[y][x] == '.')
				{
					check = check_set_termino(map, l, y, x, size_map);
					if (check) 
					{						
						set_termino(map, l, y, x);						
						if (l->next)
						{
							l = l->next;
						}
						else
						{
							l = NULL;
							return (map);
						}
						x = 0;
						y = 0;
					}
					else	
						x++;
				}
				else
					x++;
			}
			y++;
		}

						
		if (l)
		{

			while (l->prev)
			{
				l = l->prev;

			} 
			map = creat_map(y);
			map = put_in_map(map, start);
			
		}
		if (l->next)
			l = l->next;
		else
			return (map);
			
	}
	*/
	return (map);
}
