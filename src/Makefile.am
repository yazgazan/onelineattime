# whatever flags you want to pass to the C compiler & linker
CC = gcc
CFLAGS = --pedantic --ansi -W -Wall -Wextra -Wshadow -Werror -O3
LDFLAGS = -ltermcap

# this lists the binaries to produce, the (non-PHONY, binary) targets in
# the previous manual Makefile
bin_PROGRAMS = 1lineattime
1lineattime_SOURCES = main.c 1lineattime.c 1lineattime.h io.c io.h opts.c opts.h terminal.c terminal.h
