/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:29:00 by mito              #+#    #+#             */
/*   Updated: 2024/03/11 18:46:47 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Callback function used to handle window closing
 * which is called when the user attempts 
 * to close the window, for example
 * by clicking the close widget in the title bar.
 * 
 */
void	close_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	printf("You've clicked x widget to close this window");
	clean_up(game, NULL);
}
