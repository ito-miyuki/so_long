/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:08:24 by mito              #+#    #+#             */
/*   Updated: 2024/02/27 16:58:36 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_item(t_game *game, int y, int x)
{
	size_t i;

	i = 0;
	x = x * 32 + 16;
	y = y * 32 + 16;
	// 引数で渡された座標にあるアイテムを見つけたら非表示にする
	while (i < game->img->item->count)
	{
		if (game->img->item->instances[i].x == x 
			&& game->img->item->instances[i].y == y)
			game->img->item->instances[i].enabled = false;
		i++;
	}
}