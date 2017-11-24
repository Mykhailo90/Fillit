/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funclib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarapii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:21:52 by msarapii          #+#    #+#             */
/*   Updated: 2017/11/24 10:59:16 by msarapii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCLIB_H
# define FUNCLIB_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

size_t			count_tetriminos(char const *s);
void			check_valid_terminos(char **ar);
void			ft_putchar(char c);
void			*ft_memalloc(size_t size);
void			ft_bzero(void *s, size_t n);
void			ft_putstr(char const *s);
char			*read_list(char **argv, char *buffer);
void			*ft_memalloc(size_t size);
char			**ft_strsplit(char const *s);
void			check_type_symbols(char const *s);
char			*ft_strncpy(char *dest, const char *src, size_t n);
#endif
