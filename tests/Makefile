
NAME = tests
CC          = cc 
CFLAGS      = -Wall -Wextra -Werror 

all:	$(NAME)

$(NAME):
	$(MAKE) -C .. all
	cp ../libftprintf.a $(NAME)
	${CC} ${CFLAGS} main.c -o $(NAME)

clean:
	$(MAKE) -C .. clean

fclean: clean
	rm -rf a.out $(NAME)

re: fclean
	$(MAKE) all