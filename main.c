/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:59:21 by msarapii          #+#    #+#             */
/*   Updated: 2017/12/14 12:29:10 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"
#include <stdio.h>

int	main(int arg, char **argv)
{
	char	**ar;
	char	**map;
	int		j;
	size_t	a;

	a = 0;
	if (arg != 2)
	{
		ft_putstr("Usage: You must take only one parametr!\n");
		exit(1);
	}
	ar = ft_strsplit(read_list(argv, (char *)ft_memalloc(550)), &j);
	check_valid_terminos(ar);
	check_form(ar);
	map = put_in_map(j, creat_list(ar, j));
	while (map[a])
	{
		ft_putstr(map[a]);
		ft_putstr("\n");
		a++;
	}
	return (0);
}
