/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:12:34 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/06 15:27:15 by vheymans         ###   ########.fr       */
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
	if (g->map[x][y] == '1')
		return (0);
	if (g->map[x][y] == 'E')
	{
		if (g->count[0] != 0)
			return (0);
		else
		{
			g->end = 1;
			exit_game(g);
		}
	}
	if (g->map[x][y] == 'C')
		g->count[0] -= 1;
	if (y < g->ppos[1])
		g->map[x][y] = 'L';
	else if (y > g->ppos[1])
		g->map[x][y] = 'R';
	else
		g->map[x][y] = g->map[g->ppos[0]][g->ppos[1]];
	g->map[g->ppos[0]][g->ppos[1]] = '0';
	g->move ++;
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
	if (key == 115 || key == 119)
	{
		y = g->ppos[1];
		if (key == 115)
			x = g->ppos[0] + 1;
		else if (key == 119)
			x = g->ppos[0] - 1;
	}
	else if (key == 97 || key == 100)
	{
		x = g->ppos[0];
		if (key == 97)
			y = g->ppos[1] - 1;
		else if (key == 100)
			y = g->ppos[1] + 1;
	}
	if (x != -1 && check_move(x, y, g))
		draw_map(g);
	return (1);
}
