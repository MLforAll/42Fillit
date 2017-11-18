/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:01:59 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/18 22:45:00 by kdumarai         ###   ########.fr       */
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

static void	add_piece(char **piece, char **board, int pos[2], char letter)
{
	int		startpoint;
	int		sx;
	int		sy;
	int		bakx;

	startpoint = get_piece_start(piece);
	sy = startpoint % 10;
	bakx = pos[0];
	while (board[pos[1]])
	{
		sx = (startpoint < 10) ? 0 : startpoint / 10;
		pos[0] = bakx;
		while (board[pos[1]][pos[0]])
		{
			if (piece[sy][sx] == '#')
				board[pos[1]][pos[0]] = letter;
			sx += (sx < 4);
			pos[0]++;
		}
		sy += (sy < 4);
		pos[1]++;
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

static int			remalloc_board(char ***board, int bounds)
{
	char	**tmp;
	char	*strtmp;
	char	**newrow;
	int		i;

	i = 0;
	if (!(newrow = (char**)ft_memalloc(sizeof(char*) * 2)))
		return (0);
	if (!(newrow[0] = ft_strnew(bounds)))
		return (0);
	while (i < bounds)
		newrow[0][i++] = '.';
	tmp = *board;
	*board = ft_tabcat((const char**)tmp, (const char**)newrow);
	ft_tabfree(&tmp);
	ft_tabfree(&newrow);
	i = 0;
	while (i < bounds - 1)
	{
		strtmp = (*board)[i];
		(*board)[i] = ft_strjoin((*board)[i], ".");
		ft_strdel(&strtmp);
		i++;
	}
	return (1);
}

int		solve_fillit(char **piece, char ***board, int bounds, char letter)
{
	int		x;
	int		y;
	int		pos[2];

	if (!*piece)
		return (1);
	while (bounds < 104)
	{
		y = -1;
		while (++y < bounds)
		{
			x = -1;
			while (++x < bounds)
			{
				if (does_it_fit(piece, *board, x, y))
				{
					pos[0] = x;
					pos[1] = y;
					add_piece(piece, *board, pos, letter);
					if (solve_fillit(piece + 5, board, bounds, letter + 1))
						return (1);
					del_piece(*board, letter);
				}
			}
		}
		if (letter > 'A')
			return (0);
		if (!remalloc_board(board, ++bounds))
			break ;
	}
	return (0);
}
