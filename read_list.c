/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:52:07 by msarapii          #+#    #+#             */
/*   Updated: 2017/12/14 22:47:02 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"

static void	check_v(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n' && str[i + 2] == '\n')
		{
			ft_putstr("error\n");
			exit(1);
		}
		i++;
	}
}

char		*read_list(char **argv, char *buffer)
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
	check_v(buffer);
	return (buffer);
}
