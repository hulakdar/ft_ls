CC=clang
CFLAGS=-Wall -Wextra -g
FILES=main ft_ls_error_manager ft_ls_is_valid_param ft_ls_sorting ft_ls_print_current ft_ls_construct_info ft_ls_info_push
OBJ=$(addprefix obj/, $(addsuffix .o, $(FILES)))
NAME=ft_ls

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -lm libft/libft.a
	@echo "Binary is done! 🖥"
libft/libft.a:
	@make -C libft/
obj/%.o: %.c
	@$(CC) -c $^ -o $@ $(CFLAGS)
clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@echo "Cleaned the objects! ❌"
fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "Cleaned the binary! ☠️"
re: fclean all
	
.PHONY: clean fclean re

