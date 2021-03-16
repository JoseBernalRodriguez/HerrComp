all: datos.pdf

updown.x: updown.cpp
	g++ updown.cpp -o updown.x

datos.txt: updown.x
	./updown.x 1000 > datos.txt

Clean:
	rm -f datos.txt updown.x

datos.pdf: datos.txt updown.gp
	gnuplot updown.gp
