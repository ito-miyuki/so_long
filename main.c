/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:14:54 by mito              #+#    #+#             */
/*   Updated: 2024/03/13 11:06:30 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./MLX42/include/MLX42/MLX42.h"

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		error_message("invalid input. We can read only one map at a time");
	is_ber(argv[1]);
	game = init_map_data(argv[1]);
	game->mlx = mlx_init(game->width * PIXELS,
			game->height * PIXELS, "so_long", false);
	if (!game->mlx)
		return (EXIT_FAILURE);
	game->img = init_img_struct(game->mlx);
	fill_background(game);
	render_map(game);
	game->img->moves_print = mlx_put_string(game->mlx, "MOVES: ",
			8, game->height * PIXELS - 22);
	mlx_key_hook(game->mlx, moves_keyhook, game);
	mlx_close_hook(game->mlx, close_hook, game);
	mlx_loop(game->mlx);
	free(game);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
