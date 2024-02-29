/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:50:59 by mito              #+#    #+#             */
/*   Updated: 2024/02/29 14:38:17 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *message)
{
	// putstrとputendlの違いは改行があるかないかだけ
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(message, 2);
	exit(1);
}

void	print_moves_screen(t_game *game)
{
	char *string;
	
	string = ft_itoa(game->steps);
	mlx_delete_image(game->mlx, game->img->moves_nbr);
	game->img->moves_nbr = mlx_put_string(game->mlx, string, 80, game->height * 32 - 22);
	free (string);
}

void	print_moves_terminal(t_game *game)
{
	char *string;
	
	string = ft_itoa(game->steps);
	ft_printf("Moves: %s\n", string);
	free (string);
}

void check_game_status(t_game *game)
{
	//print_move func here?
	if (game->collected == game->item)
	{
		mlx_close_window(game->mlx);
	}
	
}