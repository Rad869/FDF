NAME = fdf

SRC = 	./get_next_line/get_next_line.c \
		./utils/tab_utils.c \
		./utils/draw.c \
		./utils/read_entry.c \
		./src/error_check.c \
		./src/error_utils.c \
		./src/fdf.c \

		
FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

%.o: %.c
	gcc $(FLAGS) -I/usr/include -Iget_next_line -Imlx_linux -O3 -c $< -o $@


$(NAME): $(OBJ)
	@$(MAKE) -C ./libft/ bonus
	@$(MAKE) -C ./ft_printf/
	gcc $(FLAGS) $(OBJ) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz ./libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)

clean:
	rm -rf $(OBJ)
	@$(MAKE) -C ./libft/ clean
	@$(MAKE) -C ./ft_printf/ clean

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) -C ./libft/ fclean
	@$(MAKE) -C ./ft_printf/ fclean

re: fclean all
