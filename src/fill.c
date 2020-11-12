/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 04:02:49 by jlange            #+#    #+#             */
/*   Updated: 2020/11/12 12:49:16 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static inline int	get_lower_case(int **mat, int y, int x)
{
	int a;
	int b;
	int c;

	a = mat[y - 1][x - 1];
	b = mat[y - 1][x];
	c = mat[y][x - 1];
	a = (b < a) ? b : a;
	a = (c < a) ? c : a;
	return (a);
}

static inline void	fill_case(t_infomap *imap, int y, int x, char *line)
{
	if (y == 0 || x == 0)
		imap->mat[y][x] = (line[x] == imap->empty) ? 1 : 0;
	else
	{
		if (line[x] == imap->obstacle)
			imap->mat[y][x] = 0;
		else
			imap->mat[y][x] = get_lower_case(imap->mat, y, x) + 1;
	}
	if (imap->mat[y][x] > imap->fsize)
	{
		imap->fsize = imap->mat[y][x];
		imap->fx = x - (imap->fsize - 1);
		imap->fy = y - (imap->fsize - 1);
	}
}

int					fill_check_line(t_infomap *imap, char *line, int l_index)
{
	int		i;
	int		malloc_size;

	i = -1;
	malloc_size = (l_index) ? imap->r_len : ft_strlen(line) - 1;
	if (l_index >= imap->c_len
	|| !(imap->mat[l_index] = (int*)malloc(sizeof(int) * (malloc_size))))
		return (handle_free_return(line, 1));
	while (line[++i] && line[i] != '\n')
	{
		if (line[i] != imap->empty && line[i] != imap->obstacle)
			return (handle_free_return(line, 1));
		fill_case(imap, l_index, i, line);
	}
	imap->r_len = (!l_index) ? i : imap->r_len;
	return (i && i == imap->r_len) ? (handle_free_return(line, 0))
	: (handle_free_return(line, 1));
}

int					fill_check_mat(t_infomap *imap, int fd)
{
	char	*f_line;
	char	c;
	int		i;

	i = 0;
	if (!(imap->mat = (int**)malloc(sizeof(int*) * (imap->c_len))))
		return (1);
	ft_memset(imap->mat, 0, sizeof(int*) * (imap->c_len));
	f_line = concat_char(NULL, 0);
	while (read(fd, &c, 1) && c != '\n')
		f_line = concat_char(f_line, c);
	if (fill_check_line(imap, f_line, i)
	|| !(f_line = (char*)malloc(sizeof(char) * (imap->r_len + 1))))
		return (1);
	++i;
	while (read(fd, f_line, imap->r_len + 1) > 0)
	{
		f_line[imap->r_len] = 0;
		if (fill_check_line(imap, f_line, i)
		|| !(f_line = (char*)malloc(sizeof(char) * (imap->r_len + 1))))
			return (1);
		++i;
	}
	free(f_line);
	return (!(imap->c_len == i));
}

int					fill_check_info_map(t_infomap *imap, char *f_line)
{
	int i;

	if ((i = ft_strlen(f_line)) < MIN_SIZE_FIRST_LINE)
		return (1);
	imap->full = f_line[i - 1];
	imap->obstacle = f_line[i - 2];
	imap->empty = f_line[i - 3];
	if (imap->empty == imap->obstacle
		|| imap->empty == imap->full
		|| imap->obstacle == imap->full)
		return (1);
	f_line[i - 3] = 0;
	i = 0;
	while (f_line[i])
	{
		if (!is_numeric(f_line[i]))
			return (1);
		++i;
	}
	imap->c_len = ft_atoi(f_line);
	return (0);
}
