/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:46:20 by mito              #+#    #+#             */
/*   Updated: 2024/02/21 12:43:57 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void image_select(t_game *data, size_t y, size_t x)
{
    size_t img_size;
	
    img_size = 32;
    if (data->grid[y][x] == 'P')
    {
        if (mlx_image_to_window(data->mlx, data->img->player, x * PIXELS, y * PIXELS) < 0)
            return ; // please modifiy it!
    }
	if (data->grid[y][x] == 'P')
    {
        if (mlx_image_to_window(data->mlx, data->img->player, x * PIXELS, y * PIXELS) < 0)
            return ; // please modifiy it!
    }
}

void fill_background(t_game *data)
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
			printf ("you're in fill_background loop\n");
			//mlx_image_to_window(data->mlx, data->img->floor, x * PIXELS, y * PIXELS);
			if (mlx_image_to_window(data->mlx, data->img->floor, x * PIXELS, y * PIXELS) < 0)
			{
				printf("Fill background failed\n"); // modify it to subeject accordingly
				return ;
			}
			x++;
			//printf("x incremented\n");
		}
		y++;
		//printf("y incremented\n");
	}
	printf ("complete fill background func\n");
}
