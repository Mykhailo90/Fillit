/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funclib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:21:52 by msarapii          #+#    #+#             */
/*   Updated: 2017/12/14 12:25:39 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCLIB_H
# define FUNCLIB_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_list
{
	char			ch;
	int				x[4];
	int				y[4];
	struct s_list	*next;
}					t_list;

typedef struct		s_xy
{
	int				x;
	int				y;
}					t_xy;

char				**delete_tetrimoino(char **map, char ch);
void				set_termino(char **map, t_list *l, int i, int n);
int					check_set_termino(char **map, t_list *l, int i, int n);
size_t				count_tetriminos(char const *s);
int					count_map_len(char **map);
void				check_valid_terminos(char **ar);
void				ft_putchar(char c);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				ft_putstr(char const *s);
char				*read_list(char **argv, char *buffer);
void				*ft_memalloc(size_t size);
char				**ft_strsplit(char const *s, int *j);
void				check_type_symbols(char const *s);
char				*ft_strncpy(char *dest, const char *src, size_t n);
void				check_form(char **ar);
char				**creat_map(int j);
void				*make_point(void *s, int c, size_t n);
t_list				*creat_list(char **ar, size_t j);
int					func_rec(char **map, t_list *l, int size);
char				**put_in_map(int size, t_list *l);
#endif
