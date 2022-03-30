SERVER		= server
CLIENT		= client

# FT_PRINTF #
FT_PRINTF	= ./ft_printf/ft_printf.a
PRINTF_PATH	= ./ft_printf

# COMPILATION #
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
RM			= rm -fr

# COLORS #
GREEN		=	\e[38;5;118m
RED			=	\033[0;31m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(RED)REMOVED$(RESET)]

all: ${SERVER} ${CLIENT}

${FT_PRINTF}:
	@make -s all -C ${PRINTF_PATH}

$(SERVER): ${FT_PRINTF}
	@${CC} ${CFLAGS} server.c ${FT_PRINTF} -o ${SERVER}
	@printf "$(_SUCCESS) server ready.\n"

$(CLIENT): ${FT_PRINTF}
	@${CC} ${CFLAGS} client.c ${FT_PRINTF} -o ${CLIENT}
	@printf "$(_SUCCESS) client ready.\n"

clean:
	@${RM} ${CLIENT} ${SERVER}
	@printf "$(_INFO) server removed.\n"
	@printf "$(_INFO) client removed.\n"

fclean:
	make fclean -C ${PRINTF_PATH}
	@${RM} ${CLIENT} ${SERVER}
	@printf "$(_INFO) server removed.\n"
	@printf "$(_INFO) client removed.\n"

re: fclean all

mandatory: all
bonus: all

m: mandatory
b: bonus

.PHONY: all clean fclean re mandatory bonus m b
