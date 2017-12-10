/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:59:21 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/24 17:01:45 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"
#include <stdio.h>

int	main(int arg, char **argv)
{
	char	**ar;
	char	**map;
	char	*buffer;
	char	*list_buf;
	size_t	j;
		
	size_t a;
	a = 0;
	if (arg != 2)
	{
		ft_putstr("Usage: You must take only one parametr!\n");
		exit(1);
	}
	buffer = (char *)ft_memalloc(550);
	list_buf = read_list(argv, buffer);
	ar = ft_strsplit(list_buf, &j);
	check_valid_terminos(ar);
	check_form(ar);
	map = creat_map(j);
	map = put_in_map(map, creat_list(ar, j), 0, 0);
	
	while (map[a])
	{
		printf("%s\n", map[a]);
		a++;
	}
	
	return (0);
}
