NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
MINIFLAGS = -Llib/minilibx_linux -lmlx -L/usr/lib -Ilib/minilibx_linux -lXext -lX11 -lm -lz

RM = rm -rf
SRCS = cub3d.c\
		./utils/util.c\
		./parser/control1.c\
		./lib/get_next_line/get_next_line_utils.c\
		./lib/get_next_line/get_next_line.c\
		./parser/map_check.c\
		./parser/texture_control.c\
		./parser/format_control.c\
		./parser/map_check_utils.c\
		./parser/map_check_2.c\
		./parser/texture_control_2.c\
		./parser/map_check_3.c\
		./parser/map_close_check_2.c\
		./parser/map_close_check.c\
		./game/cub_game.c\
		./game/key_press.c\
		./game/image_init.c\
		./game/cub_game_2.c\
		./game/raycasting.c\
		./game/raycasting_utils.c\
		./game/game_move.c\
		./game/game_move_2.c\
		./parser/map_check_utils_2.c\
		./utils/utils_2.c\
		./parser/texture_control_3.c

MLX = ./lib/minilibx_linux/libmlx.a
OBJS = $(SRCS:.c=.o)
LIBFT = ./lib/libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINIFLAGS) -o $(NAME)

$(MLX):
	@make -C ./lib/minilibx_linux

$(LIBFT):
	@make -C ./lib/libft

clean:
	@make clean -C ./lib/libft
	@make clean -C ./lib/minilibx_linux
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C ./lib/libft

re: fclean all

.PHONY: all clean fclean re