/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_shape_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:14:40 by mito              #+#    #+#             */
/*   Updated: 2024/03/07 15:10:44 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangle(char **map_array)
{
	int		i;
	size_t	first_str;

	i = 1;
	first_str = ft_strlen(map_array[0]);
	while (map_array[i] != '\0')
	{
		if (first_str != ft_strlen(map_array[i]))
			return (0);
		i++;
	}
	return (1);
}

int	only_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

 /* what if the map is like this? is it considered as closed/surrounded by wall? 
  1111111111
  1E0000C001
  10000C0P11
  1111111110
 */

void	valid_shape_map(char **map_array)
{
	if (!(is_rectangle(map_array)))
		error_message("map is not a rectangle");
	if (!(is_wall(map_array)))
		error_message("map is not surrounded by wall");
}
