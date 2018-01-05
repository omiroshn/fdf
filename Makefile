CC = clang
FILES = main matrix_func matrix_func2 transform init \
		read draw matrixes key_func draw_line ft_atoi_base errors free
SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(FILES)))
DEBUG = -g -O3
FLAGS = -Wall -Wextra -Werror -I.
CGFLAGS_LINUX = -lm -lmlx -lXext -lX11
CGFLAGS_MAC = -lmlx -framework OpenGL -framework AppKit
NAME = fdf

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	$(CC) $(DEBUG) -o $(NAME) $(OBJ) $(FLAGS) $(CGFLAGS_MAC) libft/libft.a

libft/libft.a:
	@make -C libft/
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "libft is done!"
obj/%.o: src/%.c
	$(CC) -c $^ -o $@ $(DEBUG) $(FLAGS)
clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@printf '\033[33m[ ✔ ] %s\n\033[0m' "fdf: Clean"
fclean: clean
	@rm -f $(NAME)
	@rm -rf fdf.dSYM
	@rm -rf .draw.c.swp
	@make -C libft/ fclean
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "fdf: Fclean"
re: fclean all
