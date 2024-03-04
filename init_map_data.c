/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:57:44 by mito              #+#    #+#             */
/*   Updated: 2024/03/04 10:29:41 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber(char *file_name)
{
	int		len;
	char	*format;

	len = ft_strlen(file_name);
	format = ".ber";
	//if (len > 4) // これいるか？
	len = ft_strlen(file_name) - 4;
	if (ft_strncmp(&file_name[len], format, 4) == 0)
		return (1); // yes, it's .ber
	else
		return (0); // no, file name is not .ber 
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
	valid_shape_map(map_array);
	data = init_game_struct(map_array);
	ft_flood_fill(data);
	free(map_str);
	return (data);
}
