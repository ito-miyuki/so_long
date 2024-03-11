/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:41:39 by mito              #+#    #+#             */
/*   Updated: 2024/03/11 18:32:22 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# define PIXELS 32

typedef struct s_img
{
	mlx_image_t	*player;
	mlx_image_t	*item;
	mlx_image_t	*floor;
	mlx_image_t	*grass;
	mlx_image_t	*exit;
	mlx_image_t	*moves_print;
	mlx_image_t	*moves_nbr;
}				t_img;

typedef struct s_game
{
	char			**grid;
	size_t			width;
	size_t			height;
	size_t			item;
	size_t			collected;
	size_t			player_x;
	size_t			player_y;
	size_t			exit_x;
	size_t			exit_y;
	size_t			steps;
	t_img			*img;
	mlx_t			*mlx;
}				t_game;

// read map
char	*read_map(char *map);

// valid char map
void	valid_char_map(char *map_str, char **map_array);

//valid shape map
void	valid_shape_map(char *map_str, char **map_array);
int		only_char(char *str, char c);

//init map data
void	is_ber(char *file_name);
t_game	*init_map_data(char *argv);

// valid path map
void	free_grid(char **grid);
int		check_path(t_game *temp, size_t y, size_t x);
void	ft_flood_fill(t_game *game);

// get position
size_t	get_position(t_game *game, char c, char xy);

//init struct
t_img	*init_img_struct(mlx_t *mlx);
int		row_count(char **map_array);
size_t	count_items(t_game *game);
t_game	*init_game_struct(char **map_array);

//load images
t_img	*load_floor_texture(mlx_t *mlx, t_img *img);
t_img	*load_player_texture(mlx_t *mlx, t_img *img);
t_img	*load_grass_texture(mlx_t *mlx, t_img *img);
t_img	*load_item_texture(mlx_t *mlx, t_img *img);
t_img	*load_exit_texture(mlx_t *mlx, t_img *img);

// render map
void	render_map(t_game *data);
void	image_select(t_game *data, size_t y, size_t x);
void	fill_background(t_game *data);

// moves
void	moves_keyhook(mlx_key_data_t keydata, void *data);
void	close_hook(void *param);
t_game	*move_up(t_game *game);
t_game	*move_down(t_game *game);
t_game	*move_right(t_game *game);
t_game	*move_left(t_game *game);

//remove item
void	remove_item(t_game *game, int y, int x);

// check game status
void	error_message(char *message);
void	print_moves_terminal(t_game *game);
void	print_moves_screen(t_game *game);
void	check_game_status(t_game *game);

// check wall map
int		is_wall(char **map_array);

void	clean_up(t_game *game, char *message);

#endif