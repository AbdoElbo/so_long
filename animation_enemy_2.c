/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_enemy_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:46:30 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/10/02 15:34:24 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collision_up_enemy(t_game *game, size_t i)
{
	int		new_x;
	int		new_y;
	size_t	n;

	new_x = game->e_an.i_e0->instances[i].x;
	new_y = game->e_an.i_e0->instances[i].y - 100;
	n = 0;
	while (n < game->i_wall->count)
	{
		if ((game->i_wall->instances[n].y == new_y)
			&& (game->i_wall->instances[n].x == new_x))
			return ;
		n++;
	}
	game->e_an.i_e0->instances[i].y -= 100;
}

void	collision_down_enemy(t_game *game, size_t i)
{
	int		new_x;
	int		new_y;
	size_t	n;

	new_x = game->e_an.i_e0->instances[i].x;
	new_y = game->e_an.i_e0->instances[i].y + 100;
	n = 0;
	while (n < game->i_wall->count)
	{
		if ((game->i_wall->instances[n].y == new_y)
			&& (game->i_wall->instances[n].x == new_x))
			return ;
		n++;
	}
	game->e_an.i_e0->instances[i].y += 100;
}

void	collision_right_enemy(t_game *game, size_t i)
{
	int		new_x;
	int		new_y;
	size_t	n;

	new_x = game->e_an.i_e0->instances[i].x + 100;
	new_y = game->e_an.i_e0->instances[i].y;
	n = 0;
	while (n < game->i_wall->count)
	{
		if ((game->i_wall->instances[n].y == new_y)
			&& (game->i_wall->instances[n].x == new_x))
			return ;
		n++;
	}
	game->e_an.i_e0->instances[i].x += 100;
}

void	collision_left_enemy(t_game *game, size_t i)
{
	int		new_x;
	int		new_y;
	size_t	n;

	new_x = game->e_an.i_e0->instances[i].x - 100;
	new_y = game->e_an.i_e0->instances[i].y;
	n = 0;
	while (n < game->i_wall->count)
	{
		if ((game->i_wall->instances[n].y == new_y)
			&& (game->i_wall->instances[n].x == new_x))
			return ;
		n++;
	}
	game->e_an.i_e0->instances[i].x -= 100;
}
