# Variables
NAME		= libftprintf.a
INCLUDE		= include
LIBFT		= libft/
SRC_DIR		= src/
PRINTERS_DIR= $(SRC_DIR)/printers/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I $(INCLUDE) 
RM			= rm -f
AR			= ar rcs

# Colors
DEF_COLOR   = \033[0;39m
GREEN       = \033[0;92m
BLUE        = \033[0;94m
CYAN        = \033[0;96m
TERM_UP				=	\033[1A
TERM_CLEAR_LINE		=	\033[2K\r
MAGENTA				=	\033[0;95m

# Sources
SRC_FILES       =   ft_printf
PRINTERS_FILES  =   ft_print_c_fd ft_print_d_fd ft_print_x_fd ft_print_s_fd ft_print_p_fd ft_print_u_fd ft_print_pct_fd

SRC             =   $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
SRC_PRINTERS    =   $(addprefix $(PRINTERS_DIR), $(addsuffix .c, $(PRINTERS_FILES)))
OBJ             =   $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJ_PRINTERS    =   $(addprefix $(OBJ_DIR), $(addsuffix .o, $(PRINTERS_FILES)))

# progress_update
TOTAL_FILES     =   $(words $(SRC) $(SRC_PRINTERS))
COMPILED_COUNT  =   0


define progress_update
	printf "$(TERM_UP)";
	$(eval COMPILED_COUNT=$(shell expr $(COMPILED_COUNT) + 1))
	@printf "$(TERM_CLEAR_LINE)$(CYAN)Compilation progress: $$(($(COMPILED_COUNT) * 100 / $(TOTAL_FILES)))%%$(DEF_COLOR)\n"
endef

###
OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJ_PRINTERS)
			@$(MAKE) -C $(LIBFT) all -s
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(RM) -f libft.a
			@$(AR) $(NAME) $(OBJ) $(OBJ_PRINTERS)
			@echo  "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@$(progress_update)
			@$(CC) $(CFLAGS)  -c $< -o $@
			


	
$(OBJ_DIR)%.o: $(PRINTERS_DIR)%.c | $(OBJF)
			@$(progress_update)
			@$(CC) $(CFLAGS)  -c $< -o $@


$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@$(MAKE) clean -C $(LIBFT) -s
			@echo  "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(MAKE) fclean -C $(LIBFT) -s
			@echo  "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo  "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true


.PHONY:		all clean fclean re norm