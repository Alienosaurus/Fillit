/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:20:14 by dalexand          #+#    #+#             */
/*   Updated: 2016/03/31 17:12:08 by adenece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_error(void)
{
	ft_putstr_fd("error\n", 1);
	exit(0);
}

int					ft_read(int fd, t_tetriminos **result, int nbtetri)
{
	char			str[22];
	int				temp;

	temp = read(fd, &str, 21);
	if (temp > 0 && (str[20] == '\n' || str[20] == '\0'))
	{
		*result = parse(str, nbtetri);
		return (1);
	}
	else if (temp == 0)
		return (0);
	return (-1);
}

t_tetriminos_array	*ft_read_all(int fd)
{
	t_tetriminos		**tab;
	t_tetriminos_array	*result;
	int					i;
	int					status;

	i = 0;
	if (!(tab = ((t_tetriminos **)malloc(sizeof(t_tetriminos *) * 26))))
		return (NULL);
	if (!(result = ((t_tetriminos_array *)malloc(sizeof(t_tetriminos_array)))))
		return (NULL);
	while ((status = ft_read(fd, &(tab[i]), i)) > 0 && i <= 26)
		i++;
	close(fd);
	if (status < 0 || i > 26 || i == 0)
		ft_error();
	result->array = tab;
	result->size = i;
	return (result);
}
