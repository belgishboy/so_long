/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:55:35 by vheymans          #+#    #+#             */
/*   Updated: 2021/11/23 16:43:23 by vheymans         ###   ########.fr       */
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
	g->map = map;
	check_map(g, &good);
	return (good);
}

int	main(int argc, char **argv)
{
	t_game	g;

	printf("%s\n", argv[1]);
	if (argc == 2)
		create_map(&g, argv[1]);
	printf("GOOD MAP\n");
	return (0);
}
