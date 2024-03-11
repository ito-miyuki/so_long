/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:46:20 by mito              #+#    #+#             */
/*   Updated: 2024/03/11 18:25:10 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_select(t_game *data, size_t y, size_t x)
{
	size_t	img_size;

	img_size = 32;
	if (data->grid[y][x] == 'P')
		if (mlx_image_to_window(data->mlx, data->img->player,
				x * PIXELS, y * PIXELS) < 0)
			clean_up(data, "Failed to put image to window");
	if (data->grid[y][x] == '1')
		if (mlx_image_to_window(data->mlx, data->img->grass,
				x * PIXELS, y * PIXELS) < 0)
			clean_up(data, "Failed to put image to window");
	if (data->grid[y][x] == 'C')
		if (mlx_image_to_window(data->mlx, data->img->item,
				x * PIXELS, y * PIXELS) < 0)
			clean_up(data, "Failed to put image to window");
	if (data->grid[y][x] == 'E')
		if (mlx_image_to_window(data->mlx, data->img->exit,
				x * PIXELS, y * PIXELS) < 0)
			clean_up(data, "Failed to put image to window");
}

void	render_map(t_game *data)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			image_select(data, y, x);
			x++;
		}
		y++;
	}
}

void	fill_background(t_game *data)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (mlx_image_to_window(data->mlx, data->img->floor,
					x * PIXELS, y * PIXELS) < 0)
				error_message("Fill background failed\n"); // mis it correct?
			x++;
		}
		y++;
	}
}
