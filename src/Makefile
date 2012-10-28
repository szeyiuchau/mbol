all: ../bin/mbolc
lex.yy.c: mbolc.l
	lex -o lex.yy.c mbolc.l
y.tab.c: mbolc.y
	yacc -o y.tab.c -d mbolc.y
../bin/mbolc: y.tab.c lex.yy.c
	g++ -g lex.yy.c y.tab.c -lfl -o ../bin/mbolc
clean:
	rm -rf lex.yy.c y.tab.c y.tab.h ../bin/mbolc
install:
	cp ../bin/mbolc /usr/bin
