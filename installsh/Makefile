
NAME=		1lineattime

SRCS=		../src/main.c		\
		../src/1lineattime.c	\
		../src/io.c		\
		../src/opts.c		\
		../src/terminal.c

OBJS=		$(SRCS:.c=.o)

CFLAGS=		--pedantic --ansi -W -Wall -Wextra -Wshadow -Werror -O3
LDFLAGS=	-ltermcap
CC=		gcc
RM=		rm -rvf
EMBEDER=	./embeder.sh
EMBEDCONF=	installerconf
EMBEDTARGET=	1lineattime-installer.sh

$(NAME): all installer

all:	$(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LDFLAGS)

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(EMBEDTARGET)

re:	fclean all installer

installer:
	$(EMBEDER) $(EMBEDCONF)

.PHONY:	all clean fclean re installer

