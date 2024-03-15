/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:14:54 by mito              #+#    #+#             */
/*   Updated: 2024/03/15 10:37:48 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		error_message("Invalid input. Please put only one map");
	is_ber(argv[1]);
	game = init_map_data(argv[1]);
	game->mlx = mlx_init(game->width * PIXELS,
			game->height * PIXELS, "so_long", false);
	if (!game->mlx)
		return (EXIT_FAILURE);
	game->img = init_img_struct(game->mlx, game);
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
