/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:57:44 by mito              #+#    #+#             */
/*   Updated: 2024/02/27 14:27:26 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_ber(char *file_name)
{
    int len;
    char *format;

    len = ft_strlen(file_name);
    format = ".ber";
    //if (len > 4) // これいるか？
    len = ft_strlen(file_name) - 4;
    if (ft_strncmp(&file_name[len], format, 4) == 0)
        return (1); // yes, it's .ber
    else
        return (0);  // no, file name is not .ber
        
}

t_game *init_map_data(char *argv) 
{
    char *map_str;
    char **map_array;
    t_game *data;

    map_str = read_map(argv);
    if (map_str == NULL)
    {
        printf("File could not be read or does not exist.\n");
        exit (1); // this one is a temporaly solution, replace it with something
    }
    
    map_array = ft_split(map_str, '\n');
	if (valid_char_map(map_str))
        printf("map char is valid\n"); //delete it!
    if (valid_shape_map(map_array))
        printf("map shape is valid\n"); //delete it!
    else
    {
        printf("map shape is invalid\n"); //delete it!
        exit (0);
    }
    // printf("File content:\n%s\n", map_str); //delete it!
    data = init_game_struct(map_array);
    //ft_flood_fill(data); // this is broken
    free(map_str);

    return (data);
}