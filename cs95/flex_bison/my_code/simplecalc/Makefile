# $Header: /home/johnl/flnb/code/RCS/Makefile.ch3,v 2.1 2009/11/08 02:53:18 johnl Exp $
# Companion source code for "flex & bison", published by O'Reilly
# Media, ISBN 978-0-596-15597-1
# Copyright (c) 2009, Taughannock Networks. All rights reserved.
# See the README file for license conditions and contact info.

# programs in chapter 3

all:	  calc

calc:	calc.l calc.y calc.h calcfuncs.c
	bison -d calc.y && \
	flex -ocalc.lex.c calc.l && \
	cc -g -o $@ calc.tab.c calc.lex.c calcfuncs.c -lm

clean:
	rm -f  calc \
		calc.tab.c calc.tab.h calc.lex.c
