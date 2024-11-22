NAME        = pipex
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -O3
INCLUDES    = -Ilibs/Libft -Ilibs/ft_printf/include -I.
LIBS        = -Llibs/Libft -lft \
              -Llibs/ft_printf -lftprintf
SRC         = main.c src/check_args.c
OBJ         = $(SRC:.c=.o)
LIBFT       = libs/Libft/libft.a
FT_PRINTF   = libs/ft_printf/libftprintf.a

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	@make -C libs/Libft

$(FT_PRINTF):
	@make -C libs/ft_printf

$(MLX):
	@make -C libs/mlx

$(NAME): $(OBJ)
	@echo "Linking $(NAME)"
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C libs/Libft clean
	@make -C libs/ft_printf clean

fclean: clean
	rm -f $(NAME)
	@make -C libs/Libft fclean
	@make -C libs/ft_printf fclean

re: fclean all

run: $(LIBFT) $(FT_PRINTF) $(MLX) $(NAME)
	./$(NAME) maps/test2.ber
	make fclean

.PHONY: all clean fclean re
