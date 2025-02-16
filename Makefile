NAME = so_long
FRAEMWORKS = -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g -fsanitize=undefined
FT_PRINTF = ft_printf/libftprintf.a
SRC = main.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	ft_split.c \
	controller.c \
	check.c \
	map_control.c \
	ft_itoa.c \
	error_message.c \
	create_image.c \
	keycode.c 

GREEN := \033[1;32m
RED := \033[1;41m
END := \033[0;39m

OBJ = $(SRC:.c=.o)

INCLUDES = mlx/libmlx.a

all: $(OBJ) $(FT_PRINTF) $(INCLUDES)
	@gcc $(SRC) -o $(NAME) $(CFLAGS) $(FT_PRINTF) $(INCLUDES) $(FRAEMWORKS)
	@echo "$(GREEN)Compile Completed!$(END)"

$(FT_PRINTF):
	make -C ft_printf
$(INCLUDES):
	make -C ./mlx
clean:
	make clean -C ft_printf
	make clean -C ./mlx
	rm -rf $(OBJ)
	@echo "$(RED)Cleaning Completed!$(END)"

fclean: clean
	make fclean -C ft_printf
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
