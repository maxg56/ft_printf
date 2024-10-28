
SCRS		=  main.c 

LIB_ABR		= /libft/libft.a
LIB_NAME	= ft
OBJDIR		= obj
OBJS		= $(addprefix $(OBJDIR)/, $(SCRS:.c=.o))

NAME		= ft_printf
	
CC			= cc 
CFLAGS		= -Wall -Wextra -Werror 
RM			= rm -f
MKDIR		= mkdir

all:		${NAME}

$(OBJDIR):
			${MKDIR} $(OBJDIR)  

$(OBJDIR)/%.o: %.c | $(OBJDIR)
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} -L ${LIB_ABR} -l ${LIB_NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re