/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_shape_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:14:40 by mito              #+#    #+#             */
/*   Updated: 2024/02/16 15:27:35 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int is_rectangle(char **map_array)
{
	int i;
	size_t first_str;
	
	i = 1;
	first_str = ft_strlen(map_array[0]);
	while (map_array[i] != '\0')
	{
		if (first_str != ft_strlen(map_array[i]))
			return (0);
		i++;
	}
	return (1);
}

int only_char(char *str, char c)
{
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

 /* what if the map is like this? is's closed and surrounded by wall: 
  1111111111
  1E0000C001
  10000C0P11
  1111111110
 */
static int is_wall(char **map_array) 
{
	int i;
	int last_row;
	int last_idx;

	i = 1;
	last_row = 0;
	while (map_array[last_row] != NULL)
		last_row++;
	last_idx = ft_strlen(map_array[0]) - 1;
	if (!only_char(map_array[0], '1'))
			return (0);
	while (map_array[i] != NULL)
	{
		while (i > 0 && i < last_row - 1)
		{
			if ((map_array[i][0] != '1') || map_array[i][last_idx] != '1')
				return (0);
			i++;
		}
		if (i == last_row - 1)
		{
			if (!only_char(map_array[i], '1'))
				return (0);
		}
		i++;
	}
	return (1);	
}

int valid_shape_map(char **map_array)
{
	if (is_rectangle(map_array))
	{
		printf("map is rectangle\n"); // delete it
	}
	if (is_wall(map_array))
		printf("map is surrounded by wall\n"); // delete it 
	else
		printf("map is NOT surrounded by wall\n"); // delete it 
	if (is_rectangle(map_array) && is_wall(map_array))
		return (1);
	return (0);
}
