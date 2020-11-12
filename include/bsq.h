/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 04:35:20 by jlange            #+#    #+#             */
/*   Updated: 2020/11/12 19:22:46 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define MIN_SIZE_FIRST_LINE 4

typedef struct	s_infomap
{
	char	empty;
	char	obstacle;
	char	full;
	int		r_len;
	int		c_len;
	int		**mat;
	int		fx;
	int		fy;
	int		fsize;
}				t_infomap;

typedef struct	s_case
{
	int		c;
	int		x;
	int		y;
}				t_case;

int				ft_strlen(char *str);
char			*concat_char(char *str, char c);
int				ft_atoi(char *str);
int				is_numeric(char c);
void			free_mat(int **map, int size);
void			*ft_memset(void *dest, int val, unsigned int len);
int				handle_free_return(void *tofree, int ret);
int				print_map(t_infomap *imap);
int				fill_check_mat(t_infomap *imap, int fd);
int				fill_check_info_map(t_infomap *imap, char *f_line);

#endif
