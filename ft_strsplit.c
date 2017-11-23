
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:32:42 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/23 15:21:43 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"

char			**ft_strsplit(char const *s)
{
	char		**arr_ptr;
	size_t		i;
	size_t		j;

	if (!s)
		return (NULL);
	check_type_symbols(s);
	
	j = count_tetriminos(s);
	i = 0;
	arr_ptr = NULL;
	if (!(arr_ptr = (char **)ft_memalloc(sizeof(s) * j + 1)))
		return (NULL);
	while (j--)
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
