# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/25 15:34:29 by mromao-d          #+#    #+#              #
#    Updated: 2023/10/20 18:15:57 by mromao-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = *.c
LIBFT = libft/*.c
LIBFT_DIR = libft/
PRINTF = printf/*.c
PRINTF_DIR = printf/
MLX_LIB_DIR = .mlx/
MLX_INCLUDE = -I mlx
MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

all: $(NAME)

%.o: %.c
		$(CC) -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME): $(OBJS)
		@$(MAKE) -C $(MLX_LIB_DIR)
		@$(MAKE) -C $(LIBFT_DIR)
		@$(CC) $(OBJ)$(CFLAGS) $(SRC) libft/libft.a $(MLX_FLAGS)  -o $(NAME) 
# -fsanitize=address

valgrind: $(OBJS)
	@$(MAKE) -C $(MLX_LIB_DIR)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(OBJ)$(CFLAGS) $(SRC) libft/libft.a $(MLX_FLAGS)  -o $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "maps/test_maps/42.fdf"


run: $(NAME)
	./$(NAME) "maps/test_maps/42.fdf"

lldb: $(NAME)
	lldb ./$(NAME) "maps/test_maps/42.fdf"


clean:
	rm -rf $(OBJS)
	@$(MAKE) -C $(MLX_LIB_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) -C $(MLX_LIB_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re