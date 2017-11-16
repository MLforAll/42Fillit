/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:29:51 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/16 21:48:41 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>

# include "Libft/libft.h"

size_t	count_pieces(char **allpieces);
char	**solve_fillit(char **piece, char **board, int bounds);
int		does_it_fit(char **piece, char **board, int x, int y);

#endif
