NAME	= miniRT

CFLAGS	= -Wall -Wextra -Werror
MAC_API = -framework OpenGL -framework AppKit
MLX_API = -Lminilibx_macOS -lmlx
DEBUG = -g

#colors for beauty
YELLOW =	\033[33;1m
RESET =		\033[0m
RED =		\033[31;1m
GREEN =		\033[32;1m
MAGENTA =	\033[35;1m

ERASE = \33[2K

CC		= gcc

#HEADER		= minirt.h

SRCS	= main.c parser/parser.c  parser/ambient.c parser/camera.c parser/light.c parser/plane.c parser/sphere.c parser/cylinder.c display/show_display.c

%.o: 	%.c #$(HEADER)
		@$(CC) -Iminilibx_macOS -c $< -o $@ -MMD

#@$(CC) $(FLAGS) -Iminilibx_macOS -c $< -o $@ -MMD
$(NAME):	$(SRCS) #$(HEADER)
			@make -C ./Lib
			@make -C ./minilibx_macOS
			@cp Lib/libft.a ./$(NAME)
			@cp minilibx_macOS/libmlx.a ./$(NAME)
			@echo "$(YELLOW)mlx $(GREEN)ready$(RESET)"
			@$(CC) -D DEBUG -Iminilibx_macOS $(MLX_API) $(MAC_API) $(SRCS) minilibx_macOS/libmlx.a Lib/libft.a -o $(NAME)
			@echo "$(MAGENTA)$(NAME) $(GREEN)compiled\033[0m"

#@$(CC) $(CFLAGS) -D DEBUG -Iminilibx_macOS $(MLX_API) $(MAC_API) $(SRCS) minilibx_macOS/libmlx.a Lib/libft.a -o $(NAME)

all: $(NAME)

clean:
	@make fclean -C ./Lib
	@make clean -C ./minilibx_macOS
	@-rm -rf $(OBJS)

fclean: clean
	-rm -rf $(NAME)

re:		fclean all

.PHONY: all clean fclean re
