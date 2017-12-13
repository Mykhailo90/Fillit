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

static void  set_termino(char **map, t_list *l, int i, int n)
{
	map[i][n] = l->ch;
	map[l->y[1] - l->y[0] + i][n + l->x[1] - l->x[0]] = l->ch;
	map[l->y[2] - l->y[0] + i][n + l->x[2] - l->x[0]] = l->ch;
	map[l->y[3] - l->y[0] + i][n + l->x[3] - l->x[0]] = l->ch;
}

static int	count_map_len(char ** map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static int check_set_termino(char **map, t_list *l, int i, int n, int size_map)
{	
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
		map[l->y[3] - l->y[0] + i][l->x[3] - l->x[0] + n] == '.'){
	
			return (1);}
		else
			return (0);
}

char	**delete_tetrimoino(char **map, char ch)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (map[i])
	{
		n = 0;
		while (map[i][n] != '\0')
		{
			if (map[i][n] == ch)
			{
				map[i][n] = '.';
			}
			n++;
		}
		i++;
	}
	return (map);
}

char	**put_in_map(int size, t_list *l)
{	
	char **map;

	map = creat_map(size);
	while (!func(map, l, size))
	{			
	    	size++;
	    	map = creat_map(size);
	}
	return (map);
}

int		func(char **map, t_list *l, int size)
{
	int		x;
	int		y;	
	
	y = 0;	
	if (!l)
		return (1);
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (check_set_termino(map, l, y, x, size))
			{
				set_termino(map,l, y, x);
				if (l == NULL)
					return (0);
				if (func(map, l->next, size))
				 	return (1);
				else
				 map = delete_tetrimoino(map, l->ch);
			}
			x++;
		}
		y++;
	}
	return (0);
}
