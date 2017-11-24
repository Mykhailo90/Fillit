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
	char	*buffer;
	char	*list_buf;

	if (arg != 2)
	{
		ft_putstr("Usage: You must take only one parametr!\n");
		exit(1);
	}
	buffer = (char *)ft_memalloc(550);
	list_buf = read_list(argv, buffer);
	ar = ft_strsplit(list_buf);
	check_valid_terminos(ar);
	check_form(ar);
	return (0);
}
