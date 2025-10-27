/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:14:50 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/10/06 13:08:36 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_moves_count(t_game *game)
{
	char	*str;
	char	*num;

	num = ft_itoa(game->move_count);
	if (!num)
		return (0);
	str = ft_strdup("Moves count: ");
	if (!str)
		return (free(num), 0);
	game->str1 = ft_strjoin(str, num);
	free(num);
	free(str);
	if (!game->str1)
		return (0);
	if (game->text_image_1)
		mlx_delete_image(game->mlx, game->text_image_1);
	game->text_image_1 = mlx_put_string(game->mlx, game->str1, 25, 25);
	free(game->str1);
	mlx_set_instance_depth(game->text_image_1->instances, 10);
	return (1);
}

int	display_coins_acquired(t_game *game)
{
	char	*str;
	char	*num;

	num = ft_itoa(game->coins);
	if (!num)
		return (0);
	str = ft_strdup("coins acquired: ");
	if (!str)
		return (free(num), 0);
	game->str2 = ft_strjoin(str, num);
	free(num);
	free(str);
	if (!game->str2)
		return (0);
	if (game->text_image_2)
		mlx_delete_image(game->mlx, game->text_image_2);
	game->text_image_2 = mlx_put_string(game->mlx, game->str2, 25, 50);
	free(game->str2);
	mlx_set_instance_depth(game->text_image_2->instances, 10);
	return (1);
}

void	ft_hook(void *param)
{
	t_game		*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (!display_moves_count(game))
		return ;
	if (!display_coins_acquired(game))
		return ;
	player_animation(game);
	coin_animation(game);
	enemy_animation(game);
	collision_enemy(game);
}

int	main(int argc, char *argv[])
{
	t_game			game;
	char			*map;
	t_textures		textures;

	map = ft_strdup("");
	if (!map)
		return (ft_printf("Error:\nAllocation failed (map)\n"), 1);
	if (!init_map(argc, argv[1], &game, &map))
		return (free(map), 1);
	init_vars(&game);
	if (!load_map_and_components(&game, &map, &textures))
		return (ft_cleanup(&game, &textures), free(map), 1);
	if (!player_rendering(&game, &textures))
		return (ft_cleanup(&game, &textures), free(map), 1);
	if (!load_coin_pics(&game, &textures))
		return (ft_cleanup(&game, &textures), free(map), 1);
	mlx_loop_hook(game.mlx, &ft_hook, &game);
	mlx_loop(game.mlx);
	free(map);
	return (ft_cleanup(&game, &textures), 0);
}
