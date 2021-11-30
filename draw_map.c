/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:13:14 by vheymans          #+#    #+#             */
/*   Updated: 2021/11/29 11:18:44 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Contains all the functions needed to draw the map
*/

#include "so_long.h"

int	what_draw(t_game *g, char c, int x, int y)
{
	int	p_pos[2];

	x = x * g->wdth;
	y = y * g->wdth;
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->wall, y, x);
	else if (c == '0')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->floor, y, x);
	else if (c == 'P' || c == 'L' || c == 'R')
	{
		p_pos[0] = x / g->wdth;
		p_pos[1] = y / g->wdth;
		g->ppos = p_pos;
		printf ("p_pos : [%d][%d]\n", p_pos[0], p_pos[1]);
		if (c == 'P' || c == 'L')
			mlx_put_image_to_window(g->mlx, g->mlx_win, g->ply_l, y, x);
		if (c == 'R')
			mlx_put_image_to_window(g->mlx, g->mlx_win, g->ply_r, y, x);
	}
	else if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->gold, y, x);
	else if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->exit, y, x);
	return (1);
}

/*
**Main draw function
*/

int	draw_map(t_game *g)
{
	int		x;
	int		y;
	char	**map;

	x = 0;
	map = g->map;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			printf("%c", map[x][y]);
			what_draw(g, map[x][y], x, y);
			y ++;
		}
		printf("\n");
		x ++;
	}
	return (1);
}
