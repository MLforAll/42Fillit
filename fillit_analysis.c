/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:36:34 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/18 00:38:31 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		has_piece_neighbour(char **allpieces, int x, int y)
{
	int		checks[4];

	checks[0] = (y > 0 && allpieces[y - 1][x] == '#');
	checks[1] = (allpieces[y] && allpieces[y + 1][x] == '#');
	checks[2] = (x > 0 && allpieces[y][x - 1] == '#');
	checks[3] = (x < 3 && allpieces[y][x + 1] == '#');
	//printf("x = %i; y = %i | check0 = %i | check1 = %i | check2 = %i | check3 = %i\n", x, y, checks[0], checks[1], checks[2], checks[3]);
	return (checks[0] + checks[1] + checks[2] + checks[3]);
}

static size_t	count_hashtag_with_neighbour(char **allpieces, int y)
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
			toadd = has_piece_neighbour(allpieces, x, y);
			if (!toadd)
				return (0);
			ret += toadd;
		}
		x++;
	}
	return (ret);
}

static	int		str_haschars(const char *str, const char *chars)
{
	size_t	fails;
	size_t	ci;

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

size_t			count_pieces(char **allpieces)
{
	unsigned int	y;
	size_t			ret;
	int				lines;
	int				hashtags;

	y = 0;
	ret = 0;
	lines = 0;
	hashtags = 0;
	while (allpieces[y])
	{
		//printf("ap[y] = %s | hashtags = %i\n", allpieces[y], hashtags);
		if (lines == 4 && (ft_strcmp(allpieces[y], "") || hashtags <= 4 || hashtags > 12))
			return (0);
		else if (lines != 4 && (ft_strlen(allpieces[y]) != 4
					|| !str_haschars(allpieces[y], "#.")))
			return (0);
		hashtags = (lines == 4) ? 0 : hashtags
			+ count_hashtag_with_neighbour(allpieces, y);
		ret += (lines == 4);
		lines = (lines == 4) ? 0 : lines + 1;
		y++;
	}
	return (ret);
}
