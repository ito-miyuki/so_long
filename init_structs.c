/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:47:15 by mito              #+#    #+#             */
/*   Updated: 2024/02/21 11:24:24 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*init_img_struct(mlx_t *mlx)
{
	t_img *assets;

	assets = (t_img *)ft_calloc(1, sizeof(t_img)); //allocate memory for assets pointer and init with 0
	if (!assets)
		return (NULL);
	assets = load_floor_texture(mlx, assets);
	if (!assets)
		printf ("failed line no 24 in init-img-struct func\n");
	assets = load_player_texture(mlx, assets);
	if (!assets)
		printf ("failed line no 27 in init-img-struct func\n");
	return (assets);
}

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
		printf("calloc faile at init game struct func\n");
		// free?
		return (0);
	}
	game->grid = map_array;
	game->width = ft_strlen(map_array[0]);
	game->height = row_count(map_array);
	return (game);
}