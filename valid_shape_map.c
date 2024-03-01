/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_shape_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:14:40 by mito              #+#    #+#             */
/*   Updated: 2024/03/01 16:01:32 by mito             ###   ########.fr       */
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

 /* what if the map is like this? is it considered as closed or surrounded by wall?: 
  1111111111
  1E0000C001
  10000C0P11
  1111111110
 */

static int check_wall_rows(char **map_array) //横にチェック
{
	int	i;
	int	last_row;

	i = 0;
	last_row = row_count(map_array);
	if (!(only_char(map_array[0], '1')))
		return (0);
	if (!(only_char(map_array[last_row], '1')))
		return (0);
	return (1);
}

static int check_wall_columns(char **map_array) //縦にチェック
{
	int	i;
	int	last_idx;

	i = 0;
	last_idx = ft_strlen(map_array[0]) - 1;
	while (map_array[i] != NULL)
	{
		if ((map_array[i][0] != '1') || map_array[i][last_idx] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int is_wall(char **map_array) 
{
	if (!(check_wall_columns(map_array) && check_wall_rows(map_array)))
		return (0);
	return (1);
}


void valid_shape_map(char **map_array)
{
	if (!(is_rectangle(map_array)))
		error_message("map is not a rectangle");
	if (!(is_wall(map_array)))
		error_message("map is not surrounded by wall");
}
