/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:02:59 by mito              #+#    #+#             */
/*   Updated: 2024/03/07 13:32:22 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*load_floor_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*floor;

	floor = mlx_load_png("./png/floor.png");
	if (!floor)
		error_message("Loading image failed");
	img->floor = mlx_texture_to_image(mlx, floor);
	if (!img->floor)
		error_message("Loading image failed");
	mlx_delete_texture(floor);
	return (img);
}

t_img	*load_player_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./png/player.png");
	if (!player)
		error_message("Loading image failed");
	img->player = mlx_texture_to_image(mlx, player);
	if (!img->player)
		error_message("Loading image failed");
	mlx_delete_texture(player);
	return (img);
}

t_img	*load_grass_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("./png/grass.png");
	if (!grass)
		error_message("Loading image failed");
	img->grass = mlx_texture_to_image(mlx, grass);
	if (!img->grass)
		error_message("Loading image failed");
	mlx_delete_texture(grass);
	return (img);
}

t_img	*load_item_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*item;

	item = mlx_load_png("./png/onigiri.png");
	if (!item)
		error_message("Loading image failed");
	img->item = mlx_texture_to_image(mlx, item);
	if (!img->item)
		error_message("Loading image failed");
	mlx_delete_texture(item);
	return (img);
}

t_img	*load_exit_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./png/exit.png");
	if (!exit)
		error_message("Loading image failed");
	img->exit = mlx_texture_to_image(mlx, exit);
	if (!img->exit)
		error_message("Loading image failed");
	mlx_delete_texture(exit);
	return (img);
}
