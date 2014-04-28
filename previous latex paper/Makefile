all: main.pdf

main.pdf: *.tex *.bib
	pdflatex main
	-bibtex main
	pdflatex main
	pdflatex main
	pdflatex main

clean:
	rm -f main.log main.bbl main.blg main.dvi main.ps main.pdf main.dvi main.aux main.toc *~
