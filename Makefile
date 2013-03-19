
NAME=		1lineattime

SRCS=		main.c
OBJS=		$(SRCS:.c=.o)

CFLAGS=		-W -Wall -Wextra -Wshadow
LDFLAGS=	-ltermcap
CC=		gcc
RM=		rm -rvf

$(NAME): all

all:	$(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

