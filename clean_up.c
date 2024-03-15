/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:12:12 by mito              #+#    #+#             */
/*   Updated: 2024/03/15 16:47:00 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_up(t_game *game, char *message)
{
	if (game->mlx)
		mlx_close_window(game->mlx);
	if (game->grid)
		free_grid(game->grid);
	if (game->img)
		free(game->img);
	if (game)
		free(game);
	if (message != NULL)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putendl_fd(message, 2);
	}
}

void	clean_up_exit(t_game *game, char *message)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->grid)
		free_grid(game->grid);
	if (game->img)
		free(game->img);
	if (game)
		free(game);
	if (message != NULL)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putendl_fd(message, 2);
	}
	exit(1);
}
