/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheymans <vheymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:03:51 by vheymans          #+#    #+#             */
/*   Updated: 2021/11/25 17:19:15 by vheymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**All the functions nesscisary for map error checking
*/

#include "so_long.h"

int	*check_middle(char *line, int count[], int *good, size_t len)
{
	size_t	x;

	x = 0;
	if (len != ft_strlen(line))
		*good = ft_error("Not a Rectangle");
	while (line[x])
	{
		if (x == 0 || x == len - 1)
		{
			if (line[x] != '1')
				*good = ft_error("Missing outside wall");
		}
		else if (line[x] == 'C')
			count[0]++;
		else if (line[x] == 'E')
			count[1]++;
		else if (line[x] == 'P')
			count[2]++;
		else if (line[x] != '1' && line[x] != '0')
			*good = ft_error("Invalid input");
		x ++;
	}
	return (good);
}

size_t	check_outside(char *line, int *good)
{
	int	len;
	int	x;

	len = ft_strlen(line);
	x = 0;
	while (line[x])
	{
		if (line[x++] != '1')
			*good = ft_error("Invalid top or bottom row");
	}
	if (len < 3)
		*good = ft_error("Not a Rectangle");
	*good = 1;
	return (len);
}

char	**create_map_array(t_game *g)
{
	char	**map_a;
	int		x;
	t_list	*map_l;

	map_a = ft_calloc((g->size) + 1, sizeof(char *));
	x = 0;
	map_l = g->map_l;
	g->len = ft_strlen(map_l->content);
	while (x < g->size)
	{
		map_a[x] = ft_substr(map_l->content, 0, ft_strlen(map_l->content));
		x ++;
		map_l = map_l->next;
	}
	return (map_a);
}

/*
** Main function
*/

int	check_map(t_game *g, int *good)
{
	int		count[3];
	size_t	len;
	t_list	*check;

	check = g->map_l;
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	len = check_outside(check->content, good);
	check = check->next;
	while (check->next != NULL && *good)
	{
		good = check_middle(check->content, count, good, len);
		check = check->next;
	}
	if (count[2] != 1 || count[0] < 1 || count[1] < 1)
		*good = ft_error("Invalid count");
	if (check_outside(check->content, good) != len)
		*good = ft_error("Not a Rectangle");
	g->count = count;
	g->map = create_map_array(g);
	return (1);
}
