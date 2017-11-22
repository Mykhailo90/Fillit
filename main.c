/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:59:21 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/22 19:04:16 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"
#include <stdio.h>

char *read_list(char **argv, char *buffer)
{
	int		fd;
	size_t	block;
	size_t	len;
	
	len = 550;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	block = read(fd, buffer, len);
	if (block < 20 || block > 545)
	{
		ft_putstr("error\n");
		exit(1);	
	}
	close(fd);
	return (buffer);
}

int	main(int arg, char **argv)
{	
	char buffer [550];
	char	*list_buf;

	//Заполнить буфер символами конца строки для эстетики. 
	if (arg != 2)
	{
		ft_putstr("Usage: You must take only one parametr!\n");
		exit(1);
	}
	list_buf = read_list(argv, buffer);
	printf("%s\n", list_buf + 525);
	return (0);
}
