/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:01:59 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/18 16:59:22 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del_piece(char **board, char letter)
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

void	add_piece(char **piece, char **board, int pos[2], char letter)
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

int		does_it_fit(char **piece, char **board, int pos[2], int bounds)
{
	int		startpoint;
	int		sx;
	int		sy;
	int		bakx;
	int		hashtags;

	hashtags = 0;
	startpoint = get_piece_start(piece);
	sy = startpoint % 10;
	bakx = pos[0];
	while (pos[1] < bounds)
	{
		sx = (startpoint < 10) ? 0 : startpoint / 10;
		pos[0] = bakx;
		while (pos[0] < bounds)
		{
			if (board[pos[1]][pos[0]] != '.' && piece[sy][sx] == '#')
				return (0);
			if (piece[sy][sx] == '#')
				hashtags++;
			sx += (sx < 4);
			pos[0]++;
		}
		sy += (sy < 4);
		pos[1]++;
	}
	return ((hashtags >= 4));
}

int		remalloc_board(char ***board, int bounds)
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

char	**solve_fillit(char **piece, char **board, int bounds, char letter)
{
	int		x;
	int		y;
	int		pos[2];

	if (!*piece)
		return (board);
	while (bounds < 104) /* Space to fit 26 pieces (not sort) */
	{
		y = -1;
		while (++y < bounds)
		{
			x = -1;
			while (++x < bounds)
			{
				pos[0] = x;
				pos[1] = y;
				//printf("\ncheck!  (x = %i; y = %i)\n", x, y);
				if (does_it_fit(piece, board, pos, bounds))
				{
					pos[0] = x;
					pos[1] = y;
					//printf("fits!   (x = %i; y = %i)\n", x, y);
					add_piece(piece, board, pos, letter);
					//printf("added!  (x = %i; y = %i)\n\n", x, y);
					//ft_puttab(board, NULL);
					if (solve_fillit(piece + 5, board, bounds, letter + 1)) /* 4 elems per piece + 1 blank (\n) */
						return (board);
					//printf("\ndelete! (x = %i; y = %i; letter = %c)\n", x, y, letter);
					del_piece(board, letter);
					//printf("del ok! (x = %i; y = %i; letter = %c)\n", x, y, letter);
					//ft_puttab(board, NULL);
				}
			}
		}
		if (letter > 'A')
			return (NULL);
		/* Remalloc */
		//printf("=== REMALLOC ===\n");
		bounds++;
		if (!remalloc_board(&board, bounds))
			break ;
		//ft_puttab(board, NULL);
	}
	return (NULL);
}
