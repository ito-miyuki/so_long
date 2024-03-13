/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:26:11 by mito              #+#    #+#             */
/*   Updated: 2024/03/13 11:46:17 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(char **grid)
{
	size_t	i;

	i = 0;
	if (grid == NULL)
		return ;
	while (grid[i] != NULL)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
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
	if (check_path(temp, y + 1, x))
		return (1);
	if (check_path(temp, y - 1, x))
		return (1);
	if (check_path(temp, y, x + 1))
		return (1);
	if (check_path(temp, y, x - 1))
		return (1);
	return (0);
}

bool	ft_flood_fill(t_game *game)
{
	t_game	temp;
	size_t	i;

	i = 0;
	temp.height = game->height;
	temp.width = game->width;
	temp.item = game->item;
	temp.player_x = game->player_x;
	temp.player_y = game->player_y;
	temp.exit_x = 0;
	temp.grid = ft_calloc(temp.height + 1, sizeof(char *));
	if (!temp.grid)
		clean_up_exit(game, "memory allocation failed\n");
	while (i < temp.height)
	{
		temp.grid[i] = ft_strdup(game->grid[i]);
		if (!temp.grid[i])
			clean_up_exit(game, "memory allocation failed\n");
		i++;
	}
	check_path(&temp, temp.player_y, temp.player_x);
	free_grid(temp.grid);
	if (!(temp.exit_x == 1 && temp.item == 0))
		return (false);
	return (true);
}
