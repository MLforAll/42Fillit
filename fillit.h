/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:29:51 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/20 13:20:58 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/* headers */
# include <stdio.h>
# include "Libft/libft.h"

/* analyze */
int		is_file_valid(char **allpieces);

/* solver */
int		malloc_board_size(char ***board, int bounds);
int		solve_fillit(char **piece, char ***board, int bounds, char letter);

/* misc */
int		get_piece_start(char **allpieces);
int		str_haschars(const char *str, const char *chars);
int		get_min_size(int n_pieces);
char	*strnewc(int size, char c);

#endif
