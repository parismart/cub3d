NAME = Cub3D

SRCS = srcs/cub3d.c \
	   srcs/bmp.c \
	   srcs/exit.c \
	   srcs/keycode.c \
	   srcs/map.c \
	   srcs/movement.c \
	   srcs/raycasting.c \
	   srcs/read.c \
	   srcs/save.c \
	   srcs/sprite.c \
	   srcs/textures.c \
	   srcs/check.c

OBJS = $(SRCS:.c=.o)

CC = clang

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -g

LINUXFLAGS = -lm -lbsd -lXext -lX11

MACFLAGS = -framework OpenGL -framework Appkit

all:		$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -I./libft/ -I./minilibx_linux/ $< -o $(<:.c=.o)
	#$(CC) $(CFLAGS) -c -I./libft/ -I./minilibx_mac/ $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
		cd ./libft/ && make
		cd ./minilibx_linux/ && make
		#cd ./minilibx_mac/ && make
		$(CC) $(CFLAGS) $(LINUXFLAGS) -o $(NAME) -I./minilibx_linux/ $(OBJS) ./libft/libft.a ./minilibx_linux/libmlx_Linux.a
		#$(CC) $(CFLAGS) $(MACFLAGS) -o $(NAME) -I./minilibx_mac/ $(OBJS) ./libft/libft.a ./minilibx_mac/libmlx.a

clean:		
		$(RM) $(OBJS)
		@make clean -C libft
		@make clean -C minilibx_linux
		#@make clean -C minilibx_mac

fclean:		clean
		$(RM) $(NAME) cub3d.bmp
		@make fclean -C libft

re:		fclean all

.PHONY:		all clean fclean re
