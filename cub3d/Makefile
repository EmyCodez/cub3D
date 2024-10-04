# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 15:31:19 by esimpson          #+#    #+#              #
#    Updated: 2024/10/03 14:21:55 by adshafee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 

LIBFT = ./library/libft/libft.a
GNL = ./library/get_next_line/get_next_line.a
PRINTF = ./library/libftprintf/libftprintf.a

SRC_PATH = ./src
SRC_FILES = $(SRC_PATH)/main.c $(SRC_PATH)/parse.c $(SRC_PATH)/extention_check.c \
            $(SRC_PATH)/struct_init.c $(SRC_PATH)/texture_validator.c $(SRC_PATH)/texture_validator2.c \
			$(SRC_PATH)/color_validator.c $(SRC_PATH)/map_validator.c $(SRC_PATH)/map_checks.c \
			$(SRC_PATH)/dfs.c

OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(GNL) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME) $(LIBFT) $(GNL) $(PRINTF)

$(LIBFT):
	@make -C ./library/libft

$(GNL):
	@make -C ./library/get_next_line

$(PRINTF):
	@make -C ./library/libftprintf

clean:
	@make -C ./library/libft clean
	@make -C ./library/get_next_line clean
	@make -C ./library/libftprintf clean
	@rm -f $(OBJ_FILES)

fclean: clean
	@make -C ./library/libft fclean
	@make -C ./library/get_next_line fclean
	@make -C ./library/libftprintf fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re