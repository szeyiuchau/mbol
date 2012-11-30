all: main
misc-files:
	mkdir misc-files
graph: main
	./main justgraph
	fdp -Tsvg -O misc-files/graph.dot
	convert misc-files/graph.dot.svg graph.pdf
misc-files/svm-softmargin.plot: main misc-files
	./main
misc-files/svm-hardmargin.plot: main misc-files
	./main
svm: misc-files/svm-hardmargin.plot misc-files/svm-softmargin.plot
	gnuplot misc-files/svm-hardmargin.plot
	gnuplot misc-files/svm-softmargin.plot
main.pdf: main.tex mbol-source/*.tex
	pdflatex main.tex
	rm main.aux main.log
mbol-include/%.hpp: mbol-source/%.tex ../bin/mbolc
	mkdir -p mbol-include
	../bin/mbolc -q $< -o $@
main: main.cpp $(patsubst mbol-source/%.tex,mbol-include/%.hpp,$(wildcard mbol-source/*.tex)) misc-files
	g++ -O3 -fopenmp -m64 -fPIC -fno-strict-aliasing -fexceptions -DNDEBUG -DIL_STD -I../include -I$(CPLEX_HOME)/cplex/include -I$(CPLEX_HOME)/concert/include -I./mbol-include/ main.cpp -o main -L$(CPLEX_HOME)/cplex/lib/x86-64_sles10_4.1/static_pic -lilocplex -lcplex -L$(CPLEX_HOME)/concert/lib/x86-64_sles10_4.1/static_pic -lconcert -lm -pthread
clean:
	rm -rf *.pdf main misc-files *eps mbol-include
