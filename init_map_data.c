/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:57:44 by mito              #+#    #+#             */
/*   Updated: 2024/03/08 17:01:12 by mito             ###   ########.fr       */
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
		error_message("map file has to be ***.ber"); // think about better message
	if (len == 4)
		error_message("map file is hidden file(1)"); // think about better message
	len = ft_strlen(file_name) - 4;
	if (file_name[len - 1] == '/')
		error_message("map file is hidden file(2)"); // think about better message
	if (ft_strncmp(&file_name[len], format, 4) != 0)
		error_message("map file has to be ***.ber");
}

static bool	is_map_too_big(char **map_array)
{
	int row;
	int col;

	row = row_count(map_array);
	col = ft_strlen(map_array[0]);

	if (col * PIXELS > 2500 || row * PIXELS > 1700)
		return (true);
	return (false);
}
t_game	*init_map_data(char *argv)
{
	char	*map_str;
	char	**map_array;
	t_game	*data;

	map_str = read_map(argv);
	if (map_str == NULL)
		exit(EXIT_FAILURE);
	map_array = ft_split(map_str, '\n');
	check_empty_map(map_str);
	valid_char_map(map_str);
	check_empty_line(map_str);
	valid_shape_map(map_array);
	if (is_map_too_big(map_array) == true)
	{
		free_grid(map_array);
		error_message("Map is too big.");
	}
	data = init_game_struct(map_array);
	ft_flood_fill(data);
	free(map_str);
	return (data);
}
