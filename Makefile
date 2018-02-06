SHELL=/bin/sh
LEX=flex
YACC=bison
CC=gcc
RM=rm -f
MKDIR=mkdir -p
CFLAGS=-g -std=c11 -pedantic -Wall
LDFLAGS=-lfl
# --nounput: ne g�n�re pas la fonction yyunput() inutile
# --DYY_NO_INPUT: ne prend pas en compte la fonction input() inutile
# -D_POSIX_SOURCE: d�clare la fonction fileno()
LEXOPTS=-D_POSIX_SOURCE -DYY_NO_INPUT --nounput
YACCOPTS=

PROG=miniml

.PHONY: all
all: $(PROG) clean

$(PROG): $(PROG).yy.o $(PROG).tab.o \
	     names.c ast_make.c ast_list_make.c
	$(CC) $+ -o $@ $(LDFLAGS) 

%.yy.c: %.l %.tab.h
	$(LEX) $(LEXOPTS) --outfile=$@ $<

%.yy.h: %.l
	$(LEX) $(LEXOPTS) --header-file=$@ --outfile=/dev/null $<

%.tab.c %.tab.h: %.y %.yy.h
	$(YACC) $(YACCOPTS) $< -d -v

%.o: %.c
	$(CC) -DYYDEBUG $(CFLAGS) $< -c

.PHONY: clean-all
clean-all: clean
	@$(RM) $(PROG)

.PHONY: clean
clean:
	@$(RM) *.o *.yy.* *.tab.* *.err *.output *.out *.dot

.PHONY: re
re: clean-all all

