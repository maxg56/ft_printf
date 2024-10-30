
NAME        = tests_exec
LIBFT       = ../libftprintf.a
CC          = cc 
CFLAGS      = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): main.c $(LIBFT)
	$(MAKE) -C .. all
	$(CC) $(CFLAGS) main.c $(LIBFT) -o $(NAME)

clean:
	$(MAKE) -C .. clean

fclean: clean
	rm -f $(NAME)

re: fclean all
