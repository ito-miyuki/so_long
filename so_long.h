#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "libft/libft.h"

typedef struct s_game
{
	char	**grid;
	int		width;
	int		height;
} t_game

//int	main(void);
int		main(int argc, char **argv);
int 	validate_map(char *argv);
char	*read_map(char *map);
int		valid_char_map(char *map_str);
int		valid_shape_map(char **map_array);
int		is_ber(char *file_format);

#endif