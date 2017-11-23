/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:18:57 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/23 15:21:23 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"

size_t	count_tetriminos(char const *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s == '\n')
			s++;
		while (*s != '\n')
			s++;
		if (*(s + 1) == '\n' || *(s + 1) == '\0')
			i++;
		if (*(s + 1) == '\0')
			return (i);
	}
	return (i);
}