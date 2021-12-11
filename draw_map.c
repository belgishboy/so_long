/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:13:14 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/11 16:22:03 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Contains all the functions needed to draw the map
*/

#include "so_long.h"

int	what_draw(t_game *g, char c, int row, int col)
{
	row = row * g->wdth;
	col = col * g->wdth;
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->wall, col, row);
	else if (c == '0')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->floor, col, row);
	else if (c == 'P' || c == 'L' || c == 'R')
	{
		if (c == 'P' || c == 'L')
			mlx_put_image_to_window(g->mlx, g->mlx_win, g->ply_l, col, row);
		if (c == 'R')
			mlx_put_image_to_window(g->mlx, g->mlx_win, g->ply_r, col, row);
	}
	else if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->gold, col, row);
	else if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->exit, col, row);
	return (1);
}

/*
**Main draw function
*/

int	draw_map(t_game *g)
{
	int		row;
	int		col;
	char	**map;
	char	c;

	row = 0;
	map = g->map;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			c = map[row][col];
			if (c == 'P' || c == 'L' || c == 'R')
				g->ppos[0] = row;
			if (c == 'P' || c == 'L' || c == 'R')
				g->ppos[1] = col;
			what_draw(g, map[row][col], row, col);
			col ++;
		}
		row ++;
	}
	mlx_string_put(g->mlx, g->mlx_win, 12, 1 * IMG_WIDTH, 0xff0000ff, ft_itoa(g->move));// find a valid color
	return (1);
}
