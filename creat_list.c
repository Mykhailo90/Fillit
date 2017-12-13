/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:05:46 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/25 18:05:49 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "funclib.h"

static void		input_list_x(char *ar, t_list *list)
{
	size_t		n;
	size_t		i;

	n = 0;
	i = 0;

	while (ar[i] != '\0')
	{
		
		if (ar[i] == '#' && i < 5)
			list->x[n++] = i;
		else if (ar[i] == '#' && i < 10)
			list->x[n++] = i - 5;
		else if (ar[i] == '#' && i < 15)
			list->x[n++] = i - 10;
		else if (ar[i] == '#' && i < 20)
			list->x[n++] = i - 15;
		i++;;
	}
}

static void		input_list_y(char *ar, t_list *list)
{
	size_t		n;
	size_t		i;

	n = 0;
	i = 0;
	while (ar[i] != '\0')
	{
		if (ar[i] == '#' && i < 5)
			list->y[n++] = 0;
		else if (ar[i] == '#' && i < 10)
			list->y[n++] = 1;
		else if (ar[i] == '#' && i < 15)
			list->y[n++] = 2;
		else if (ar[i] == '#' && i < 20)
			list->y[n++] = 3;
		i++;
	}
}

static void		inputs(char **ar, t_list *list, size_t j)
{
	size_t		k;
	
	k = 0;
	list->prev = NULL;	
	while (ar[k])
	{
		input_list_x(ar[k], list);
		input_list_y(ar[k], list);
		list->ch = 'A' + k;
		if (j == 1)
			list->next = NULL;
		else if (j-- > 1)
		{
			list->next = ft_memalloc(sizeof(t_list));
			list->next->prev = list;
			list = list->next;			
		}
		k++;
	}
}

t_list			*creat_list(char **ar, size_t j)
{
	t_list		*list;
	t_list		*stlist;

	list = NULL;
	if (!(list = ft_memalloc(sizeof(t_list))))
		return (NULL);
	stlist = list;
	inputs(ar, list, j);
	return (stlist);
}
