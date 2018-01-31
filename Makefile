# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 21:21:01 by omiroshn          #+#    #+#              #
#    Updated: 2018/01/31 21:21:02 by omiroshn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = clang
FILES = main \
		init \
		read \
		draw \
		free \
		errors \
		matrixes \
		key_func \
		draw_line \
		transform \
		matrix_func \
		matrix_func2 \
		ft_atoi_base
LIBFT_DIR = libft/
SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(FILES)))
OBJ_LIST = $(addsuffix .o, $(FILES))
HEADERS = -I./includes -I./libft/includes
SPEED = -Ofast
FLAGS = -Wall -Wextra -Werror
CGFLAGS_LINUX = -lm -lmlx -lXext -lX11
CGFLAGS_MAC = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

.PHONY: all clean
.NOTPARALLEL: all $(NAME) clean fclean re 

$(NAME): libft/libft.a $(OBJ)
	@echo "\033[36mLinking...\033[34m"
	@$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(SPEED) $(CGFLAGS_MAC) libft/libft.a
	@echo "\033[32m[ ✔ ] Binary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"
libft/libft.a:
	@make --no-print-directory -C $(LIBFT_DIR)
obj/%.o: src/%.c
	@$(CC) -o $@ $(FLAGS) $(HEADERS) -c $^
	@echo "\033[37mCompilation of \033[97m$(notdir $<) \033[0m\033[37mdone. \033[0m"
clean:
	@rm -rf $(OBJ)
	@make -C libft/ clean
	@echo "\033[31m[ ✔ ] Objects files \033[91m$(OBJ_LIST) \033[0m\033[31m removed. \033[0m"
fclean:
	@rm -rf $(OBJ)
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "\033[31m[ ✔ ] Objects files \033[91m$(OBJ_LIST) \033[0m\033[31m removed. \033[0m"
	@echo "\033[31m[ ✔ ] Binary \033[1;31m$(NAME) \033[1;0m\033[31mremoved.\033[0m"
re: fclean all
