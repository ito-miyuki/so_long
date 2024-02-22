/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:54:54 by mito              #+#    #+#             */
/*   Updated: 2024/02/22 12:21:43 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game move_up(t_game *data)
{
	
}

void moves_keyhook(mlx_key_data_t keydata, void* data)
{
	// THIS IS JUST A TEST
	 t_game *game;

	 game = (t_game *)data;
	// If we PRESS the 'W' key, print "UP". W is for up
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		move_up(game);
		printf("UP\n");
	}
	// If we RELEASE the 'A' key, print "LEFT".
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		printf("LEFT\n");
	// If we RELEASE the 'S' key, print "DOWN".
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		printf("DOWN\n");
	// If we RELEASE the 'D' key, print "LEFT".
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		printf("LEFT\n");

}