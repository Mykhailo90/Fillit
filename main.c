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

int	main(int arg, char **argv)
{
	int		fd;
	size_t	block;
	char buffer [21 * 26];

	block = sizeof(char) * 21;
	
	if (arg != 2)
	{
		ft_putstr("Usage: You must take only one parametr!\n");
		exit(1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	while ((block = read(fd, buffer, (sizeof(char) * 21)) > 0)
		   
	close(fd);
	return (0);
}
