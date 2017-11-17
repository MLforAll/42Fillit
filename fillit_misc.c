/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_misc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:34:02 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/17 18:36:32 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_piece_start(char **allpieces)
{
	int		x;
	int		y;
	int		startx;
	int		starty;

	starty = -1;
	startx = -1;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (allpieces[y][x] == '#')
			{
				if (x < startx || startx == -1)
					startx = x;
				if (starty == -1)
					starty = y;
			}
			x++;
		}
		y++;
	}
	return (startx * 10 + starty);
}