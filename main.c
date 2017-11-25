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

	t_list *l;
	
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
	l = creat_list(ar, j);
	map = creat_map(j);	

	l = l->next;
	printf("%d", l->x[0]);
	printf("%d", l->x[1]);
	printf("%d", l->x[2]);
	printf("%d\n", l->x[3]);
	printf("%d", l->y[0]);
	printf("%d", l->y[1]);
	printf("%d", l->y[2]);
	printf("%d", l->y[3]);
	return (0);
}
