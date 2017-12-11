/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 09:13:57 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/25 09:13:58 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"

char			**creat_map(int j)
{
	char		**map;
	int		i;
	int		n;
	
	i = 0;
	n = 0;	
	while (i * i <= 4 * j)
		i++;
	if (!(map = (char **)ft_memalloc(sizeof(char *) * (i + 1))))

		return (NULL);
	map[i] = 0;
	while (n < i)

	{
		map[n] = (char *)ft_memalloc(sizeof(char) * (i + 1));
		n++;
	}
	n = 0;
	while (map[n])
	{
		ft_memset(map[n], '.', sizeof(char) * i);
		n++;
	}	
	return (map);
}
