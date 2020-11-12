/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 04:14:54 by jlange            #+#    #+#             */
/*   Updated: 2020/11/12 04:23:22 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static inline char	return_char(t_infomap *imap, t_case c)
{
	if (c.c == 0)
		return (imap->obstacle);
	else
	{
		if ((c.y >= imap->fy && c.y < imap->fy + imap->fsize)
			&& (c.x >= imap->fx && c.x < imap->fx + imap->fsize))
			return (imap->full);
		else
			return (imap->empty);
	}
}

static inline int	check_for_newline(t_case *c, int r_len, char *buf, int i)
{
	if (c->x >= r_len)
	{
		c->y++;
		c->x = 0;
		buf[i] = '\n';
		return (1);
	}
	return (0);
}

int					print_map(t_infomap *imap)
{
	char			*buf;
	unsigned long	i;
	unsigned long	max;
	t_case			c;

	i = 0;
	c = (t_case){0, 0, 0};
	max = imap->r_len * imap->c_len + imap->c_len;
	if (!(buf = (char*)malloc(sizeof(char) * (max + 1))))
		return (1);
	while (i < max)
	{
		c.c = imap->mat[c.y][c.x];
		buf[i] = return_char(imap, c);
		c.x++;
		++i;
		i += check_for_newline(&c, imap->r_len, buf, i);
	}
	write(1, buf, max);
	free(buf);
	return (0);
}
