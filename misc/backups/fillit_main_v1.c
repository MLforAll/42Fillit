/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:36:34 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/13 20:17:57 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int		has_piece_neighbour(char **allpieces, int x, int y)
{
	int		checks[4];

	checks[0] = (y > 0 && allpieces[y - 1][x] == '#');
	checks[1] = (y < 3 && allpieces[y + 1][x] == '#');
	checks[2] = (x > 0 && allpieces[y][x - 1] == '#');
	checks[3] = (x < 3 && allpieces[y][x + 1] == '#');
	return ((checks[0] || checks[1] || checks[2] || checks[3]));
}

int		is_piece_valid(char **allpieces)
{
	int		x;
	int		y;
	int		hashtags;

	hashtags = 0;
	y = 0;
	while (allpieces[y])
	{
		x = 0;
		while (allpieces[y][x])
		{
			if (!has_piece_neighbour(allpieces, x, y) && allpieces[y][x] == '#')
				return (0);
			hashtags += (allpieces[y][x] == '#');
			x++;
		}
		y++;
	}
	return ((hashtags == 4));
}

int		count_pieces(char *piecesstr)
{
	int		ret;
	int		lines;
	int		i;
	int		z;

	ret = 0;
	lines = 0;
	i = 0;
	z = 4;
	while (piecesstr[i])
	{
		if (piecesstr[i] != '#' && piecesstr[i] != '.' && piecesstr[i] != '\n')
			return (0);
		if (piecesstr[i] == '\n')
		{
			if (lines % 3 == 0 && lines > 0)
			{
				ret++;
				lines = 0;
				z += 5;
			}
			else
			{
			if (i != z)
				return (0);
			else
				z += 5;
			lines++;
			}
		}
		i++;
	}
	return (ret);
}

int		main(int ac, char **av)
{
	char	*filecont;
	int		fd;

	if (ac < 2)
		return (ft_returnmsg("usage: fillit /path/to/file", 2, 1));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_returnmsg("Couldn't open the file!", 2, 1));
	filecont = ft_readfd(fd, 32);
	//printf("is piece valid = %i\n", is_piece_valid(ft_strsplit(filecont, '\n')));
	printf("pieces = %i\n", count_pieces(filecont));
	ft_strdel(&filecont);
	if (close(fd) == -1)
		return (ft_returnmsg("Couldn't close the file!", 2, 1));
	return (0);
}
