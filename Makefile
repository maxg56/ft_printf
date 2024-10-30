NAME        = libftprintf.a
NAMETESTS   = tests.out    

SRC_FILES   = ft_printf_utils.c ft_printf.c ft_print_unsigned.c

SRC_DIR     = src/
OBJ_DIR     = obj/

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

CC          = cc 
CFLAGS      = -Wall -Wextra -Werror 

RM          = rm -f
MKDIR       = mkdir -p

all:        $(NAME)

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJ)
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:     clean
	$(RM) $(NAME)

re:         fclean all

tests:      all
	$(CC) $(CFLAGS) main.c -L . -l ft -o $(NAMETESTS)
	./$(NAMETESTS)
	rm -f $(NAMETESTS)

.PHONY:     all clean fclean re bonus tests