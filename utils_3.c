/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:20:19 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/10/03 13:09:59 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

long long	get_time_in_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	disable_player_instances(t_game *game)
{
	if (game->p_an.i_p1)
		game->p_an.i_p1->instances[0].enabled = false;
	if (game->p_an.i_p2)
		game->p_an.i_p2->instances[0].enabled = false;
	if (game->p_an.i_p3)
		game->p_an.i_p3->instances[0].enabled = false;
}

void	init_vars(t_game *game)
{
	game->coins = 0;
	game->move_count = 0;
	game->p_an.current_frame = 1;
	game->current_move = NONE;
	game->c_an.current_coin = ZERO;
	game->enemy_move_allowed = 1;
	game->p_an.start_time = get_time_in_ms();
	game->p_an.last_time = game->p_an.start_time;
	game->c_an.start_time = get_time_in_ms();
	game->c_an.last_time = game->c_an.start_time;
	game->e_an.start_time = get_time_in_ms();
	game->e_an.last_time = game->e_an.start_time;
}

int	map_size(t_game game)
{
	if (game.height > MAX_HEIGHT)
		return (ft_printf("Max Height Reached, Try a smaller Map"), 0);
	if (game.width > MAX_WIDTH)
		return (ft_printf("Max width Reached, Try a smaller Map"), 0);
	return (1);
}
