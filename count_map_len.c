/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:57:30 by msarapii          #+#    #+#             */
/*   Updated: 2017/12/14 12:08:29 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_map_len(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}