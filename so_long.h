/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:46:56 by vheymans          #+#    #+#             */
/*   Updated: 2021/12/11 16:12:50 by vheymans         ###   ########.fr       */
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
# include <stdlib.h> // malloc, free, exit, printf
# include <stdio.h> // perror
# include <string.h> // strerror

/*
**MINILIBX
*/

# include "mlx/mlx.h"

/*
**Structures
*/

/*typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;*/

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_list	*map_l;
	char	**map;
	int		*count;// free at the end
	int		size;
	int		len;
	int		move;
	int		ppos[2];
	int		wdth;
	void	*floor;
	void	*ply_l;
	void	*ply_r;
	void	*gold;
	void	*wall;
	void	*exit;
	int		end;
}			t_game;

/*
**IMG_WIDTH
*/

# ifndef IMG_WIDTH
#  define IMG_WIDTH 40 // DONT KNOW IF ALLOWED
# endif

/*
** Functions
*/

int		check_map(t_game *g, int *good);
int		draw_map(t_game *g);
int		play_move(int key, t_game *g);
int		exit_game(t_game *g);

#endif