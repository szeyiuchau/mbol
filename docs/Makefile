all: mbol-docs.pdf
mbol-docs.pdf: mbol-docs.tex
	pdflatex mbol-docs.tex
	pdflatex mbol-docs.tex
	pdflatex mbol-docs.tex
	rm -rf mbol-docs.aux mbol-docs.log mbol-docs.nav mbol-docs.out mbol-docs.snm mbol-docs.toc
clean:
	rm -rf mbol-docs.pdf
