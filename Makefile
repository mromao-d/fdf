# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/25 15:34:29 by mromao-d          #+#    #+#              #
#    Updated: 2023/06/25 16:47:39 by mromao-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = *.c
LINE = get_next_line/*.c

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -fsanitize=address $(SRC) $(LINE) -o $(NAME)
#		$(CC) $(CFLAGS) $(SRC) -o $(NAME)

valgrind: $(OBJS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	valgrind --leak-check=full ./$(NAME) "0 1 2 3 4 5 6 7 8 10 9"


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