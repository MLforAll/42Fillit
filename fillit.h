/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:29:51 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/18 19:04:59 by kdumarai         ###   ########.fr       */
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
char	**solve_fillit(char **piece, char **board, int bounds, char letter);

/* misc */
int		get_piece_start(char **allpieces);
int		str_haschars(const char *str, const char *chars);

#endif
