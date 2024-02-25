# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 12:38:16 by ale-tron          #+#    #+#              #
#    Updated: 2024/02/25 16:36:43 by ale-tron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fractol
CC = gcc
RM = rm -f
CFLAGS = -Wextra -Wall -Werror -g -fsanitize=address
LIBFT_FLAGS =  -L ./libft -lft
MLX_FLAGS = -L ./mlx -lmlx -lm -framework OpenGL -framework AppKit

LIBFT_DIR = libft/
SRC_DIR = src/
OBJ_DIR = obj/

INCLUDE = Makefile inc/fractol.h libft/*/*/*.c libft/inc/*.h 
SRC = fractol.c handle_errors.c events.c render.c equations.c utils.c 
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))


all: $(NAME)

$(NAME): $(OBJ) 
		make -C $(LIBFT_DIR)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c  $(INCLUDE)
		mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -c -o $@ $<
clean: 
		$(RM) $(OBJ)
		make clean -C $(LIBFT_DIR)

fclean: clean
		$(RM) $(NAME)
		$(RM) $(LIBFT_DIR)libft.a

re: fclean all

.PHONY: all clean fclean re
