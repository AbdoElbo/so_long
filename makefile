# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 16:20:34 by aelbouaz          #+#    #+#              #
#    Updated: 2025/10/02 16:10:20 by aelbouaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = cc

SO_LONG = so_long
SO_LONG_SRCS = so_long.c utils_1.c utils_2.c utils_3.c utils_4.c parse_map.c \
	initialise_map.c mechanics_1.c mechanics_2.c map_validity.c animation_player_1.c \
	animation_player_2.c animation_coin.c animation_enemy_1.c animation_enemy_2.c \
	rendering.c

SO_LONG_OBJ = $(SO_LONG_SRCS:.c=.o)

LIBFT_DIR = ft_printf/libft/
LIBFT = $(LIBFT_DIR)libft.a

PRINTF_DIR = ft_printf/
PRINTF = $(PRINTF_DIR)libftprintf.a

MLX42_DIR = mlx42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a
MLX42_INC = $(MLX42_DIR)/include

HEADERS = $(PRINTF_DIR)ft_printf.h $(LIBFT_DIR)libft.h $(MLX42_INC)/MLX42/MLX42.h

all: $(SO_LONG) $(MLX42_LIB)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(MLX42_LIB):
	cmake -B $(MLX42_DIR)/build $(MLX42_DIR)
	make -C $(MLX42_DIR)/build

$(SO_LONG): $(LIBFT) $(PRINTF) $(MLX42_LIB) $(SO_LONG_OBJ)
	$(CC) $(CFLAGS) -o $(SO_LONG) $(SO_LONG_OBJ) \
	-L$(PRINTF_DIR) -lftprintf \
	-L$(LIBFT_DIR) -lft \
	$(MLX42_LIB) -I$(MLX42_INC) -ldl -lglfw -pthread -lm

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX42_INC) -c $< -o $@

clean:
	make -C $(PRINTF_DIR) clean
	rm -rf $(MLX42_DIR)/build
	rm -f $(SO_LONG_OBJ)

fclean: clean
	make -C $(PRINTF_DIR) fclean
	rm -f $(SO_LONG)

re: fclean all

.PHONY: all clean fclean re
