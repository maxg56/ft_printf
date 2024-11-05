NAME        = tests_exec
CC          = cc 
CFLAGS      = -Wall -Wextra -Werror 
GREEN       = \033[0;92m
BLUE        = \033[0;94m
CYAN        = \033[0;96m

all: $(NAME)

$(NAME): main.c
	@$(MAKE) -C ..  -s
	@cp ../libftprintf.a .
	@$(CC) $(CFLAGS) main.c  libftprintf.a ../libft/libft.a -o $(NAME)
	@echo  "$(GREEN)ft_printf_testse compiled!$(DEDEF_COLOR)"
	@./tests_exec 1
	@ $(MAKE) clean -s

clean:
	@$(MAKE) -C .. clean -s 
	@rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
