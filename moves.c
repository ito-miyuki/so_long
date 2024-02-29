/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:54:54 by mito              #+#    #+#             */
/*   Updated: 2024/02/29 11:42:13 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game *move_up(t_game *game)
{
	if (game->grid[game->player_y - 1][game->player_x] != '1' 
		&& game->grid[game->player_y - 1][game->player_x] != 'E')
	{
		if (game->grid[game->player_y - 1][game->player_x] == 'C')
		{
			remove_item(game, game->player_y - 1, game->player_x);
			game->grid[game->player_y - 1][game->player_x] = '0';
			game->collected += 1;
		}
		game->player_y -= 1;
		game->img->player->instances[0].y -= 1 * PIXELS;
		game->steps += 1;
		print_moves_terminal(game);
		print_moves_screen(game);
	}
	else if (game->grid[game->player_y - 1][game->player_x] == 'E') //it's temporaly. should implement a better solution
		check_game_status(game);
	return (game);
}

t_game *move_down(t_game *game)
{
	if (game->grid[game->player_y + 1][game->player_x] != '1'
		&& game->grid[game->player_y + 1][game->player_x] != 'E')
	{
		if (game->grid[game->player_y + 1][game->player_x] == 'C')
		{
			remove_item(game, game->player_y + 1, game->player_x);
			game->grid[game->player_y + 1][game->player_x] = '0';
			game->collected += 1;
		}
		game->player_y += 1;
		game->img->player->instances[0].y += 1 * PIXELS;
		game->steps += 1;
		print_moves_terminal(game);
		print_moves_screen(game);
	}
	else if (game->grid[game->player_y + 1][game->player_x] == 'E') //it's temporaly. should implement a better solution
		check_game_status(game);
	return (game);
}

t_game *move_right(t_game *game)
{
	if (game->grid[game->player_y][game->player_x + 1] != '1'
		&& game->grid[game->player_y][game->player_x + 1] != 'E')
	{
		if (game->grid[game->player_y][game->player_x + 1] == 'C')
		{
			remove_item(game, game->player_y, game->player_x + 1);
			game->grid[game->player_y][game->player_x + 1] = '0';
			game->collected += 1;
		}
		game->player_x += 1;
		game->img->player->instances[0].x += 1 * PIXELS;
		game->steps += 1;
		print_moves_terminal(game);
		print_moves_screen(game);
	}
	else if (game->grid[game->player_y][game->player_x + 1] == 'E') // it's temporaly. should implement a better solution
		check_game_status(game);
	return (game);
}

t_game *move_left(t_game *game)
{
	if (game->grid[game->player_y][game->player_x - 1] != '1'
		&& game->grid[game->player_y][game->player_x - 1] != 'E')
	{
		if (game->grid[game->player_y][game->player_x - 1] == 'C')
		{
			remove_item(game, game->player_y, game->player_x - 1);
			game->grid[game->player_y][game->player_x - 1] = '0';
			game->collected += 1;
		}
		game->player_x -= 1;
		game->img->player->instances[0].x -= 1 * PIXELS;	
		game->steps += 1;
		print_moves_terminal(game);
		print_moves_screen(game);
	}
	else if (game->grid[game->player_y][game->player_x - 1] == 'E') // it's temporaly. should implement a better solution
		check_game_status(game);
	return (game);
}

void moves_keyhook(mlx_key_data_t keydata, void *data)
{
	t_game *game;
	game = (t_game *)data;
	// If we PRESS the 'W' key, it moves to "UP"
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(game);
	// If we RELEASE the 'A' key, it moves to "LEFT".
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		move_left(game);
	// If we RELEASE the 'S' key, it moves to "DOWN"
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		move_down(game);
	// If we RELEASE the 'D' key, it moves to "RIGHT".
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		move_right(game);
}