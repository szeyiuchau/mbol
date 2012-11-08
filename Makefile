all: bin
	cd src;	make
bin:
	mkdir bin
clean:
	cd src; make clean
	cd samples; make clean
	cd docs; make clean
install:
	cd src; make install
commit:
	git commit -a
	git push origin master
