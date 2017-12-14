/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:32:42 by msarapii          #+#    #+#             */
/*   Updated: 2017/12/14 12:24:29 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"

static void		check_str(const char *s)
{
	size_t		i;
	size_t		n;

	i = 0;
	n = count_tetriminos(s);
	while (*s++)
		i++;
	if (i / n != 20)
	{
		ft_putstr("error\n");
		exit(1);
	}
}

char			**ft_strsplit(char const *s, int *j)
{
	char		**arr_ptr;
	int			i;
	int			k;

	if (!s)
		return (NULL);
	check_type_symbols(s);
	check_str(s);
	*j = count_tetriminos(s);
	k = *j;
	i = 0;
	if (!(arr_ptr = (char **)ft_memalloc(sizeof(s) * k + 1)))
		return (NULL);
	while (k--)
	{
		if (!(arr_ptr[i] = ft_memalloc(sizeof(s) * 20)))
			return (NULL);
		while (*s == '\n')
			s++;
		ft_strncpy(arr_ptr[i], s, 20);
		s = s + 20;
		i++;
	}
	arr_ptr[i] = 0;
	return (arr_ptr);
}
