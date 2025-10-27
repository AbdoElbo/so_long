/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanics_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:46:30 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/10/03 14:35:59 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collision_up(t_game *game)
{
	size_t	i;
	int		new_x;
	int		new_y;

	i = 0;
	new_x = game->p_an.i_p0->instances[0].x;
	new_y = game->p_an.i_p0->instances[0].y - 100;
	while (i < game->i_wall->count)
	{
		if ((game->i_wall->instances[i].y == new_y)
			&& (game->i_wall->instances[i].x == new_x))
			return ;
		i++;
	}
	game->current_move = UP;
}

void	collision_down(t_game *game)
{
	size_t	i;
	int		new_x;
	int		new_y;

	i = 0;
	new_x = game->p_an.i_p0->instances[0].x;
	new_y = game->p_an.i_p0->instances[0].y + 100;
	while (i < game->i_wall->count)
	{
		if ((game->i_wall->instances[i].y == new_y)
			&& (game->i_wall->instances[i].x == new_x))
			return ;
		i++;
	}
	game->current_move = DOWN;
}

void	collision_right(t_game *game)
{
	size_t	i;
	int		new_x;
	int		new_y;

	i = 0;
	new_x = game->p_an.i_p0->instances[0].x + 100;
	new_y = game->p_an.i_p0->instances[0].y;
	while (i < game->i_wall->count)
	{
		if ((game->i_wall->instances[i].y == new_y)
			&& (game->i_wall->instances[i].x == new_x))
			return ;
		i++;
	}
	game->current_move = RIGHT;
}

void	collision_left(t_game *game)
{
	size_t	i;
	int		new_x;
	int		new_y;

	i = 0;
	new_x = game->p_an.i_p0->instances[0].x - 100;
	new_y = game->p_an.i_p0->instances[0].y;
	while (i < game->i_wall->count)
	{
		if ((game->i_wall->instances[i].y == new_y)
			&& (game->i_wall->instances[i].x == new_x))
			return ;
		i++;
	}
	game->current_move = LEFT;
}

int	success_failed(t_game *game)
{
	int	x;
	int	y;

	x = (game->width / 2) - 200;
	y = game->height / 2 - 50;
	if (game->status)
	{
		if ((mlx_image_to_window(game->mlx, game->i_passed, x, y) < 0))
			return (0);
	}
	else
	{
		if ((mlx_image_to_window(game->mlx, game->i_wasted, x, y) < 0))
			return (0);
	}
	return (1);
}
