/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:36:34 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/18 22:45:06 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

static int		fillit_usage(char *prgm_name, char *target_file_msg, int retval)
{
	ft_putstr("usage: ");
	ft_putstr(prgm_name);
	ft_putstr(" ");
	ft_putendl(target_file_msg);
	return (retval);
}

static int		fillit_err(char *prgm_name, char *msg, int fd, int retval)
{
	if (prgm_name)
	{
		ft_putstr_fd(prgm_name, fd);
		ft_putstr_fd(": ", fd);
	}
	ft_putendl_fd(msg, fd);
	return (retval);
}

static int		fillit_solve(int fd)
{
	char	*file_content;
	char	**allpieces;
	char	**board;

	file_content = ft_readfd(fd, 32);
	allpieces = ft_strsplitline(file_content);
	ft_strdel(&file_content);
	if (!is_file_valid(allpieces))
		return (0);
	board = ft_strsplit("..|..", '|');
	if (!solve_fillit(allpieces, &board, 2, 'A'))
		return (0);
	ft_puttab(board, NULL);
	ft_tabfree(&board);
	ft_tabfree(&allpieces);
	return (1);
}

int				main(int ac, char **av)
{
	int		fd;
	char	*prgm_name;

	prgm_name = "./fillit";
	if (ac < 2)
		return (fillit_usage(prgm_name, "target_file", 0));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (fillit_err(prgm_name, "No such file or directory!", 1, 1));
	if (!fillit_solve(fd))
		return (fillit_err(NULL, "error", 1, 1));
	if (close(fd) == -1)
		return (fillit_err(prgm_name, "Couldn't close the file!", 1, 1));
	return (0);
}
