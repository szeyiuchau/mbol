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
main.pdf: main.tex NodeDisjointPaths.tex ChromaticNumber.tex MaxFlow.tex HelloWorld.tex
	pdflatex main.tex
	rm main.aux main.log
ChromaticNumber.hpp: ../bin/mbolc ChromaticNumber.tex
	../bin/mbolc -q ChromaticNumber.tex
NodeDisjointPaths.hpp: ../bin/mbolc NodeDisjointPaths.tex
	../bin/mbolc -q NodeDisjointPaths.tex
HelloWorld.hpp: ../bin/mbolc HelloWorld.tex
	../bin/mbolc -q HelloWorld.tex
MaxFlow.hpp: ../bin/mbolc MaxFlow.tex
	../bin/mbolc -q MaxFlow.tex
SVMHardMargin.hpp: ../bin/mbolc SVMHardMargin.tex
	../bin/mbolc -q SVMHardMargin.tex
SVMSoftMargin.hpp: ../bin/mbolc SVMSoftMargin.tex
	../bin/mbolc -q SVMSoftMargin.tex
main: main.cpp MaxFlow.hpp ChromaticNumber.hpp NodeDisjointPaths.hpp HelloWorld.hpp SVMHardMargin.hpp SVMSoftMargin.hpp misc-files
	g++ -O3 -fopenmp -m64 -fPIC -fno-strict-aliasing -fexceptions -DNDEBUG -DIL_STD -I../include -I$(CPLEX_HOME)/cplex/include -I$(CPLEX_HOME)/concert/include -I. main.cpp -o main -L$(CPLEX_HOME)/cplex/lib/x86-64_sles10_4.1/static_pic -lilocplex -lcplex -L$(CPLEX_HOME)/concert/lib/x86-64_sles10_4.1/static_pic -lconcert -lm -pthread
clean:
	rm -rf *.hpp *.pdf main misc-files *eps
