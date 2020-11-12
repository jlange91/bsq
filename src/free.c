/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 04:04:41 by jlange            #+#    #+#             */
/*   Updated: 2020/11/12 04:04:46 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_mat(int **mat, int size)
{
	int i;

	i = 0;
	if (mat)
	{
		while (mat[i] && i < size)
		{
			free(mat[i]);
			++i;
		}
		free(mat);
	}
}

int		handle_free_return(void *tofree, int ret)
{
	free(tofree);
	return (ret);
}
