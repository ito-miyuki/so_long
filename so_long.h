#ifndef	SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

#define	WIDTH 256
#define HEIGHT 256

# define PIXELS 32
# define EMOVE 30

typedef struct s_img
{
	mlx_image_t	*player;
	mlx_image_t *item;
	mlx_image_t *floor;
	mlx_image_t *grass;
	mlx_image_t *exit;
	mlx_image_t	*moves_print;
	mlx_image_t *moves_nbr;
} t_img;

typedef struct s_game
{
	//void 	*mlx;
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
	mlx_t			*mlx; // これは何のため？
	mlx_texture_t	*player_up;
} t_game;

int		main(int argc, char **argv);
t_game 	*init_map_data(char *argv);
char	*read_map(char *map);
void	valid_char_map(char *map_str);
void	valid_shape_map(char **map_array);
int		is_ber(char *file_name);
int 	check_path(t_game *temp, size_t y, size_t x);
void	ft_flood_fill(t_game *game);
void	free_grid(char **grid, size_t height);

size_t	get_position(t_game *game, char c, char xy);
t_game 	*init_game_struct(char **map_array);
size_t 	count_items(t_game *game);

void 	image_select(t_game *data, size_t y, size_t x);
t_img	*init_img_struct(mlx_t *mlx);

t_img	*load_floor_texture(mlx_t *mlx, t_img *img);
t_img	*load_player_texture(mlx_t *mlx, t_img *img);
t_img 	*load_grass_texture(mlx_t *mlx, t_img *img);
t_img 	*load_item_texture(mlx_t *mlx, t_img *img);
t_img 	*load_exit_texture(mlx_t *mlx, t_img *img);

void 	fill_background(t_game *data);
void 	render_map(t_game *data);

// for move function
void	moves_keyhook(mlx_key_data_t keydata, void *data);
void	remove_item(t_game *game, int y, int x);
t_game	*move_up(t_game *game);
t_game 	*move_down(t_game *game);
t_game 	*move_right(t_game *game);
t_game 	*move_left(t_game *game);

int		check_path(t_game *temp, size_t y, size_t x);
void	check_game_status(t_game *game);

void	print_moves_terminal(t_game *game);
void	print_moves_screen(t_game *game);

void	error_message(char *message);

int		row_count(char **map_array);

int only_char(char *str, char c);
#endif