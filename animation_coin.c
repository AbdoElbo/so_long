/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_coin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 20:12:11 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/10/01 17:57:42 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_coin_pics(t_game *game, t_textures *textures)
{
	if (!coin_rendering_1(game, textures))
		return (0);
	if (!coin_rendering_2(game, textures))
		return (0);
	if (!load_all_coins(game))
		return (0);
	return (1);
}

int	load_all_coins(t_game *game)
{
	size_t	i;
	int		x;
	int		y;

	i = 0;
	while (i < game->c_an.i_c0->count)
	{
		x = game->c_an.i_c0->instances[i].x;
		y = game->c_an.i_c0->instances[i].y;
		if (mlx_image_to_window(game->mlx, game->c_an.i_c1, x, y) < 0)
			return (0);
		if (mlx_image_to_window(game->mlx, game->c_an.i_c2, x, y) < 0)
			return (0);
		if (mlx_image_to_window(game->mlx, game->c_an.i_c3, x, y) < 0)
			return (0);
		if (mlx_image_to_window(game->mlx, game->c_an.i_c4, x, y) < 0)
			return (0);
		if (mlx_image_to_window(game->mlx, game->c_an.i_c5, x, y) < 0)
			return (0);
		i++;
	}
	return (1);
}

void	disable_all_coins(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->c_an.i_c0->count)
	{
		game->c_an.i_c0->instances[i].enabled = false;
		game->c_an.i_c1->instances[i].enabled = false;
		game->c_an.i_c2->instances[i].enabled = false;
		game->c_an.i_c3->instances[i].enabled = false;
		game->c_an.i_c4->instances[i].enabled = false;
		game->c_an.i_c5->instances[i].enabled = false;
		i++;
	}
}

void	coin_animation(t_game *game)
{
	size_t	i;

	game->c_an.current = get_time_in_ms();
	game->c_an.elapsed = game->c_an.current - game->c_an.last_time;
	i = 0;
	if (game->c_an.current_coin == ZERO && game->c_an.elapsed >= 200)
		coin_animation_1(game, game->c_an.i_c0, i, ZERO);
	else if (game->c_an.current_coin == ONE && game->c_an.elapsed >= 200)
		coin_animation_1(game, game->c_an.i_c1, i, ONE);
	else if (game->c_an.current_coin == TWO && game->c_an.elapsed >= 200)
		coin_animation_1(game, game->c_an.i_c2, i, TWO);
	else if (game->c_an.current_coin == THREE && game->c_an.elapsed >= 200)
		coin_animation_1(game, game->c_an.i_c3, i, THREE);
	else if (game->c_an.current_coin == FOUR && game->c_an.elapsed >= 200)
		coin_animation_1(game, game->c_an.i_c4, i, FOUR);
	else if (game->c_an.current_coin == FIVE && game->c_an.elapsed >= 200)
		coin_animation_1(game, game->c_an.i_c5, i, FIVE);
}

void	coin_animation_1(t_game *game, mlx_image_t *i_c,
		size_t i, t_coin_anime state)
{
	disable_all_coins(game);
	while (i < i_c->count)
	{
		i_c->instances[i].enabled = true;
		i++;
	}
	if (game->c_an.current_coin == FIVE)
		game->c_an.current_coin = ZERO;
	else
		game->c_an.current_coin = state + 1;
	game->c_an.last_time = game->c_an.current;
}
