all: main maxflow/MaxFlow $(patsubst mbol-source/%.tex,pdfs/%.pdf,$(wildcard mbol-source/*.tex))
maxflow/MaxFlow:
	mkdir -p maxflow
	../bin/mbolc -bin -d maxflow mbol-source/MaxFlow.tex
graph: main
	mkdir -p misc-files
	./main justgraph
	fdp -Tsvg -O misc-files/graph.dot
	convert misc-files/graph.dot.svg graph.pdf
misc-files/svm-softmargin.plot: main
	./main
misc-files/svm-hardmargin.plot: main
	./main
svm: misc-files/svm-hardmargin.plot misc-files/svm-softmargin.plot
	mkdir -p misc-files
	gnuplot misc-files/svm-hardmargin.plot
	gnuplot misc-files/svm-softmargin.plot
main.pdf: main.tex mbol-source/*.tex
	pdflatex main.tex
	rm main.aux main.log
pdfs/%.pdf: mbol-source/%.tex ../bin/mbolc
	mkdir -p pdfs
	../bin/mbolc -pdf -d pdfs $<
mbol-include/%.hpp: mbol-source/%.tex ../bin/mbolc
	mkdir -p mbol-include
	../bin/mbolc -hpp -q $< -d mbol-include
main: main.cpp $(patsubst mbol-source/%.tex,mbol-include/%.hpp,$(wildcard mbol-source/*.tex))
	mkdir -p misc-files
	g++ -O3 -fopenmp -m64 -fPIC -fno-strict-aliasing -fexceptions -DNDEBUG -DIL_STD -I../include -I$(CPLEX_HOME)/cplex/include -I$(CPLEX_HOME)/concert/include -I./mbol-include/ main.cpp -o main -L$(CPLEX_HOME)/cplex/lib/x86-64_sles10_4.1/static_pic -lilocplex -lcplex -L$(CPLEX_HOME)/concert/lib/x86-64_sles10_4.1/static_pic -lconcert -lm -pthread
clean:
	rm -rf main misc-files *eps mbol-include maxflow/MaxFlow* pdfs maxflow/obj.var maxflow/f.var
