/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:52:44 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/23 13:53:06 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*res;

	res = dest;
	while (n && (*dest++ = *src++))
		n--;
	if (n)
	{
		while (--n)
			*dest++ = '\0';
	}
	return (res);
}
