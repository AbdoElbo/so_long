/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:17:46 by aelbouaz          #+#    #+#             */
/*   Updated: 2025/10/03 14:24:48 by aelbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include "mlx42/include/MLX42/MLX42.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <sys/time.h>

# define BUFFER_SIZE 200
# define MAX_WIDTH 3840
# define MAX_HEIGHT 2160

typedef enum e_movement
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NONE
}	t_movement;

typedef enum s_coin_anime
{
	ZERO,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE
}	t_coin_anime;

typedef struct s_player_animation
{
	long long		start_time;
	long long		last_time;
	long long		current;
	long long		delta;
	long long		elapsed;
	int				current_frame;
	mlx_image_t		*i_p0;
	mlx_image_t		*i_p1;
	mlx_image_t		*i_p2;
	mlx_image_t		*i_p3;
}	t_player_animation;

typedef struct s_coin_animation
{
	long long		start_time;
	long long		last_time;
	long long		current;
	long long		elapsed;
	mlx_image_t		*i_c0;
	mlx_image_t		*i_c1;
	mlx_image_t		*i_c2;
	mlx_image_t		*i_c3;
	mlx_image_t		*i_c4;
	mlx_image_t		*i_c5;
	t_coin_anime	current_coin;
}	t_coin_animation;

typedef struct s_enemy_animation
{
	long long		start_time;
	long long		last_time;
	long long		current;
	long long		delta;
	long long		elapsed;
	mlx_image_t		*i_e0;
}	t_enemy_animation;

typedef struct s_textures
{
	mlx_texture_t	*t_wall;
	mlx_texture_t	*t_enemy;
	mlx_texture_t	*t_exit;
	mlx_texture_t	*t_exit_o;
	mlx_texture_t	*t_p0;
	mlx_texture_t	*t_p1;
	mlx_texture_t	*t_p2;
	mlx_texture_t	*t_p3;
	mlx_texture_t	*t_c0;
	mlx_texture_t	*t_c1;
	mlx_texture_t	*t_c2;
	mlx_texture_t	*t_c3;
	mlx_texture_t	*t_c4;
	mlx_texture_t	*t_c5;
	mlx_texture_t	*t_e0;
	mlx_texture_t	*t_e1;
	mlx_texture_t	*t_e2;
	mlx_texture_t	*t_e3;
	mlx_texture_t	*t_wasted;
	mlx_texture_t	*t_passed;

}	t_textures;

typedef struct s_game
{
	mlx_t				*mlx;
	char				*str1;
	char				*str2;
	mlx_image_t			*text_image_1;
	mlx_image_t			*text_image_2;
	mlx_image_t			*i_wall;
	mlx_image_t			*i_exit;
	mlx_image_t			*i_exit_o;
	mlx_image_t			*i_passed;
	mlx_image_t			*i_wasted;
	t_textures			textures;
	t_player_animation	p_an;
	t_coin_animation	c_an;
	t_enemy_animation	e_an;
	int					enemy_move_allowed;
	int					status;
	int					height;
	int					width;
	int					fd;
	size_t				coins;
	size_t				move_count;
	t_movement			current_move;
}	t_game;

int			error_check(int argc, char *argv);
int			check_arg(char *str);
int			map_validity(char *map);
int			components_exist(char *map);
int			map_is_rectangular(char *map);
int			horizontally_enclosed(char *map);
int			vertically_enclosed(char *map);
int			map_size(t_game game);
int			path_validity(char *map);

int			load_map_and_components(t_game *game, char **map,
				t_textures *textures);
void		init_vars(t_game *game);
int			init_map(int argc, char *argv, t_game *game, char **map);
int			map_rendering_1(t_game *game, t_textures *textures);
int			map_rendering_2(t_game *game, t_textures *textures);
int			player_rendering(t_game *game, t_textures *textures);
int			coin_rendering_1(t_game *game, t_textures *textures);
int			coin_rendering_2(t_game *game, t_textures *textures);

int			read_into_map(char **map, int fd);
int			width_size(char *map);
int			height_size(char *map);

int			load_walls(t_game *game, char *map);
int			load_player(t_game *game, char *map);
int			load_collect(t_game *game, char *map);
int			load_exit(t_game *game, char *map);
int			load_exit_open(t_game *game, char *map);
int			load_enemies(t_game *game, char *map);

void		collision_up(t_game *game);
void		collision_down(t_game *game);
void		collision_right(t_game *game);
void		collision_left(t_game *game);

void		collision_collect(t_game *game);
void		collision_exit(t_game *game);
void		collision_enemy(t_game *game);

int			player_index(char *map, int c);
void		flood_fill(char *map, int i, int width);
int			updated_map(char *map_copy);
int			trap_player(t_game *game);

void		ft_cleanup(t_game *game, t_textures *textures);
void		ft_cleanup_1(t_textures *textures);
void		ft_cleanup_2(t_textures *textures);
void		disable_player_instances(t_game *game);

void		player_animation(t_game *game);
void		animation_up_down(t_game *game, int x, int y, int dir);
void		moving_up(t_game *game);
void		moving_down(t_game *game);
void		animation_right_left(t_game *game, int x, int y, int dir);
void		moving_right(t_game *game);
void		moving_left(t_game *game);

long long	get_time_in_ms(void);

int			load_all_coins(t_game *game);
int			load_coin_pics(t_game *game, t_textures *textures);
void		disable_all_coins(t_game *game);
void		coin_animation(t_game *game);
void		disable_coins_at_instance(t_game *game, size_t i);
void		coin_animation_1(t_game *game, mlx_image_t *i_c,
				size_t i, t_coin_anime state);

void		enemy_animation(t_game *game);
void		collision_up_enemy(t_game *game, size_t i);
void		collision_down_enemy(t_game *game, size_t i);
void		collision_right_enemy(t_game *game, size_t i);
void		collision_left_enemy(t_game *game, size_t i);
int			success_failed(t_game *game);

#endif
