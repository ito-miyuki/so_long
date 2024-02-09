#include "so_long.h"

char *read_map(char *map)
{
	char	*line;
	char	*line_joint;
	int		fd;

	fd = open(map, O_RDONLY); //read a file, fd will be -1 if read fails
	line_joint = calloc(1, 1);
	if (!line_joint)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		line_joint = ft_strjoin(line_joint, line);
		free (line);
	}
	close (fd);
	return (line_joint);
}
