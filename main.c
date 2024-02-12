/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:16:37 by mito              #+#    #+#             */
/*   Updated: 2024/02/12 13:16:42 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// this main func is for testing read_map func
int main(void) 
{
    char *file_path = "./maps/map1.ber"; // テストファイルのパスを指定
    char *map_str = read_map(file_path);
    char **map_array;
    if (map_str == NULL)
    {
        printf("File could not be read or does not exist.\n");
        return (1);
    }
	if (validate_map(map_str))
    {
        map_array = ft_split(map_str, '\n');
        // int k = 0;
        // while (map_array[k] != '\0')
        // {
        //     printf("map_array:%s\n", map_array[k]);
        //     k++;
        // }
    	printf("File content:\n%s\n", map_str); //delete it!
    }
    free(map_str);
    return (0);
}
