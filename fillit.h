/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:29:51 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/20 14:29:06 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "Libft/libft.h"

int		is_file_valid(char **allpieces);

int		malloc_board_size(char ***board, int bounds);
int		solve_fillit(char **piece, char ***board, int bounds, char letter);

int		get_piece_start(char **allpieces);
int		str_haschars(const char *str, const char *chars);
int		get_min_size(int n_pieces);
char	*strnewc(int size, char c);

#endif
