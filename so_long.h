#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "libft.h"

int		main(void);
int		validate_map(void);
char	*read_map(char *map);
int		valid_char_map(char *map_str);
int		valid_shape_map(char **map_array);

#endif