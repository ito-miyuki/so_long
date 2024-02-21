/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:02:59 by mito              #+#    #+#             */
/*   Updated: 2024/02/21 13:50:10 by mito             ###   ########.fr       */
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
		printf ("failed at load player texture func on line no 36"); // delet it
		return (0);	
	}
	img->player = mlx_texture_to_image(mlx, player);
	if (!img->player)
	{
		printf ("failed at load player texture func on line no 42"); // delete it 
		return (0);	
	}
	mlx_delete_texture(player);
	return (img);
}

t_img *load_grass_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t *grass;
	
	grass = mlx_load_png("./png/grass.png");
	if (!grass)
	{
		printf ("failed at load grass texture func on line no 56");
		return (0);	
	}
	img->grass = mlx_texture_to_image(mlx, grass);
	if (!img->grass)
	{
		printf ("failed at load grass texture func on line no 62");
		return (0);	
	}
	mlx_delete_texture(grass);
	return (img);
}

t_img *load_item_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t *item;
	
	item = mlx_load_png("./png/onigiri.png");
	if (!item)
	{
		printf ("failed at load item texture func on line no 56");
		return (0);	
	}
	img->item = mlx_texture_to_image(mlx, item);
	if (!img->item)
	{
		printf ("failed at load item texture func on line no 62");
		return (0);	
	}
	mlx_delete_texture(item);
	return (img);
}

t_img *load_exit_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t *exit;
	
	exit = mlx_load_png("./png/exit.png");
	if (!exit)
	{
		printf ("failed at load exit texture func on line no 56");
		return (0);	
	}
	img->exit = mlx_texture_to_image(mlx, exit);
	if (!img->exit)
	{
		printf ("failed at load exit texture func on line no 62");
		return (0);	
	}
	mlx_delete_texture(exit);
	return (img);
}