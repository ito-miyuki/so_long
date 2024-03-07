/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:57:44 by mito              #+#    #+#             */
/*   Updated: 2024/03/07 15:29:13 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_empty_map(char *map_str)
{
	size_t	i;

	i = 0;
	if (!map_str[i])
		error_message("Map is empty");
}

static void	check_empty_line(char *map_str)
{
	size_t	i;

	i = 0;
	while (map_str[i])
	{
		if (map_str[0] == '\n'
			|| (map_str[i] == '\n' && map_str[i + 1] == '\n'))
			error_message("there are empty lines in the map");
		i++;
	}
}

void	is_ber(char *file_name)
{
	int		len;
	char	*format;

	len = ft_strlen(file_name);
	format = ".ber";
	if (len < 4)
		error_message("map file has to be ***.ber");
	len = ft_strlen(file_name) - 4;
	if (ft_strncmp(&file_name[len], format, 4) != 0)
		error_message("map file has to be ***.ber");
}

t_game	*init_map_data(char *argv)
{
	char	*map_str;
	char	**map_array;
	t_game	*data;

	map_str = read_map(argv);
	if (map_str == NULL)
		error_message("File could not be read or does not exist.\n");
	map_array = ft_split(map_str, '\n');
	valid_char_map(map_str);
	check_empty_map(map_str);
	check_empty_line(map_str);
	valid_shape_map(map_array);
	data = init_game_struct(map_array);
	ft_flood_fill(data);
	free(map_str);
	return (data);
}
