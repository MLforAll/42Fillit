/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_misc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:34:02 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/18 18:10:41 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
