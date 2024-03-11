/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:10:20 by mito              #+#    #+#             */
/*   Updated: 2024/03/11 14:47:35 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	check_wall_rows(char **map_array)
{
	int	i;
	int	last_row;

	i = 0;
	last_row = row_count(map_array);
	if (!(only_char(map_array[0], '1')))
		return (0);
	if (!(only_char(map_array[last_row - 1], '1')))
		return (0);
	return (1);
}

static int	check_wall_columns(char **map_array)
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

int	is_wall(char **map_array)
{
	if (!(check_wall_columns(map_array) && check_wall_rows(map_array)))
		return (0);
	return (1);
}
