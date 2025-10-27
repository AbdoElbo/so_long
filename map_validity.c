/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekko <gekko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:40:58 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/10/01 22:09:25 by gekko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_validity(char *map)
{
	if (!components_exist(map))
	{
		ft_printf("Error :\nMISSING or DUPLICATED or UNKOWN COMPONENTS\n");
		return (0);
	}
	if (!map_is_rectangular(map))
	{
		ft_printf("Error :\nMAP SHAPE ERROR (not rectangular)\n");
		return (0);
	}
	if (!horizontally_enclosed(map))
	{
		ft_printf("Error :\nMAP ENCLOSURE ERROR (horizontally)\n");
		return (0);
	}
	if (!vertically_enclosed(map))
	{
		ft_printf("Error :\nMAP ENCLOSURE ERROR (vertically)\n");
		return (0);
	}
	return (1);
}

int	components_exist(char *map)
{
	int	i;
	int	p;
	int	c;
	int	e;

	i = 0;
	p = 0;
	c = 0;
	e = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			p++;
		else if (map[i] == 'C')
			c++;
		else if (map[i] == 'E')
			e++;
		else if (map[i] != '\n' && map[i] != '1'
			&& map[i] != '0' && map[i] != 'e')
			return (0);
		i++;
	}
	if (p != 1 || c < 1 || e != 1)
		return (0);
	return (1);
}

int	map_is_rectangular(char *map)
{
	int	i;
	int	first_len;
	int	sec_len;

	i = 0;
	first_len = -1;
	sec_len = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (first_len == -1)
				first_len = sec_len;
			else if (sec_len != first_len)
				return (0);
			sec_len = 0;
		}
		else
			sec_len++;
		i++;
	}
	if (sec_len > 0 && sec_len != first_len)
		return (0);
	return (1);
}

int	horizontally_enclosed(char *map)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '\n')
	{
		if (map[i] != '1')
			return (0);
		i++;
	}
	i = ft_strlen(map) - 1;
	while (i > 0 && map[i - 1] != '\n')
		i--;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	vertically_enclosed(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (map[i - 1] != '1')
				return (0);
			if (map[i + 1] != '1' && map[i + 1] != '\0')
				return (0);
		}
		i++;
	}
	return (1);
}
