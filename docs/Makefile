all: mbol-slides.pdf
mbol-grammar.txt: ../src/mbol.y 
mbol-slides.pdf: mbol-slides.tex
	pdflatex mbol-slides.tex
	rm -rf mbol-slides.aux  mbol-slides.log  mbol-slides.nav  mbol-slides.out  mbol-slides.snm  mbol-slides.toc
clean:
	rm -rf mbol-slides.pdf lex.yy.c
