/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:12:34 by vheymans          #+#    #+#             */
/*   Updated: 2021/11/29 11:14:41 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Has all the functions nessecary for moving/playing the game
*/

#include "so_long.h"

/*
**checks if the move is possible
*/

int	check_move(int x, int y, t_game *g)
{
	char	**map;

	map = g->map;
	printf("check move\n");
	if (map[x][y] == '1')
		return (0);
	if (map[x][y] == 'E' && g->count[0] != 0)
		return (0);
	if (map[x][y] == 'C')
	{
		printf("count before 2: %d\n", g->count[0]);
		g->count[0] -= 1;
		printf("count after: %d\n", g->count[0]);
	}
	printf("move checked\n");
	g->map[x][y] = 'P';
	g->map[g->ppos[0]][g->ppos[1]] = '0';
	return (1);
}

/*
**Main function
*/

int	play_move(int key, t_game *g)
{
	int	x;
	int	y;

	x = -1;
	printf("play_move\n");
	if (key == 115)
	{
		printf("s\n");
		x = g->ppos[0] + 1;
		y = g->ppos[1];
		printf("x: %d\t::\ty:%d\n", x, y);
	}
	if (x != -1 && check_move(x, y, g))
	{
		printf("draw_map\n");
		draw_map(g);
		return (1);
	}
	return (0);
}
