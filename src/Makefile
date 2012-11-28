all: ../bin/mbolc
lex.yy.c: mbolc.l
	lex -o lex.yy.c mbolc.l
y.tab.c: mbolc.y
	yacc -o y.tab.c -d mbolc.y
obj/%.o: cppSrc/%.cpp include/%.hpp
	mkdir -p obj
	g++ -g -c -I./include/ -o $@ $<
../bin/mbolc: y.tab.c lex.yy.c obj/classes.o obj/visitors.o obj/utilities.o
	g++ -I./include/ -g obj/classes.o obj/utilities.o obj/visitors.o lex.yy.c y.tab.c -lfl -o ../bin/mbolc
clean:
	rm -rf ../bin/mbolc obj
install:
	cp ../bin/mbolc /usr/bin
