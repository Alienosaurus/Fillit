/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:20:14 by dalexand          #+#    #+#             */
/*   Updated: 2016/03/31 23:22:09 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_error(void)
{
	ft_putstr_fd("error\n", 1);
	exit(0);
}

int					ft_read(int fd, t_tetriminos **result, int nbtetri, int *nb_read)
{
	char			str[22];

	*nb_read = read(fd, &str, 21);
	str[*nb_read] = '\0';
	if (*nb_read > 0 && (str[20] == '\n' || str[20] == '\0'))
	{	
		str[20] = '\0';
		*result = parse(str, nbtetri);
		printf("%d -> %d\n", nbtetri, *nb_read);
		return (1);
	}
	else if (*nb_read == 0)
	{
	printf("%d -> %d\n", nbtetri, *nb_read);
	return (0);}
	printf("%d -> %d\n", nbtetri, *nb_read);
	return (-1);
}

t_tetriminos_array	*ft_read_all(int fd)
{
	t_tetriminos		**tab;
	t_tetriminos_array	*result;
	int 			nb_last_read;
	int				nb_last_success_read;
	int			i;
	int			status;

	i = 0;
	if (!(tab = ((t_tetriminos **)malloc(sizeof(t_tetriminos *) * 26))))
		return (NULL);
	if (!(result = ((t_tetriminos_array *)malloc(sizeof(t_tetriminos_array)))))
		return (NULL);
	while ((status = ft_read(fd, &(tab[i]), i, &nb_last_read)) > 0 && i <= 26)
	{	
		nb_last_success_read = nb_last_read;
		i++;
	}
	close(fd);
	printf("%d", nb_last_read);
	if (status < 0 || i > 26 || i == 0 || nb_last_success_read != 20)
		ft_error();
	result->array = tab;
	result->size = i;
	return (result);
}
