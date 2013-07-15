all: ../docs/mbol-grammar.txt ../bin/mbolc
../docs/mbol-grammar.txt: mbol-grammar-tool y.output
	more y.output | ./mbol-grammar-tool > ../docs/mbol-grammar.txt
y.output: mbolc.y
	yacc -v mbolc.y
mbol-grammar-tool: mbol-grammar-tool.c
	gcc -o mbol-grammar-tool mbol-grammar-tool.c -lfl
mbol-grammar-tool.c: mbol-grammar-tool.l
	lex -o mbol-grammar-tool.c mbol-grammar-tool.l
lex.yy.c: mbolc.l
	lex -o lex.yy.c mbolc.l
y.tab.h: mbolc.y
	yacc -o y.tab.c -d mbolc.y
obj/%.o: cppSrc/%.cpp include/%.hpp
	mkdir -p obj
	g++ -g -c -I./include/ -o $@ $<
../bin/mbolc: y.tab.h lex.yy.c obj/classes.o obj/visitors.o obj/utilities.o
	g++ -I./include/ -g obj/classes.o obj/utilities.o obj/visitors.o lex.yy.c y.tab.c -lfl -o ../bin/mbolc
clean:
	rm -rf ../bin/mbolc obj mbol-grammar-tool *.c *.h *.output
install:
	cp ../bin/mbolc /usr/bin
