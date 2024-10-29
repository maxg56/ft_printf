# \__________________________Variables______________________________/
NAME        = libftprintf.a
INCLUDE     = include
LIBFT       = libft

NAMETESTS   = tests

SRC_DIR     = src/
OBJ_DIR     = obj/

CC          = cc 
CFLAGS      = -Wall -Wextra -Werror 
MKDIR       = mkdir
RM          = rm -f
AR          = ar rcs
NAME_tstes  = ft_printf

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Sources

SRC_FILES   = ft_printf_utils.c ft_printf.c

SRC         = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ         = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

###

all:        ${NAME}

$(NAME):    $(OBJ)
            @cp libft/libft.a .
            @mv libft.a $(NAME)
            @$(AR) $(NAME) $(OBJ)
            @echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
            @echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
            @$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJF):
            ${MKDIR} $(OBJ_DIR)

clean:
            @$(RM) -rf $(OBJ_DIR)
            @echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean:     clean
            @$(RM) -f $(NAME)
            @echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
            @echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:         fclean all
            @echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

norm:
            @norminette $(SRC) $(INCLUDE) || grep -v Norme -B1 || true

tests:      all
            $(CC) $(CFLAGS) -I $(INCLUDE) main.c -L. -lftprintf -o $(NAMETESTS)
            ./$(NAMETESTS)
            rm -f $(NAMETESTS)

.PHONY:     all clean fclean re norm tests
