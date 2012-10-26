all: main
graph.pdf: main
	./main justgraph
	fdp -Tsvg -O graph.dot
	convert graph.dot.svg graph.pdf
	rm graph.dot.svg graph.dot
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
main: main.cpp MaxFlow.hpp ChromaticNumber.hpp NodeDisjointPaths.hpp HelloWorld.hpp
	g++ -O3 -fopenmp -m64 -fPIC -fno-strict-aliasing -fexceptions -DNDEBUG -DIL_STD -I$(CPLEX_HOME)/cplex/include -I$(CPLEX_HOME)/concert/include -I. main.cpp -o main -L$(CPLEX_HOME)/cplex/lib/x86-64_sles10_4.1/static_pic -lilocplex -lcplex -L$(CPLEX_HOME)/concert/lib/x86-64_sles10_4.1/static_pic -lconcert -lm -pthread
clean:
	rm *.pdf *.hpp main
