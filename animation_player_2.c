/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_player_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:16:23 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/10/17 19:16:30 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation_right_left(t_game *game, int x, int y, int dir)
{
	disable_player_instances(game);
	if (game->p_an.current_frame == 1)
	{
		game->p_an.i_p0->instances[0].enabled = false;
		game->p_an.i_p1->instances[0].x = x + (dir * 25);
		game->p_an.i_p1->instances[0].y = y;
		game->p_an.i_p1->instances[0].enabled = true;
	}
	else if (game->p_an.current_frame == 2)
	{
		game->p_an.i_p0->instances[0].enabled = false;
		game->p_an.i_p2->instances[0].x = x + (dir * 50);
		game->p_an.i_p2->instances[0].y = y;
		game->p_an.i_p2->instances[0].enabled = true;
	}
	else if (game->p_an.current_frame == 0)
	{
		game->p_an.i_p0->instances[0].enabled = false;
		game->p_an.i_p3->instances[0].x = x + (dir * 75);
		game->p_an.i_p3->instances[0].y = y;
		game->p_an.i_p3->instances[0].enabled = true;
	}
}

void	moving_right(t_game *game)
{
	int	x;
	int	y;

	x = game->p_an.i_p0->instances[0].x;
	y = game->p_an.i_p0->instances[0].y;
	game->p_an.current = get_time_in_ms();
	game->p_an.delta = game->p_an.current - game->p_an.last_time;
	game->p_an.elapsed = game->p_an.current - game->p_an.start_time;
	if (game->p_an.delta >= 100)
	{
		animation_right_left(game, x, y, 1);
		game->p_an.current_frame = (game->p_an.current_frame + 1) % 3;
		game->p_an.last_time = game->p_an.current;
	}
	else if (game->p_an.elapsed >= 350 && game->p_an.current_frame == 1)
	{
		game->p_an.i_p0->instances->x += 100;
		game->p_an.i_p0->instances[0].enabled = true;
		game->move_count++;
		ft_printf("Moves count :%d\n", game->move_count);
		collision_collect(game);
		collision_exit(game);
	}
}

void	moving_left(t_game *game)
{
	int	x;
	int	y;

	x = game->p_an.i_p0->instances[0].x;
	y = game->p_an.i_p0->instances[0].y;
	game->p_an.current = get_time_in_ms();
	game->p_an.delta = game->p_an.current - game->p_an.last_time;
	game->p_an.elapsed = game->p_an.current - game->p_an.start_time;
	if (game->p_an.delta >= 100)
	{
		animation_right_left(game, x, y, -1);
		game->p_an.current_frame = (game->p_an.current_frame + 1) % 3;
		game->p_an.last_time = game->p_an.current;
	}
	else if (game->p_an.elapsed >= 350 && game->p_an.current_frame == 1)
	{
		game->p_an.i_p0->instances->x -= 100;
		game->p_an.i_p0->instances[0].enabled = true;
		game->move_count++;
		ft_printf("Moves count :%d\n", game->move_count);
		collision_collect(game);
		collision_exit(game);
	}
}
