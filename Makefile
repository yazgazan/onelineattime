
NAME=		1lineattime

SRCS=		main.c			\
		srcs/1lineattime.c	\
		srcs/io.c		\
		srcs/opts.c		\
		srcs/terminal.c

OBJS=		$(SRCS:.c=.o)

CFLAGS=		-W -Wall -Wextra -Wshadow -I ./includes
LDFLAGS=	-ltermcap
CC=		gcc
RM=		rm -rvf

$(NAME): all

all:	$(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LDFLAGS)

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

