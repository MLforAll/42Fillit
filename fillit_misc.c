/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_misc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:34:02 by kdumarai          #+#    #+#             */
/*   Updated: 2017/12/02 15:41:22 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int		get_piece_start(char **allpieces)
{
	int		x;
	int		y;
	int		startx;
	int		starty;

	starty = -1;
	startx = -1;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (allpieces[y][x] == '#')
			{
				if (x < startx || startx == -1)
					startx = x;
				if (starty == -1)
					starty = y;
			}
			x++;
		}
		y++;
	}
	return (startx * 10 + starty);
}

int		str_haschars(const char *str, const char *chars)
{
	int		fails;
	int		ci;

	while (*str)
	{
		fails = 0;
		ci = 0;
		while (chars[ci])
		{
			if (*str != chars[ci])
				fails++;
			ci++;
		}
		if (fails == 2)
			return (0);
		str++;
	}
	return (1);
}

int		get_min_size(int n_pieces)
{
	int		bounds;
	int		i;

	bounds = 2;
	i = 1;
	while (i++ < n_pieces)
		bounds += (i % 4 == 0);
	return (bounds);
}

char	*strnewc(int size, char c)
{
	int		i;
	char	*ret;

	i = 0;
	if (!(ret = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
		ret[i++] = c;
	ret[i] = '\0';
	return (ret);
}
