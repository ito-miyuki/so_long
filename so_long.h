#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

#define WIDTH 256
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
} t_img;

typedef struct s_game
{
	//void 	*mlx;
	char	**grid;
	size_t	width;
	size_t	height;
	t_img	*img;
	mlx_t	*mlx;
} t_game;

//int	main(void);
int		main(int argc, char **argv);
t_game 	*init_map_data(char *argv);
char	*read_map(char *map);
int		valid_char_map(char *map_str);
int		valid_shape_map(char **map_array);
int		is_ber(char *file_name);
t_game *init_game_struct(char **map_array);

void 	image_select(t_game *data, size_t y, size_t x);
t_img	*init_img_struct(mlx_t *mlx);

t_img	*load_floor_texture(mlx_t *mlx, t_img *img);
t_img	*load_player_texture(mlx_t *mlx, t_img *img);
t_img 	*load_grass_texture(mlx_t *mlx, t_img *img);
t_img 	*load_item_texture(mlx_t *mlx, t_img *img);
t_img *load_exit_texture(mlx_t *mlx, t_img *img);

void 	fill_background(t_game *data);
void 	render_map(t_game *data);
#endif