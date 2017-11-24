/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:02:09 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/24 20:56:46 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"

static int		check_part2(char *s)
{
	if (*(s + 1) == '#' && *(s + 2) == '#' && *(s + 3) == '#')
		return (1);
	else if (*(s + 5) == '#' && *(s + 10) == '#' && *(s + 15) == '#')
		return (1);
	else if (*(s + 1) == '#' && *(s + 4) == '#' && *(s + 5) == '#')
		return (1);
	else if (*(s + 1) == '#' && *(s + 6) == '#' && *(s + 7) == '#')
		return (1);
	else if (*(s + 5) == '#' && *(s + 6) == '#' && *(s + 11) == '#')
		return (1);
	else if (*(s + 4) == '#' && *(s + 5) == '#' && *(s + 9) == '#')
		return (1);
	else if (*(s + 1) == '#' && *(s + 5) == '#' && *(s + 6) == '#')
		return (1);
	else if (*(s + 1) == '#' && *(s + 5) == '#' && *(s + 10) == '#')
		return (1);
	else if (*(s + 5) == '#' && *(s + 10) == '#' && *(s + 11) == '#')
		return (1);
	else if (*(s + 5) == '#' && *(s + 9) == '#' && *(s + 10) == '#')
		return (1);
	return (0);
}

static int		check_part1(char *s)
{
	if (*(s + 3) == '#' && *(s + 4) == '#' && *(s + 5) == '#')
		return (1);
	else if (*(s + 5) == '#' && *(s + 6) == '#' && *(s + 7) == '#')
		return (1);
	else if (*(s + 1) == '#' && *(s + 2) == '#' && *(s + 5) == '#')
		return (1);
	else if (*(s + 1) == '#' && *(s + 2) == '#' && *(s + 7) == '#')
		return (1);
	else if (*(s + 4) == '#' && *(s + 5) == '#' && *(s + 6) == '#')
		return (1);
	else if (*(s + 5) == '#' && *(s + 6) == '#' && *(s + 10) == '#')
		return (1);
	else if (*(s + 1) == '#' && *(s + 2) == '#' && *(s + 6) == '#')
		return (1);
	else if (*(s + 4) == '#' && *(s + 5) == '#' && *(s + 10) == '#')
		return (1);
	else if (*(s + 1) == '#' && *(s + 6) == '#' && *(s + 11) == '#')
		return (1);
	return (check_part2(s));
}

void			check_form(char **ar)
{
	int			j;
	int			i;
	int			temp;

	j = 0;
	temp = 0;
	while (ar[j])
	{
		i = 0;
		while (ar[j][i] != '#')
			i++;
		temp = check_part1(&ar[j][i]);
		j++;
		if (!temp)
		{
			ft_putstr("error\n");
			exit(1);
		}
	}
}
