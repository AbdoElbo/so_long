/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:29:01 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/10/09 13:40:11 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_index(char *map, int c)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

int	updated_map(char *map_copy)
{
	int	i;

	i = 0;
	while (map_copy[i])
	{
		if (map_copy[i] == 'C')
			return (ft_printf("Error:\nPath Invalid (coins unreachable)\n"), 0);
		if (map_copy[i] == 'E')
			return (ft_printf("Error:\nPath Invalid (EXIT unreachable)\n"), 0);
		else if (map_copy[i] != '1' && map_copy[i] != 'X' && map_copy[i] != 'e'
			&& map_copy[i] != '\n' && map_copy[i] != '0')
			return (ft_printf("Error:\nPath Invalid\n"), 0);
		i++;
	}
	return (1);
}

void	flood_fill(char *map, int i, int width)
{
	if (map[i] != 'P' && map[i] != '0' && map[i] != 'C'
		&& map[i] != 'E' && map[i] != 'e')
		return ;
	map[i] = 'X';
	flood_fill(map, i - 1, width);
	flood_fill(map, i + 1, width);
	flood_fill(map, i - (width + 1), width);
	flood_fill(map, i + (width + 1), width);
}
