/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenece <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 12:14:01 by adenece           #+#    #+#             */
/*   Updated: 2016/03/31 17:36:01 by dalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			can_u_put_it(t_tetriminos *t, char **map, t_block *pos, int edge)
{
	unsigned char	x;
	unsigned char	y;

	x = pos->x;
	y = pos->y;
	return (
		x + t->width <= edge &&
		y + t->height <= edge &&
		map[x + t->blocks[0].x][y + t->blocks[0].y] == '.' &&
		map[x + t->blocks[1].x][y + t->blocks[1].y] == '.' &&
		map[x + t->blocks[2].x][y + t->blocks[2].y] == '.' &&
		map[x + t->blocks[3].x][y + t->blocks[3].y] == '.' &&
		x + t->blocks[0].x < edge && y + t->blocks[0].y < edge &&
		x + t->blocks[1].x < edge && y + t->blocks[1].y < edge &&
		x + t->blocks[2].x < edge && y + t->blocks[2].y < edge &&
		x + t->blocks[3].x < edge && y + t->blocks[3].y < edge);
}

void		put_it(t_tetriminos *t, char **map, t_block *pos)
{
	unsigned char	x;
	unsigned char	y;

	x = pos->x;
	y = pos->y;
	map[x + t->blocks[0].x][y + t->blocks[0].y] = t->letter;
	map[x + t->blocks[1].x][y + t->blocks[1].y] = t->letter;
	map[x + t->blocks[2].x][y + t->blocks[2].y] = t->letter;
	map[x + t->blocks[3].x][y + t->blocks[3].y] = t->letter;
}

void		reset_it(t_tetriminos *t, char **map, t_block *pos)
{
	unsigned char	x;
	unsigned char	y;

	x = pos->x;
	y = pos->y;
	map[x + t->blocks[0].x][y + t->blocks[0].y] = '.';
	map[x + t->blocks[1].x][y + t->blocks[1].y] = '.';
	map[x + t->blocks[2].x][y + t->blocks[2].y] = '.';
	map[x + t->blocks[3].x][y + t->blocks[3].y] = '.';
}

int			solve(t_tetriminos_array *ta, unsigned char i, char **map, int edge)
{
	t_block	pos;

	if (i == ta->size)
		return (1);
	pos.y = 0;
	while (pos.y < edge)
	{
		pos.x = 0;
		while (pos.x < edge)
		{
			if (can_u_put_it(ta->array[i], map, &pos, edge))
			{
				put_it(ta->array[i], map, &pos);
				if (solve(ta, i + 1, map, edge))
					return (1);
				reset_it(ta->array[i], map, &pos);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}
