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

static char  **set_termino(char **map, t_list *l, int i, int n)
{
	map[i][n] = l->ch;
	map[l->y[1] - l->y[0] + i][n + l->x[1] - l->x[0]] = l->ch;
	map[l->y[2] - l->y[0] + i][n + l->x[2] - l->x[0]] = l->ch;
	map[l->y[3] - l->y[0] + i][n + l->x[3] - l->x[0]] = l->ch;
	return (map);
}

static int check_set_termino(char **map, t_list *l, int i, int n, int size_map)
{

	if (map[i][n] == '.' &&
		(l->y[1] - l->y[0] + i < size_map) &&
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

static int 	search_point(char **map, t_list *l, int x, int y)
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

char	**solver(int size, t_list *l)
{

	size = 4;
	char **map;
	map = creat_map(size);
	
	func(map, l, size);
	// while ((func(map, l, size)))
	// {
	// 	size++;
	// 	map = creat_map(size);
	// }
	//map[0][0] = 'A';
	return (map);
}

int		func(char **map, t_list *l, int size)
{
	int		x;
	int		y;


	y = 0;
	if (!l)
		return (1);
	while (y < size )
	{

		x = 0;
		while (x < size )
		{
			if (search_point(map, l, x, y))
			{
				map = set_termino(map,l, y, x);
				l = l->next;
				if (l == NULL)
					return (1);
				// printf("map:%s\n", map[0]);
				// if (func(map, l->next, size))
				// 	return (1);
				// else
				// map = delete_tetrimoino(map, l->ch);
			}
			x++;
		}
		y++;
	}

	return (0);
}
