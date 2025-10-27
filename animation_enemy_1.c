/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_enemy_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:11:14 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/10/03 13:10:44 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_animation(t_game *game)
{
	size_t	i;
	int		new_x;
	int		new_y;

	new_x = game->p_an.i_p0->instances[0].x;
	new_y = game->p_an.i_p0->instances[0].y;
	i = 0;
	game->e_an.current = get_time_in_ms();
	game->e_an.elapsed = game->e_an.current - game->e_an.last_time;
	if (game->e_an.elapsed >= 1000)
	{
		while (i < game->e_an.i_e0->count && game->enemy_move_allowed)
		{
			if (new_x < game->e_an.i_e0->instances[i].x)
				collision_left_enemy(game, i);
			else if (new_y < game->e_an.i_e0->instances[i].y)
				collision_up_enemy(game, i);
			else if (new_x > game->e_an.i_e0->instances[i].x)
				collision_right_enemy(game, i);
			else if (new_y > game->e_an.i_e0->instances[i].y)
				collision_down_enemy(game, i);
			game->e_an.last_time = game->e_an.current;
			i++;
		}
	}
}

int	load_enemies(t_game *game, char *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (map[i])
	{
		if (map[i] == 'e')
		{
			if ((mlx_image_to_window(game->mlx, game->e_an.i_e0, x, y) < 0))
				return (0);
			x += 100;
		}
		if (map[i] == '1' || map[i] == '0' || map[i] == 'P'
			|| map[i] == 'E' || map[i] == 'C')
			x += 100;
		if (map[i++] == '\n')
		{
			x = 0;
			y += 100;
		}
	}
	return (1);
}
