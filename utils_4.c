/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 20:31:13 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/10/06 15:56:46 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_cleanup(t_game *game, t_textures *textures)
{
	if (game->mlx)
	{
		ft_cleanup_1(textures);
		ft_cleanup_2(textures);
		mlx_terminate(game->mlx);
	}
	close(game->fd);
}

void	ft_cleanup_1(t_textures *textures)
{
	if (textures->t_wall)
		mlx_delete_texture(textures->t_wall);
	if (textures->t_exit)
		mlx_delete_texture(textures->t_exit);
	if (textures->t_exit_o)
		mlx_delete_texture(textures->t_exit_o);
	if (textures->t_p0)
		mlx_delete_texture(textures->t_p0);
	if (textures->t_p1)
		mlx_delete_texture(textures->t_p1);
	if (textures->t_p2)
		mlx_delete_texture(textures->t_p2);
	if (textures->t_p3)
		mlx_delete_texture(textures->t_p3);
}

void	ft_cleanup_2(t_textures *textures)
{
	if (textures->t_c0)
		mlx_delete_texture(textures->t_c0);
	if (textures->t_c1)
		mlx_delete_texture(textures->t_c1);
	if (textures->t_c2)
		mlx_delete_texture(textures->t_c2);
	if (textures->t_c3)
		mlx_delete_texture(textures->t_c3);
	if (textures->t_c4)
		mlx_delete_texture(textures->t_c4);
	if (textures->t_c5)
		mlx_delete_texture(textures->t_c5);
	if (textures->t_e0)
		mlx_delete_texture(textures->t_e0);
	if (textures->t_wasted)
		mlx_delete_texture(textures->t_wasted);
	if (textures->t_passed)
		mlx_delete_texture(textures->t_passed);
}
