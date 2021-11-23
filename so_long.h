/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:46:56 by vheymans          #+#    #+#             */
/*   Updated: 2021/11/22 18:00:19 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*
**LIBRARY
*/

# include "libft/libft.h"

/*
**INCLUDES
*/

# include <fcntl.h> // open
# include <unistd.h> // close, read, write,
# include <stdlib.h> // malloc, free, exit
# include <stdio.h> // perror
# include <string.h> // strerror

/*
**MINILIBX
*/

# include "minilibx/mlx.h"

/*
**Structures
*/

typedef struct s_game
{
	t_list	*map;
	int		collect;
	int		exit;
	int		player;
	int		size;
}			t_game;

/*
** Functions
*/

int		check_map(t_game *g, int *good);

#endif