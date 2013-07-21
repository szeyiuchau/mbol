all: bin
	cd src;	make
bin:
	mkdir bin
clean:
	cd src; make clean
	cd samples; make clean
	cd docs; make clean
install:
	cp ./bin/mbolc /usr/bin
env:
	sed -i '/export MBOL_HOME=/d' ~/.bashrc
	echo "export MBOL_HOME=$(PWD)" >> ~/.bashrc
commit:
	git commit -a
	git push origin master
