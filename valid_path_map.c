/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:26:11 by mito              #+#    #+#             */
/*   Updated: 2024/03/04 14:24:51 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(char **grid, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
}

int	check_path(t_game *temp, size_t y, size_t x)
{
	if (temp->grid[y][x] == '1')
		return (0);
	if (temp->grid[y][x] == 'C')
		temp->item--;
	if (temp->grid[y][x] == 'E')
	{
		temp->exit_x = 1;
		return (0);
	}
	temp->grid[y][x] = '1';
	if (check_path(temp, y + 1, x)) // if (check_path(temp, y + 1, x) == 1) と同じ意味
		return (1);
	if (check_path(temp, y - 1, x)) // UP
		return (1);
	if (check_path(temp, y, x + 1)) // right
		return (1);
	if (check_path(temp, y, x - 1)) // left
		return (1);
	return (0);
}

void	ft_flood_fill(t_game *game) // ここで全部コピーする
{
	t_game	temp;
	size_t	i;

	i = 0;
	temp.height = game->height; // temp->height じゃないのは、tempはポインタじゃないから
	temp.width = game->width;
	temp.item = game->item;
	temp.player_x = game->player_x;
	temp.player_y = game->player_y;
	temp.exit_x = 0; // 出口に到達したか確認するのに、一度リセットしたいから
	temp.grid = malloc(sizeof(char *) * temp.height);
	if (!temp.grid)
	{
		free_grid(temp.grid, temp.height); // do I need this?
		error_message("temp.grid malloc fail\n");
	}
	while (i < temp.height)
	{
		temp.grid[i] = ft_strdup(game->grid[i]);
		i++;
	}
	check_path(&temp, temp.player_x, temp.player_y);
	if (!(temp.exit_x == 1 && temp.item == 0))
	{
		free_grid(temp.grid, temp.height); // do I need this?
		error_message("didn't pass Flood fill map validation"); // replace with nicer message
	}
	free_grid(temp.grid, temp.height);
}
