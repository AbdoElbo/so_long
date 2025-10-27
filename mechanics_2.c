/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanics_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:20:16 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/10/06 13:47:34 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collision_collect(t_game *game)
{
	size_t	i;
	int		new_x;
	int		new_y;

	i = 0;
	new_x = game->p_an.i_p0->instances[0].x;
	new_y = game->p_an.i_p0->instances[0].y;
	while (i < game->c_an.i_c0->count)
	{
		if ((new_x == game->c_an.i_c0->instances[i].x)
			&& (new_y == game->c_an.i_c0->instances[i].y))
		{
			game->c_an.i_c0->instances[i].enabled = false;
			game->c_an.i_c0->instances[i].x -= 2 * game->width;
			game->coins++;
			disable_coins_at_instance(game, i);
			ft_printf("coins acquired: %d\n", game->coins);
		}
		i++;
	}
	if (game->coins == game->c_an.i_c0->count)
	{
		game->i_exit_o->instances->enabled = true;
		game->i_exit->instances->enabled = false;
	}
}

void	disable_coins_at_instance(t_game *game, size_t i)
{
	game->c_an.i_c0->instances[i].x -= 2 * game->width;
	game->c_an.i_c1->instances[i].x -= 2 * game->width;
	game->c_an.i_c2->instances[i].x -= 2 * game->width;
	game->c_an.i_c3->instances[i].x -= 2 * game->width;
	game->c_an.i_c4->instances[i].x -= 2 * game->width;
	game->c_an.i_c5->instances[i].x -= 2 * game->width;
}

void	collision_exit(t_game *game)
{
	int		new_x;
	int		new_y;

	new_x = game->p_an.i_p0->instances[0].x;
	new_y = game->p_an.i_p0->instances[0].y;
	if ((new_x == game->i_exit->instances[0].x)
		&& (new_y == game->i_exit->instances[0].y))
	{
		if (game->coins == game->c_an.i_c0->count)
		{
			game->status = 1;
			game->enemy_move_allowed = 0;
			trap_player(game);
			game->p_an.i_p0->instances[0].enabled = false;
			disable_player_instances(game);
			ft_printf("CONGRATULATIONS!!\n");
		}
		else
			ft_printf("Coins still need to be collected\n");
	}
	game->p_an.start_time = game->p_an.current;
	game->p_an.last_time = game->p_an.current;
	game->current_move = NONE;
}

void	collision_enemy(t_game *game)
{
	int		new_x;
	int		new_y;
	size_t	i;

	new_x = game->p_an.i_p0->instances[0].x;
	new_y = game->p_an.i_p0->instances[0].y;
	i = 0;
	while (i < game->e_an.i_e0->count)
	{
		if ((new_x == game->e_an.i_e0->instances[i].x)
			&& (new_y == game->e_an.i_e0->instances[i].y))
		{
			game->status = 0;
			trap_player(game);
			game->enemy_move_allowed = 0;
			game->p_an.i_p0->instances[0].enabled = false;
			disable_player_instances(game);
			ft_printf("U LOST!!\n");
		}
		i++;
	}
}

int	trap_player(t_game *game)
{
	int	width;

	width = game->width * 2;
	if ((mlx_image_to_window(game->mlx, game->i_wall, width, 0) < 0))
		return (0);
	if ((mlx_image_to_window(game->mlx, game->i_wall, width + 100, 100) < 0))
		return (0);
	if ((mlx_image_to_window(game->mlx, game->i_wall, width - 100, 100) < 0))
		return (0);
	if ((mlx_image_to_window(game->mlx, game->i_wall, width, 200) < 0))
		return (0);
	game->i_wall->instances[game->i_wall->count - 1].enabled = false;
	game->i_wall->instances[game->i_wall->count - 2].enabled = false;
	game->i_wall->instances[game->i_wall->count - 3].enabled = false;
	game->i_wall->instances[game->i_wall->count - 4].enabled = false;
	game->p_an.i_p0->instances->x = game->width * 2;
	game->p_an.i_p0->instances->y = 100;
	game->p_an.i_p0->instances->enabled = false;
	if (!success_failed(game))
		return (0);
	return (1);
}
