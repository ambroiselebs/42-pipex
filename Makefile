NAME        = pipex
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -O3
INCLUDES    = -Ilibs/Libft -I.
LIBS        = -Llibs/Libft -lft
SRC         = main.c src/path.c
OBJ         = $(SRC:.c=.o)
LIBFT       = libs/Libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C libs/Libft

$(NAME): $(OBJ)
	@echo "Linking $(NAME)"
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C libs/Libft clean

fclean: clean
	rm -f $(NAME)
	@make -C libs/Libft fclean

re: fclean all

.PHONY: all clean fclean re
