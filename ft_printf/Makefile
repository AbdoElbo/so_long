# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelbouaz <aelbouaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 16:20:34 by aelbouaz          #+#    #+#              #
#    Updated: 2025/05/20 17:54:24 by aelbouaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

PRINTF_SRCS = ft_printf.c check_char.c check_intd.c check_inti.c \
	check_string.c check_pointer.c check_hexa_upper.c check_hexa_lower.c \
	check_unsign_int.c check_percent.c

PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

NAME = libftprintf.a
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

CC = cc

HEADERS = ft_printf.h $(LIBFT_DIR)libft.h

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(PRINTF_OBJS)
	cp $(LIBFT) $(NAME)
	ar rcsUu $(NAME) $(PRINTF_OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(PRINTF_OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) -o test test.c -L. -lftprintf && ./test

.PHONY: all clean fclean re test
