/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funclib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:21:52 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/24 20:54:53 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCLIB_H
# define FUNCLIB_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

#include <stdio.h>

typedef struct		s_list
{
	char			ch;
	int				x[4];
	int				y[4];
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

size_t				count_tetriminos(char const *s);
void				check_valid_terminos(char **ar);
void				ft_putchar(char c);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				ft_putstr(char const *s);
char				*read_list(char **argv, char *buffer);
void				*ft_memalloc(size_t size);
char				**ft_strsplit(char const *s, size_t *j);
void				check_type_symbols(char const *s);
char				*ft_strncpy(char *dest, const char *src, size_t n);
void				check_form(char **ar);
char				**creat_map(size_t j);
void				*ft_memset(void *s, int c, size_t n);
t_list				*creat_list(char **ar, size_t j);
char				**put_in_map(char **map, t_list *l, int x, int y);
#endif
