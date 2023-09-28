# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/25 15:34:29 by mromao-d          #+#    #+#              #
#    Updated: 2023/09/26 19:16:17 by mromao-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = *.c
LINE = get_next_line/*.c
LIBFT = libft/*.c
PRINTF = printf/*.c
MLX_LIB_DIR = .minilibx-linux/
MLX_INCLUDE = -I mlx_linux
MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) -C $(MLX_LIB_DIR)
#		$(CC) $(CFLAGS) -fsanitize=address $(SRC) $(LINE) $(LIBFT) $(PRINTF) -o $(NAME)
		$(CC) $(CFLAGS) $(SRC) $(LINE) $(LIBFT) $(PRINTF) -o $(NAME)
#		$(CC) $(CFLAGS) $(SRC) $(LINE) -o $(NAME)
#		$(CC) $(CFLAGS) $(SRC) -o $(NAME)

valgrind: $(OBJS)
	$(MAKE) -C $(MLX_LIB_DIR)
#	$(CC) $(CFLAGS) -fsanitize=address $(SRC) $(LINE) $(LIBFT) $(PRINTF) -o $(NAME)
	$(CC) $(CFLAGS) $(SRC) $(LINE) $(LIBFT) $(PRINTF) -o $(NAME)
#	./$(NAME) "pyra.fdf"
#	 valgrind --leak-check=full ./$(NAME) "pyra.fdf"


run: $(OBJS)
	$(CC) $(CFLAGS) $(SRC) $(LINE)` -o $(NAME)
	./$(NAME)

#ll: $(OBJS)
#	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
#	lldb ./$(NAME) -2147483649

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) 

re: fclean all

.PHONY: all clean fclean re