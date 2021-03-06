/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:19:19 by msarapii          #+#    #+#             */
/*   Updated: 2017/12/14 12:44:33 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"

char	**put_in_map(int size, t_list *l)
{
	char **map;

	map = creat_map(size);
	size = count_map_len(map);
	while (!func_rec(map, l, size))
	{
		size++;
		map = creat_map(size);
	}
	return (map);
}
