all: bin
	cd src;	make
bin:
	mkdir bin
clean:
	cd src; make clean
	cd samples; make clean
install:
	cd src; make install
