/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:56:21 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/10/03 14:21:09 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_rendering_1(t_game *game, t_textures *textures)
{
	textures->t_wall = mlx_load_png("./textures/wall.png");
	if (!textures->t_wall)
		return (ft_printf("Error: \nWall png not found or invalid"), 0);
	game->i_wall = mlx_texture_to_image(game->mlx, textures->t_wall);
	if (!game->i_wall)
		return (ft_printf("Error: \nCouldn't convert texture to image"), 0);
	textures->t_p0 = mlx_load_png("./textures/player_idle.png");
	if (!textures->t_p0)
		return (ft_printf("Error: \nPlayer png not found or invalid"), 0);
	game->p_an.i_p0 = mlx_texture_to_image(game->mlx, textures->t_p0);
	if (!game->p_an.i_p0)
		return (ft_printf("Error: \nCouldn't convert texture to image"), 0);
	textures->t_c0 = mlx_load_png("./textures/coin_6.png");
	if (!textures->t_c0)
		return (ft_printf("Error: \nCollectible png not found or invalid"), 0);
	game->c_an.i_c0 = mlx_texture_to_image(game->mlx, textures->t_c0);
	if (!game->c_an.i_c0)
		return (ft_printf("Error: \nCouldn't convert texture to image"), 0);
	textures->t_e0 = mlx_load_png("./textures/enemy_0.png");
	if (!textures->t_e0)
		return (ft_printf("Error: \nenemy_0 png not found or invalid"), 0);
	game->e_an.i_e0 = mlx_texture_to_image(game->mlx, textures->t_e0);
	if (!game->e_an.i_e0)
		return (ft_printf("Error: \nCouldn't convert texture to image"), 0);
	return (1);
}

int	map_rendering_2(t_game *game, t_textures *textures)
{
	textures->t_exit = mlx_load_png("./textures/exitt.png");
	if (!textures->t_exit)
		return (ft_printf("Error: \nExit png not found or invalid"), 0);
	game->i_exit = mlx_texture_to_image(game->mlx, textures->t_exit);
	if (!game->i_exit)
		return (ft_printf("Error: \nCouldn't convert texture to image"), 0);
	textures->t_exit_o = mlx_load_png("./textures/exit_open.png");
	if (!textures->t_exit_o)
		return (ft_printf("Error: \nExit png not found or invalid"), 0);
	game->i_exit_o = mlx_texture_to_image(game->mlx, textures->t_exit_o);
	if (!game->i_exit_o)
		return (ft_printf("Error: \nCouldn't convert texture to image"), 0);
	textures->t_wasted = mlx_load_png("./textures/wasted.png");
	if (!textures->t_wasted)
		return (ft_printf("Error: \ncoin_4 png not found or invalid"), 0);
	game->i_wasted = mlx_texture_to_image(game->mlx, textures->t_wasted);
	if (!game->i_wasted)
		return (ft_printf("Error: \nCouldn't convert texture to image"), 0);
	textures->t_passed = mlx_load_png("./textures/passed.png");
	if (!textures->t_passed)
		return (ft_printf("Error: \ncoin_4 png not found or invalid"), 0);
	game->i_passed = mlx_texture_to_image(game->mlx, textures->t_passed);
	if (!game->i_passed)
		return (ft_printf("Error: \nCouldn't convert texture to image"), 0);
	return (1);
}

int	player_rendering(t_game *game, t_textures *textures)
{
	textures->t_p1 = mlx_load_png("./textures/player_move1.png");
	if (!textures->t_p1)
		return (ft_printf("Error: \np_animation png not found or invalid"), 0);
	game->p_an.i_p1 = mlx_texture_to_image(game->mlx, textures->t_p1);
	if (!game->p_an.i_p1)
		return (ft_printf("Error: \nCouldn't convert texture to image"), 0);
	textures->t_p2 = mlx_load_png("./textures/player_move2.png");
	if (!textures->t_p2)
		return (ft_printf("Error: \np_animation png not found or invalid"), 0);
	game->p_an.i_p2 = mlx_texture_to_image(game->mlx, textures->t_p2);
	if (!game->p_an.i_p2)
		return (ft_printf("Error: \nCouldn't convert texture to image"), 0);
	textures->t_p3 = mlx_load_png("./textures/player_move3.png");
	if (!textures->t_p3)
		return (ft_printf("Error: \np_animation png not found or invalid"), 0);
	game->p_an.i_p3 = mlx_texture_to_image(game->mlx, textures->t_p3);
	if (!game->p_an.i_p3)
		return (ft_printf("Error: \nCouldn't convert texture to image"), 0);
	if ((mlx_image_to_window(game->mlx, game->p_an.i_p1, -100, 0) < 0))
		return (ft_printf("Error: \nCouldn't load p_animation image 1"), 0);
	if ((mlx_image_to_window(game->mlx, game->p_an.i_p2, -100, 0) < 0))
		return (ft_printf("Error: \nCouldn't load p_animation image 2"), 0);
	if ((mlx_image_to_window(game->mlx, game->p_an.i_p3, -100, 0) < 0))
		return (ft_printf("Error: \nCouldn't load p_animation image 3"), 0);
	return (1);
}

int	coin_rendering_1(t_game *game, t_textures *textures)
{
	textures->t_c1 = mlx_load_png("./textures/coin_1.png");
	if (!textures->t_c1)
		return (ft_printf("Error: \n coin_1 png not found or invalid"), 0);
	game->c_an.i_c1 = mlx_texture_to_image(game->mlx, textures->t_c1);
	if (!game->c_an.i_c1)
		return (ft_printf("Error: \nCouldn't convert texture to image"), 0);
	textures->t_c2 = mlx_load_png("./textures/coin_2.png");
	if (!textures->t_c2)
		return (ft_printf("Error: \ncoin_2 png not found or invalid"), 0);
	game->c_an.i_c2 = mlx_texture_to_image(game->mlx, textures->t_c2);
	if (!game->c_an.i_c2)
		return (ft_printf("Error: \nCouldn't convert texture to image"), 0);
	textures->t_c3 = mlx_load_png("./textures/coin_3.png");
	if (!textures->t_c3)
		return (ft_printf("Error: \ncoin_3 png not found or invalid"), 0);
	game->c_an.i_c3 = mlx_texture_to_image(game->mlx, textures->t_c3);
	if (!game->c_an.i_c3)
		return (ft_printf("Error: \nCouldn't convert texture to image"), 0);
	return (1);
}

int	coin_rendering_2(t_game *game, t_textures *textures)
{
	textures->t_c4 = mlx_load_png("./textures/coin_4.png");
	if (!textures->t_c4)
		return (ft_printf("Error: \ncoin_4 png not found or invalid"), 0);
	game->c_an.i_c4 = mlx_texture_to_image(game->mlx, textures->t_c4);
	if (!game->c_an.i_c4)
		return (ft_printf("Error: \nCouldn't convert texture to image"), 0);
	textures->t_c5 = mlx_load_png("./textures/coin_5.png");
	if (!textures->t_c5)
		return (ft_printf("Error: \ncoin_5 png not found or invalid"), 0);
	game->c_an.i_c5 = mlx_texture_to_image(game->mlx, textures->t_c5);
	if (!game->c_an.i_c5)
		return (ft_printf("Error: \nCouldn't convert texture to image"), 0);
	return (1);
}
