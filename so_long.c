/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:55:35 by vheymans          #+#    #+#             */
/*   Updated: 2021/11/24 19:50:39 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
**Creates a 2d string array of the map
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

int	initialize_game(t_game *g, char *address)
{
	g->move = 0;
	g->wdth = IMG_WIDTH;// DONT KNOW IF ALLOWED
	g->end = 0;
	g->mlx = mlx_init();
	g->floor = mlx_xpm_file_to_image(g->mlx, "a/floor.xpm", &g->wdth, &g->wdth);
	g->ply_l = mlx_xpm_file_to_image(g->mlx, "a/ply_l.xpm", &g->wdth, &g->wdth);
	g->ply_r = mlx_xpm_file_to_image(g->mlx, "a/ply_l.xpm", &g->wdth, &g->wdth);
	g->gold = mlx_xpm_file_to_image(g->mlx, "a/gold.xpm", &g->wdth, &g->wdth);
	g->wall = mlx_xpm_file_to_image(g->mlx, "a/wall.xpm", &g->wdth, &g->wdth);
	g->exit = mlx_xpm_file_to_image(g->mlx, "a/wall.xpm", &g->wdth, &g->wdth);
	printf("mlx file to image\n");
	if (create_map(g, address))
	{
		g->mlx_win = mlx_new_window(g->mlx, 1920, 1080, "so_long");// need to count the rows and cols
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
	mlx_loop(g.mlx);
	return (0);
}
