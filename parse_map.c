/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:29:01 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/10/02 12:35:41 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_walls(t_game *game, char *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (map[i])
	{
		if (map[i] == '1')
		{
			if ((mlx_image_to_window(game->mlx, game->i_wall, x, y) < 0))
				return (0);
			x += 100;
		}
		if (map[i] == '0' || map[i] == 'C' || map[i] == 'E'
			|| map[i] == 'P' || map[i] == 'e')
			x += 100;
		if (map[i++] == '\n')
		{
			x = 0;
			y += 100;
		}
	}
	return (1);
}

int	load_player(t_game *game, char *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (map[i])
	{
		if (map[i] == 'P')
		{
			if ((mlx_image_to_window(game->mlx, game->p_an.i_p0, x, y) < 0))
				return (0);
			x += 100;
		}
		if (map[i] == '1' || map[i] == '0' || map[i] == 'C'
			|| map[i] == 'E' || map[i] == 'e')
			x += 100;
		if (map[i++] == '\n')
		{
			x = 0;
			y += 100;
		}
	}
	return (1);
}

int	load_collect(t_game *game, char *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (map[i])
	{
		if (map[i] == 'C')
		{
			if ((mlx_image_to_window(game->mlx, game->c_an.i_c0, x, y) < 0))
				return (0);
			x += 100;
		}
		if (map[i] == '1' || map[i] == '0' || map[i] == 'P'
			|| map[i] == 'E' || map[i] == 'e')
			x += 100;
		if (map[i++] == '\n')
		{
			x = 0;
			y += 100;
		}
	}
	return (1);
}

int	load_exit(t_game *game, char *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (map[i])
	{
		if (map[i] == 'E')
		{
			if ((mlx_image_to_window(game->mlx, game->i_exit, x, y) < 0))
				return (0);
			x += 100;
		}
		if (map[i] == '1' || map[i] == '0' || map[i] == 'C'
			|| map[i] == 'P' || map[i] == 'e')
			x += 100;
		if (map[i++] == '\n')
		{
			x = 0;
			y += 100;
		}
	}
	return (1);
}

int	load_exit_open(t_game *game, char *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (map[i])
	{
		if (map[i] == 'E')
		{
			if ((mlx_image_to_window(game->mlx, game->i_exit_o, x, y) < 0))
				return (0);
			x += 100;
		}
		if (map[i] == '1' || map[i] == '0' || map[i] == 'C'
			|| map[i] == 'P' || map[i] == 'e')
			x += 100;
		if (map[i++] == '\n')
		{
			x = 0;
			y += 100;
		}
	}
	return (game->i_exit_o->instances[0].enabled = false, 1);
}
