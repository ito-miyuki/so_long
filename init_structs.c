/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:47:15 by mito              #+#    #+#             */
/*   Updated: 2024/02/16 15:51:22 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	row_count(char **map_array)
{
	int i;
	i = 0;
	while (map_array[i] != NULL)
		i++;
	return (i);
}

t_game *init_game_struct(char **map_array)
{
	t_game *game;
	
	game = (t_game *)ft_calloc(1, sizeof(t_game)); // why do I need to type cast here?
	if (!game)
	{
		// free?
		return (0);
	}
	game->grid = map_array;
	game->width = ft_strlen(map_array[0]);
	game->height = row_count(map_array);
	return (game);
	
}