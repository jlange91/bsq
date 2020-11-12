/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:17:24 by jlange            #+#    #+#             */
/*   Updated: 2020/11/12 04:33:49 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		read_map(t_infomap *imap, int fd)
{
	char	*f_line;
	char	c;
	int		ret;

	ret = 0;
	f_line = concat_char(NULL, 0);
	while (read(fd, &c, 1) > 0 && c != '\n')
		f_line = concat_char(f_line, c);
	if (!(ret = fill_check_info_map(imap, f_line)))
		ret = fill_check_mat(imap, fd);
	if (f_line)
		free(f_line);
	return (ret);
}

int		open_map(t_infomap *imap, char *filename)
{
	int		fd;
	int		ret;

	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		ret = read_map(imap, fd);
		close(fd);
		return (ret);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_infomap	imap;
	int			i;

	i = 0;
	while (av[++i])
	{
		imap = (t_infomap){0, 0, 0, 0, 0, NULL, 0, 0, 0};
		if (open_map(&imap, av[i]) || print_map(&imap))
			write(1, "map error\n", 10);
		free_mat(imap.mat, imap.c_len);
	}
	if (ac == 1)
	{
		if (read_map(&imap, 0))
		{
			write(1, "map error\n", 10);
			return (0);
		}
		print_map(&imap);
		free_mat(imap.mat, imap.c_len);
	}
	return (0);
}
