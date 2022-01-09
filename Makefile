CC			=	gcc
RM			=	rm -rf
PATH_MLX	=	mlx
CFLAGS		=	-Wall -Wextra -Werror# -g3 -fsanitize=address
NAME		=	so_long
FLAGS		=	-ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11
				-Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/

SRCS    =srcs/check_map.c \
                srcs/main.c \
                srcs/get_next_line.c \
                srcs/window.c \
                srcs/player_moves.c \
                srcs/draw_textures.c \
                srcs/draw_textures2.c \
                srcs/utils.c \
                srcs/utils_maths.c \
                srcs/utils_free_exit.c \
                srcs/utils_get_next_line.c \
                srcs/get_map.c



OBJS		=	$(SRCS:.c=.o)


all:			$(NAME)
			@rm ${OBJS}


.c.o:
			$(CC) $(CFLAGS) -Imlx -Ibass  -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@make -C mlx
			$(CC) ${CFLAGS} -o $(NAME) ${OBJS} ${FLAGS}

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) *.o

re:			fclean all

.PHONY:		all clean fclean re

