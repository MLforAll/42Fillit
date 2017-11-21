/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:01:59 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/21 23:17:51 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	del_piece(char **board, char letter)
{
	int		x;
	int		y;

	y = 0;
	while (board[y])
	{
		x = 0;
		while (board[y][x])
		{
			if (board[y][x] == letter)
				board[y][x] = '.';
			x++;
		}
		y++;
	}
}

static void	add_piece(char **piece, char **board, int board_sp, char letter)
{
	int		piece_sp;
	int		sy;
	int		sx;
	int		y;
	int		x;

	piece_sp = get_piece_start(piece);
	sy = piece_sp % 10;
	y = board_sp % 10;
	while (board[y])
	{
		sx = (piece_sp < 10) ? 0 : piece_sp / 10;
		x = (board_sp < 10) ? 0 : board_sp / 10;
		while (board[y][x])
		{
			if (piece[sy][sx] == '#')
				board[y][x] = letter;
			sx += (sx < 4);
			x++;
		}
		sy += (sy < 4);
		y++;
	}
}

static int	does_it_fit(char **piece, char **board, int x, int y)
{
	int		startpoint;
	int		sx;
	int		sy;
	int		bakx;
	int		hashtags;

	startpoint = get_piece_start(piece);
	sy = startpoint % 10;
	bakx = x;
	hashtags = 0;
	while (board[y])
	{
		sx = (startpoint < 10) ? 0 : startpoint / 10;
		x = bakx;
		while (board[y][x])
		{
			hashtags += (board[y][x] == '.' && piece[sy][sx] == '#');
			sx += (sx < 4);
			x++;
		}
		sy += (sy < 4);
		y++;
	}
	return ((hashtags >= 4));
}

int			malloc_board_size(char ***board, int bounds)
{
	char	**tmp;
	char	**newboard;
	int		i = 0;

	if (!(newboard = (char**)ft_memalloc(sizeof(char*) * (bounds + 1))))
		return (0);
	while (i < bounds)
	{
		if (!(newboard[i] = strnewc(bounds, '.')))
			return (0);
		i++;
	}
	newboard[i] = NULL;
	tmp = *board;
	*board = newboard;
	if (tmp)
		ft_tabfree(&tmp);
	return (1);
}

int			solve_fillit(char **piece, char ***board, int bounds, char letter)
{
	int		x;
	int		y;

	while (bounds < 15)
	{
		y = -1;
		while (++y < bounds)
		{
			x = -1;
			while (++x < bounds)
			{
				if (does_it_fit(piece, *board, x, y))
				{
					add_piece(piece, *board, x * 10 + y, letter);
					if (!*(piece + 5) || solve_fillit(piece + 5, board, bounds, letter + 1))
						return (1);
					del_piece(*board, letter);
				}
			}
		}
		if (letter > 'A' || !malloc_board_size(board, ++bounds))
			return (0);
	}
	return (0);
}
