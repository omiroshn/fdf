
all: 
	cc -o mlx main.c -lmlx -framework OpenGL -framework AppKit
	./mlx
fclean:
	rm -f mlx
