/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_char_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:15:14 by mito              #+#    #+#             */
/*   Updated: 2024/02/16 15:26:36 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int check_e_and_p(char *map_str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (map_str[i] != '\0')
	{
		if (map_str[i] == c)
			count++;
		i++;
	}
	/*
	//use this one↓
	if (count == 1)
		return (1); // there is only one Exit and Starting point
	else if (count == 0)
		return (0);
	else
		ft_printf("Error\n");
	return (0); // there is more than one Exit and Starting point
	//use this one below↓
	*/
	if (count == 1)
	 	return (1);
	 else if (count == 0)
	 {
		printf("E or P is missing\n");
	 	return (0);
	 }
	else
	 {
		ft_printf("Error\n"); // there is more than one E/P
	 	return (0);
	 }
	// for testing
}

static int is_valid_char(char *map_str)
{
	int i;
	i = 0;
	while (map_str[i] != '\0')
	{
		if (map_str[i] != 'E' && map_str[i] != 'P' && map_str[i] != 'C' 
			&& map_str[i] != '1' && map_str[i] != '0' && map_str[i] != '\n')
			return (0); // if it's false = it contains invalid char
		i++;
	}
	printf("great, there is no invalid char\n");
	return (1); // if it's true = there is no invalid char
}

static int contain_item(char *map_str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (map_str[i] != '\0')
	{
		if (map_str[i] == c) // if it's true = nesessary char found
			count++;
		i++;
	}
	if (count == 0) // no item
	{
		printf("Error! item is missing\n");
	 	return (0);
	}
	else //there is at least one item
		return (1);
}


int valid_char_map(char *map_str)
{
	if (check_e_and_p(map_str, 'E') && check_e_and_p(map_str, 'P')
		&& contain_item(map_str, 'C') && is_valid_char(map_str))
		return (1);
	else
		printf("Error! Map is invalid\n"); 
	return (0);
}
