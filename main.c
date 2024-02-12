/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:16:37 by mito              #+#    #+#             */
/*   Updated: 2024/02/12 16:38:39 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// this main func is for testing read_map func
int main(void) 
{
    char *file_path = "./maps/map1.ber"; // テストファイルのパスを指定
    char *map_str = read_map(file_path);
    char **map_array;

    map_str = read_map(file_path);
    map_array = ft_split(map_str, '\n');
    if (map_str == NULL)
    {
        printf("File could not be read or does not exist.\n");
        return (1);
    }
	if (valid_char_map(map_str))
    {
        printf("map char is valid\n"); //delete it!
    	printf("File content:\n%s\n", map_str); //delete it!
    }
    if (valid_shape_map(map_array))
        printf("map shape is valid"); //delete it!
    else
        printf("map is invalid"); //delete it!
    
    free(map_str);
    return (0);
}
