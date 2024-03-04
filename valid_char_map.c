/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_char_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:15:14 by mito              #+#    #+#             */
/*   Updated: 2024/03/04 10:32:01 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_e_and_p(char *map_str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map_str[i] != '\0')
	{
		if (map_str[i] == c)
			count++;
		i++;
	}
	if (count == 1)
		return (1); // there is only one Exit/Starting point
	return (0); // thi is invalid case. there is more than one Exit and Starting point or there us none
}

static int	is_valid_char(char *map_str)
{
	int	i;

	i = 0;
	while (map_str[i] != '\0')
	{
		if (map_str[i] != 'E' && map_str[i] != 'P' && map_str[i] != 'C' 
			&& map_str[i] != '1' && map_str[i] != '0' && map_str[i] != '\n')
			return (0); // if it's false = it contains invalid char
		i++;
	}
	return (1); // if it's true = there is no invalid char
}

static int	contain_item(char *map_str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map_str[i] != '\0')
	{
		if (map_str[i] == c) // if it's true = nesessary char found
			count++;
		i++;
	}
	if (count == 0) // no item
		return (0);
	else //there is at least one item
		return (1);
}

void	valid_char_map(char *map_str)
{
	if (!(check_e_and_p(map_str, 'E')))
		error_message("a number of E has to be 1");
	if (!(check_e_and_p(map_str, 'P')))
		error_message("a number of P has to be 1");
	if (!(contain_item(map_str, 'C')))
		error_message("Your map doesn't have any items");
	if (!(is_valid_char(map_str)))
		error_message("Your map contains invalid chars");
}
