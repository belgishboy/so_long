/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:55:35 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/11 16:26:20 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
**Function for cleanly exiting the game
*/

int	exit_game(t_game *g)// EVERYTHING NEEDS TO BE FREEED
{
	mlx_loop_end(g->mlx);
	mlx_destroy_window(g->mlx, g->mlx_win);
	free(g->count);
	free(g->wall);
	free(g->floor);
	free(g->ply_l);
	free(g->ply_r);
	free(g->gold);
	free(g->exit);
	ft_lstclear(&(g->map_l), del);
	g->size --;
	while (g->size >= 0)
		del(g->map[g->size --]);
	free(g->map);
	if (!(g->end))
		ft_error("This is an exit");
	exit(0);
	return (1);
}

/*
**Function that takes care of all the key hooking/moving
*/

int	key_hook(int key, t_game *g)
{
	if (key == 65307)
		exit_game(g);
	else if (key == 119 || key == 115 || key == 100 || key == 97)
		play_move(key, g);
	else
		printf("Please enter a vaild input\n");//MAY NEED CHANGING
	return (1);
}

/*
**Creates a 2d array and list from the 'fd' and then sends it all to get checked
*/

int	create_map(t_game *g, char *file)
{
	int		fd;
	char	*line;
	t_list	*map;
	int		good;

	fd = open(file, O_RDONLY);
	if (fd == -1 || ft_strnstr(file, ".ber", ft_strlen(file))
		!= &file[ft_strlen(file) - 4])
		good = ft_error("Not a valid map file");
	map = NULL;
	g->size = 0;
	good = 1;
	while (good > 0 && fd != -1)
	{
		good = get_next_line(fd, &line);
		g->size ++;
		ft_lstadd_back(&map, ft_lstnew((void *)line));
	}
	close(fd);
	if (g->size < 3)
		good = ft_error("Too Small");
	g->map_l = map;
	check_map(g, &good);
	return (good);
}

/*
**sets up g, and initializes all of the images needed for the game
*/

int	initialize_game(t_game *g, char *address)
{
	g->move = 0;
	g->wdth = IMG_WIDTH;// DONT KNOW IF ALLOWED
	g->end = 0;
	g->mlx = mlx_init();
	g->floor = mlx_xpm_file_to_image(g->mlx, "a/floor.xpm", &g->wdth, &g->wdth);
	g->ply_l = mlx_xpm_file_to_image(g->mlx, "a/ply_l.xpm", &g->wdth, &g->wdth);
	g->ply_r = mlx_xpm_file_to_image(g->mlx, "a/ply_l.xpm", &g->wdth, &g->wdth); // GET A RIGHT IMAGE
	g->gold = mlx_xpm_file_to_image(g->mlx, "a/gold.xpm", &g->wdth, &g->wdth);
	g->wall = mlx_xpm_file_to_image(g->mlx, "a/wall.xpm", &g->wdth, &g->wdth);
	g->exit = mlx_xpm_file_to_image(g->mlx, "a/exit.xpm", &g->wdth, &g->wdth);
	if (create_map(g, address))
	{
		g->mlx_win = mlx_new_window(g->mlx, g->len * g->wdth,
				g->size * g->wdth, "so_long");
		draw_map(g);
	}
	else
		ft_error("Unable to create map");
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
		ft_error("Not correct Map input");
	initialize_game(&g, argv[1]);
	mlx_key_hook(g.mlx_win, &key_hook, &g);
	mlx_hook(g.mlx_win, 33, (1L << 17), exit_game, &g);
	mlx_hook(g.mlx_win, 19, (1L << 4), draw_map, &g);
	mlx_loop(g.mlx);
	return (0);
}
