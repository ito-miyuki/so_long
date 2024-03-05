/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:47:15 by mito              #+#    #+#             */
/*   Updated: 2024/03/05 11:34:21 by mito             ###   ########.fr       */
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
	assets = load_player_texture(mlx, assets);
	assets = load_grass_texture(mlx, assets);
	assets = load_item_texture(mlx, assets);
	assets = load_exit_texture(mlx, assets);
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

size_t count_items(t_game *game)
{
	size_t y;
	size_t x;
	size_t count;
	
	y = 0;
	x = 0;
	count = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->grid[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
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
	game->grid = map_array; // t_game構造体はマップのデータをmap_arrayを通じて参照する
	game->width = ft_strlen(map_array[0]);
	game->height = row_count(map_array);
	game->item = count_items(game);
	game->player_x = get_position(game, 'P', 'x');
	game->player_y = get_position(game, 'P', 'y');
	game->exit_x = get_position(game, 'E', 'x');
	game->exit_y = get_position(game, 'E', 'y');
	
	//free_grid(map_array, game->height); // t_game構造体はマップのデータをmap_arrayを通じて参照するからここで解放するとデータを失う
	return (game);
}