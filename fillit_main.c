/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:36:34 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/14 16:07:52 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

static int		run_fillit(int fd)
{
	char	*fcontent;
	char	**fsplitted;
	size_t	cpieces;

	fcontent = ft_readfd(fd, 32);
	fsplitted = ft_strsplitline(fcontent);
	ft_strdel(&fcontent);
	cpieces = count_pieces(fsplitted);
	if (!cpieces)
		return (0);
	printf("pieces = %li\n", cpieces);
	return (1);
}

int				main(int ac, char **av)
{
	int		fd;

	if (ac < 2)
		return (ft_returnmsg("usage: fillit /path/to/file", 2, 1));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_returnmsg("fillit: No such file or directory!", 2, 1));
	if (!run_fillit(fd))
		return (ft_returnmsg("error", 2, 1));
	if (close(fd) == -1)
		return (ft_returnmsg("fillit: Couldn't close the file!", 2, 1));
	return (0);
}
