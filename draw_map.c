/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:13:14 by vheymans          #+#    #+#             */
/*   Updated: 2021/11/24 19:54:44 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Contains all the functions needed to draw the map
*/

#include "so_long.h"

int	what_draw(t_game *g, char c, int x, int y)
{
	x = x * g->wdth;
	y = y * g->wdth;
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->wall, y, x);
	else if (c == '0')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->floor, y, x);
	else if (c == 'P' || c == 'L')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->ply_l, y, x);
	else if (c == 'R')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->ply_r, y, x);
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
	printf("draw\n");
	while (map[x])
	{
		y = 0;
		printf("draw line:%s\n", map[x]);
		while (map[x][y])
		{
			printf("draw char:%c\n", map[x][y]);
			what_draw(g, map[x][y], y, x);
			y ++;
		}
		x ++;
	}
	return (1);
}
