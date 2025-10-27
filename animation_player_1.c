/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_player_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:40:23 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/10/17 19:16:35 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_animation(t_game *game)
{
	if (game->current_move == NONE)
	{
		disable_player_instances(game);
		if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
			collision_up(game);
		else if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
			collision_down(game);
		else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
			collision_left(game);
		else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
			collision_right(game);
	}
	if (game->current_move == UP)
		moving_up(game);
	else if (game->current_move == DOWN)
		moving_down(game);
	else if (game->current_move == RIGHT)
		moving_right(game);
	else if (game->current_move == LEFT)
		moving_left(game);
}

void	animation_up_down(t_game *game, int x, int y, int dir)
{
	disable_player_instances(game);
	if (game->p_an.current_frame == 1)
	{
		game->p_an.i_p0->instances[0].enabled = false;
		game->p_an.i_p1->instances[0].x = x;
		game->p_an.i_p1->instances[0].y = y + (dir * 25);
		game->p_an.i_p1->instances[0].enabled = true;
	}
	else if (game->p_an.current_frame == 2)
	{
		game->p_an.i_p0->instances[0].enabled = false;
		game->p_an.i_p2->instances[0].x = x;
		game->p_an.i_p2->instances[0].y = y + (dir * 50);
		game->p_an.i_p2->instances[0].enabled = true;
	}
	else if (game->p_an.current_frame == 0)
	{
		game->p_an.i_p0->instances[0].enabled = false;
		game->p_an.i_p3->instances[0].x = x;
		game->p_an.i_p3->instances[0].y = y + (dir * 75);
		game->p_an.i_p3->instances[0].enabled = true;
	}
}

void	moving_up(t_game *game)
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
		animation_up_down(game, x, y, -1);
		game->p_an.current_frame = (game->p_an.current_frame + 1) % 3;
		game->p_an.last_time = game->p_an.current;
	}
	else if (game->p_an.elapsed >= 350 && game->p_an.current_frame == 1)
	{
		game->p_an.i_p0->instances->y -= 100;
		game->p_an.i_p0->instances[0].enabled = true;
		game->move_count++;
		ft_printf("Moves count :%d\n", game->move_count);
		collision_collect(game);
		collision_exit(game);
	}
}

void	moving_down(t_game *game)
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
		animation_up_down(game, x, y, +1);
		game->p_an.current_frame = (game->p_an.current_frame + 1) % 3;
		game->p_an.last_time = game->p_an.current;
	}
	else if (game->p_an.elapsed >= 350 && game->p_an.current_frame == 1)
	{
		game->p_an.i_p0->instances->y += 100;
		game->p_an.i_p0->instances[0].enabled = true;
		game->move_count++;
		ft_printf("Moves count :%d\n", game->move_count);
		collision_collect(game);
		collision_exit(game);
	}
}
