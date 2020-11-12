/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 04:05:50 by jlange            #+#    #+#             */
/*   Updated: 2020/11/12 04:06:05 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_strlen(char *str)
{
	char *begin;

	begin = str;
	while (*str)
		str++;
	return (str - begin);
}

char	*concat_char(char *str, char c)
{
	char	*ret;
	int		i;

	if (!str)
	{
		if (!(ret = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		*ret = 0;
		return (ret);
	}
	if (!(ret = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	i = -1;
	while (str[++i])
		ret[i] = str[i];
	ret[i] = c;
	ret[i + 1] = 0;
	free(str);
	return (ret);
}

int		ft_atoi(char *str)
{
	int		is_negative;
	int		value;

	is_negative = 0;
	value = 0;
	while (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		is_negative = 1;
		str++;
	}
	while ((*str <= '9') && (*str >= '0'))
	{
		value = (value * 10) - (*str - '0');
		str++;
	}
	if (!is_negative)
		value = -value;
	return (value);
}

int		is_numeric(char c)
{
	return (c >= 48 && c <= 57);
}

void	*ft_memset(void *dest, int val, unsigned int len)
{
	unsigned char *ptr;

	ptr = dest;
	while (len-- > 0)
		*ptr++ = val;
	return (dest);
}
