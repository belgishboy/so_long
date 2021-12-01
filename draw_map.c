/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:13:14 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/01 20:46:07 by vheymans         ###   ########.fr       */
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
			{
				g->ppos[0] = row;
				g->ppos[1] = col;
			}
			what_draw(g, map[row][col], row, col);
			col ++;
		}
		row ++;
	}
	return (1);
}
