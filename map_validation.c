/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:16:37 by mito              #+#    #+#             */
/*   Updated: 2024/02/16 14:39:35 by mito             ###   ########.fr       */
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

int validate_map(char *argv) 
{
    char *map_str;
    char **map_array;
    t_game *data;

    map_str = read_map(argv);
    map_array = ft_split(map_str, '\n');
    if (map_str == NULL)
    {
        printf("File could not be read or does not exist.\n");
        return (1);
    }
	if (valid_char_map(map_str))
        printf("map char is valid\n"); //delete it!
    if (valid_shape_map(map_array))
        printf("map shape is valid"); //delete it!
    else
        printf("map is invalid\n"); //delete it!
    printf("File content:\n%s\n", map_str); //delete it!
    free(map_str);
    return (0);
}
