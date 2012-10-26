all:
	cd src;	make
	cd samples; make
clean:
	cd src; make clean
	cd samples; make clean
install:
	cd src; make install
