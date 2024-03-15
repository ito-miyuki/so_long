/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:02:59 by mito              #+#    #+#             */
/*   Updated: 2024/03/14 13:11:16 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*load_floor_texture(mlx_t *mlx, t_img *img, t_game *game)
{
	mlx_texture_t	*floor;

	floor = mlx_load_png("./png/floor.png");
	if (!floor)
		clean_up_exit(game, "Loading image failed");
	img->floor = mlx_texture_to_image(mlx, floor);
	if (!img->floor)
	{
		mlx_delete_texture(floor);
		clean_up_exit(game, "Loading image failed");
	}
	mlx_delete_texture(floor);
	return (img);
}

t_img	*load_player_texture(mlx_t *mlx, t_img *img, t_game *game)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./png/player.png");
	if (!player)
		clean_up_exit(game, "Loading image failed");
	img->player = mlx_texture_to_image(mlx, player);
	if (!img->player)
	{
		mlx_delete_texture(player);
		clean_up_exit(game, "Loading image failed");
	}
	mlx_delete_texture(player);
	return (img);
}

t_img	*load_grass_texture(mlx_t *mlx, t_img *img, t_game *game)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("./png/grass.png");
	if (!grass)
		clean_up_exit(game, "Loading image failed");
	img->grass = mlx_texture_to_image(mlx, grass);
	if (!img->grass)
	{
		mlx_delete_texture(grass);
		clean_up_exit(game, "Loading image failed");
	}
	mlx_delete_texture(grass);
	return (img);
}

t_img	*load_item_texture(mlx_t *mlx, t_img *img, t_game *game)
{
	mlx_texture_t	*item;

	item = mlx_load_png("./png/onigiri.png");
	if (!item)
		clean_up_exit(game, "Loading image failed");
	img->item = mlx_texture_to_image(mlx, item);
	if (!img->item)
	{
		mlx_delete_texture(item);
		clean_up_exit(game, "Loading image failed");
	}
	mlx_delete_texture(item);
	return (img);
}

t_img	*load_exit_texture(mlx_t *mlx, t_img *img, t_game *game)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./png/exit.png");
	if (!exit)
		clean_up_exit(game, "Loading image failed");
	img->exit = mlx_texture_to_image(mlx, exit);
	if (!img->exit)
	{
		mlx_delete_texture(exit);
		clean_up_exit(game, "Loading image failed");
	}
	mlx_delete_texture(exit);
	return (img);
}
