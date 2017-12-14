/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:52:07 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/23 11:04:40 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"

char	*read_list(char **argv, char *buffer)
{
	int		fd;
	size_t	block;
	size_t	len;

	len = 550;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("error\n");
		exit(1);
	}
	block = read(fd, buffer, len);
	if (block < 20 || block > 545)
	{
		ft_putstr("error\n");
		exit(1);
	}
	close(fd);
	return (buffer);
}
