/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:36:34 by kdumarai          #+#    #+#             */
/*   Updated: 2017/12/02 20:16:12 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	cnt_square_neighbours(char **allpieces, int x, int y)
{
	int		checks[4];

	checks[0] = (y > 0 && allpieces[y - 1][x] == '#');
	checks[1] = (allpieces[y + 1] && allpieces[y + 1][x] == '#');
	checks[2] = (x > 0 && allpieces[y][x - 1] == '#');
	checks[3] = (x < 3 && allpieces[y][x + 1] == '#');
	return (checks[0] + checks[1] + checks[2] + checks[3]);
}

static int	cnt_line_neighbours(char **allpieces, int y)
{
	int		x;
	int		ret;
	int		toadd;

	x = 0;
	ret = 0;
	while (allpieces[y][x])
	{
		if (allpieces[y][x] == '#')
		{
			toadd = cnt_square_neighbours(allpieces, x, y);
			if (!toadd)
				return (0);
			ret += toadd;
		}
		x++;
	}
	return (ret);
}

int			is_file_valid(char **allpieces)
{
	int		ret;
	int		y;
	int		line;
	int		hashtags;
	int		line_neighbours;

	ret = 0;
	y = -1;
	line = 0;
	hashtags = 0;
	line_neighbours = 0;
	while (allpieces[++y])
	{
		if ((line == 4 && (ft_strcmp(allpieces[y], "")
			|| line_neighbours <= 4 || line_neighbours > 12 || hashtags != 4))
		|| (line != 4 && (ft_strlen(allpieces[y]) != 4
			|| !strchrs(allpieces[y], "#."))))
			return (0);
		hashtags = (line == 4) ? 0 : hashtags + cnt_char(allpieces[y], '#');
		line_neighbours = (line == 4) ? 0 : line_neighbours
			+ cnt_line_neighbours(allpieces, y);
		ret += (line == 4);
		line = (line == 4) ? 0 : line + 1;
	}
	return ((line) ? 0 : ret);
}
