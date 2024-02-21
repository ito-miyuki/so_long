/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:02:59 by mito              #+#    #+#             */
/*   Updated: 2024/02/21 12:35:07 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img *load_floor_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t *floor;
	
	floor = mlx_load_png("./png/floor.png");
	if (!floor)
		return (0);
	img->floor = mlx_texture_to_image(mlx, floor);
	if (!img->floor)
		return (0);
	mlx_delete_texture(floor);
	return (img);
}

t_img *load_player_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t *player;
	
	player = mlx_load_png("./png/capy_right.png");
	if (!player)
	{
		printf ("failed at load player texture func on line no 36");
		return (0);	
	}
	img->player = mlx_texture_to_image(mlx, player);
	if (!img->player)
	{
		printf ("failed at load player texture func on line no 42");
		return (0);	
	}
	mlx_delete_texture(player);
	return (img);
}

