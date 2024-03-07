/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:16:55 by mito              #+#    #+#             */
/*   Updated: 2024/03/07 10:37:57 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *read_map(char *map) // here it recieves argv[1]
{
	char	*line;
	char	*line_joint;
	int		fd;
	char	*temp;

	fd = open(map, O_RDONLY); //read a file, fd will be -1 if read fails
	if (fd == -1)
		error_message("read failed"); // modifiy message
	line_joint = ft_calloc(1, 1);
	if (!line_joint)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		temp = line_joint;
		line_joint = ft_strjoin(line_joint, line);
		if (!line_joint)
			return  (NULL);
		free (temp);
		free (line);
	}
	close (fd);
	return (line_joint);
}
