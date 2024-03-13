/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_shape_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:14:40 by mito              #+#    #+#             */
/*   Updated: 2024/03/13 10:39:29 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangle(char **map_array)
{
	int		i;
	size_t	first_str;

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

int	only_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

static bool	is_map_too_big(char **map_array)
{
	int	row;
	int	col;

	row = row_count(map_array);
	col = ft_strlen(map_array[0]);
	if (col * PIXELS > 2500 || row * PIXELS > 1700)
		return (true);
	return (false);
}

void	valid_shape_map(char *map_str, char **map_array)
{
	if (is_map_too_big(map_array) == true)
	{
		free(map_str);
		free_grid(map_array);
		error_message("Map is too big.");
	}
	if (!(is_rectangle(map_array)))
	{
		free(map_str);
		free_grid(map_array);
		error_message("Map is not a rectangle");
	}
	if (!(is_wall(map_array)))
	{
		free(map_str);
		free_grid(map_array);
		error_message("Map is not surrounded by wall");
	}
}
