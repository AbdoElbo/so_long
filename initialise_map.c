/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:37:49 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/10/06 15:59:12 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_map(int argc, char *argv, t_game *game, char **map)
{
	char	*map_copy;

	if (!error_check(argc, argv))
		return (0);
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		return (ft_printf("Error:\nMap file doesn't exist\n"), 0);
	if (!read_into_map(map, game->fd))
		return (0);
	game->width = width_size(*map);
	game->height = height_size(*map);
	if (!map_size(*game))
		return (0);
	if (!map_validity(*map))
		return (0);
	map_copy = ft_strdup(*map);
	if (!map_copy)
		return (ft_printf("Error:\nAllocation failed (map_copy)\n"), 0);
	flood_fill(map_copy, player_index(*map, 'P'), game->width / 100);
	if (!updated_map(map_copy))
		return (free(map_copy), 0);
	return (free(map_copy), 1);
}

int	load_map_and_components(t_game *game, char **map, t_textures *textures)
{
	game->mlx = mlx_init(game->width, game->height, "My Awesome Game 🦎", 0);
	if (!game->mlx)
		return (ft_printf("Error:\nMlx initialization failed"), 0);
	if (!map_rendering_1(game, textures))
		return (ft_printf("Error:\nCouldn't convert map textures"), 0);
	if (!map_rendering_2(game, textures))
		return (ft_printf("Error:\nCouldn't convert map textures"), 0);
	if (!load_walls(game, *map))
		return (ft_printf("Error:\nCouldn't load wall image to window"), 0);
	if (!load_exit(game, *map) || !load_exit_open(game, *map))
		return (ft_printf("Error:\nCouldn't load exit image to window"), 0);
	if (!load_player(game, *map))
		return (ft_printf("Error:\nCouldn't load player image to window"), 0);
	if (!load_collect(game, *map))
		return (ft_printf("Error:\nCouldn't load coin image to window"), 0);
	if (!load_enemies(game, *map))
		return (ft_printf("Error:\nCouldn't load enemy image to window"), 0);
	return (1);
}
