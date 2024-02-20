/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:02:59 by mito              #+#    #+#             */
/*   Updated: 2024/02/20 14:07:11 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img *load_player_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t *player;
	
	player = mlx_load_png("./png/capy_right.png");
	// add error handling;
	img->player = mlx_texture_to_image(mlx, player);
	mlx_delete_texture(player);
	return (img);
}

