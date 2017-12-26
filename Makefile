CC = gcc
FILES = main matrix_func transform init read draw
SRC = $(addsuffix .c, $(FILES))
OBJ = $(addprefix obj/, $(addsuffix .o, $(FILES)))
DEBUG = -g
FLAGS = 
CGFLAGS_LYNUX = -lm -lmlx -lXext -lX11
CGFLAGS_MAC = -lmlx -framework OpenGL -framework AppKit
NAME = fdf

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	$(CC) -o $(NAME) $(SRC) $(FLAGS) $(DEBUG) $(CGFLAGS_MAC) libft/libft.a

libft/libft.a:
	@make -C libft/
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "libft is done!"
obj/%.o: %.c
	@$(CC) -c $^ -o $@ $(FLAGS)
clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@printf '\033[33m[ ✔ ] %s\n\033[0m' "fdf: Clean"
fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "fdf: Fclean"
re: fclean all
	