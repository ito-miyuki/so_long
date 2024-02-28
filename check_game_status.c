/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:50:59 by mito              #+#    #+#             */
/*   Updated: 2024/02/28 14:49:50 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_game_status(t_game *game)
{
	//print_move fun here;
	if (game->collected == game->item)
	{
		mlx_close_window(game->mlx);
	}
	
}