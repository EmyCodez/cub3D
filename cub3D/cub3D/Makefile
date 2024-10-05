# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 15:31:19 by esimpson          #+#    #+#              #
#    Updated: 2024/10/05 15:14:06 by esimpson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_PATH = ./library/mlx
LIBFT_PATH = ./library/libft
SRC_PATH = ./src
EXEC_PATH = ./src/execution
PARSE_PATH = ./src/parsing

MLX_FLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -lm

MLX = $(MLX_PATH)/libmlx.a
LIBFT = $(LIBFT_PATH)/libft.a

SRC_FILES =	$(SRC_PATH)/main.c \
			$(PARSE_PATH)/dummy_parse.c \
			$(EXEC_PATH)/init.c $(EXEC_PATH)/raycast.c $(EXEC_PATH)/calculate.c \
			$(EXEC_PATH)/direction.c $(EXEC_PATH)/execute.c
				 			 
SRC_OBJ = $(SRC_FILES:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(SRC_OBJ) 
	@make -C $(MLX_PATH) all
	@make -C $(LIBFT_PATH) all
	@$(CC) $(CFLAGS) $(SRC_OBJ) $(MLX_FLAGS) $(LIBFT) $(MLX) -o $(NAME)
	@echo "SUCCESSFULLY MADE $(words $(SRC_OBJ)) object files"

clean:
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@rm -f $(SRC_OBJ) 

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY:	all clean fclean re 