/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:13:11 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/23 11:18:24 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"

void	*ft_memalloc(size_t size)
{
	void	*p;

	if (!size)
		return (NULL);
	if (!(p = malloc(size)))
		return (NULL);
	bzero(p, size);
	return (p);
}
