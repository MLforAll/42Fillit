/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:36:34 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/18 00:50:44 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

static int		run_fillit(int fd)
{
	char	*file_content;
	char	**allpieces;
	char	**board;
	size_t	cntpieces;

	file_content = ft_readfd(fd, 32);
	allpieces = ft_strsplitline(file_content);
	ft_strdel(&file_content);
	cntpieces = count_pieces(allpieces);
	if (!cntpieces)
		return (0);
	//printf("file valid with cnt = %li\n", cntpieces);

	/*char *test[4] = {".##.", "##..", "....", "...."};
	int i = 0, p = 0;
	while (p < 4)
	{
		printf("does it fit at (%i, %i)? %s\n", i, p, does_it_fit(allpieces, test, i, p) == 1 ? "\033[32mtrue\033[39m" : "\033[31mfalse\033[39m");
		p += (i == 3);
		i = (i == 3) ? 0 : i + 1;
	}*/

	//printf("Solving puzzle... Please wait till year 3000 :D\n");
	board = ft_strsplit("....|....|....|....", '|');
	board = solve_fillit(allpieces, board, 4, 'A');
	//printf("\nDone! Printing now...\n\n");
	if (!board)
		return(0);
	ft_puttab(board, NULL);
	ft_tabfree(&board);
	return (1);
}

int				main(int ac, char **av)
{
	int		fd;

	if (ac < 2)
		return (ft_returnmsg("usage: fillit /path/to/file", 1, 0));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_returnmsg("fillit: No such file or directory!", 1, 1));
	if (!run_fillit(fd))
		return (ft_returnmsg("error", 1, 1));
	if (close(fd) == -1)
		return (ft_returnmsg("fillit: Couldn't close the file!", 1, 1));
	return (0);
}
