/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:12:12 by mito              #+#    #+#             */
/*   Updated: 2024/03/13 11:03:05 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_up(t_game *game, char *message)
{
	if (game->mlx)
	{
		mlx_close_window(game->mlx);
	}
	free_grid(game->grid);
	if (game->img != NULL)
	{
		mlx_delete_image(game->mlx, game->img->player);
		mlx_delete_image(game->mlx, game->img->item);
		mlx_delete_image(game->mlx, game->img->floor);
		mlx_delete_image(game->mlx, game->img->grass);
		mlx_delete_image(game->mlx, game->img->exit);
		mlx_delete_image(game->mlx, game->img->moves_print);
		mlx_delete_image(game->mlx, game->img->moves_nbr);
		free(game->img);
	}
	if (message != NULL)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putendl_fd(message, 2);
	}
}

void	clean_up_exit(t_game *game, char *message)
{
	free_grid(game->grid);
	if (game->img != NULL)
	{
		mlx_delete_image(game->mlx, game->img->player);
		mlx_delete_image(game->mlx, game->img->item);
		mlx_delete_image(game->mlx, game->img->floor);
		mlx_delete_image(game->mlx, game->img->grass);
		mlx_delete_image(game->mlx, game->img->exit);
		mlx_delete_image(game->mlx, game->img->moves_print);
		mlx_delete_image(game->mlx, game->img->moves_nbr);
		free(game->img);
	}
	if (message != NULL)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putendl_fd(message, 2);
	}
	if (game->mlx)
		mlx_terminate(game->mlx);
	exit(1);
}
