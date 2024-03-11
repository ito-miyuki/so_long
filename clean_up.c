/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:12:12 by mito              #+#    #+#             */
/*   Updated: 2024/03/11 18:25:38 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_up(t_game *game, char *message)
{
	free_grid(game->grid);
	mlx_delete_image(game->mlx, game->img->player);
	mlx_delete_image(game->mlx, game->img->item);
	mlx_delete_image(game->mlx, game->img->floor);
	mlx_delete_image(game->mlx, game->img->grass);
	mlx_delete_image(game->mlx, game->img->exit);
	mlx_delete_image(game->mlx, game->img->moves_print);
	mlx_delete_image(game->mlx, game->img->moves_nbr);
	free(game->img);
	if (message != NULL)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putendl_fd(message, 2);
	}
	mlx_close_window(game->mlx);
}
