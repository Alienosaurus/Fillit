/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:48:34 by adenece           #+#    #+#             */
/*   Updated: 2016/03/31 17:06:53 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_usage(void)
{
	ft_putstr_fd("usage: fillit missing input file :'( xoxo \n", 1);
	exit(0);
}

int			loop(int fd)
{
	t_tetriminos_array	*ta;
	int					edge;
	char				**map;

	ta = ft_read_all(fd);
	edge = 2;
	while (1)
	{
		map = ft_map(edge);
		if (solve(ta, 0, map, edge))
		{
			print_map(map, edge);
				return (0);
		}
			free(map);
			edge++;
	}
}

int			main(int ac, char **av)
{
	int					fd;

	if (ac != 2)
		ft_usage();
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			ft_error();
		else
		{
			if (loop(fd) == 0)
				return (0);
		}
	}
	return (1);
}
