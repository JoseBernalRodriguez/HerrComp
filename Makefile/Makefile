all: datos.pdf

# implicit rules
# variables
# $^ : todas las depencias
# $< : Solamente la primera dependencia
# $@ : target

%.x : %.cpp
	g++ $< -o $@

#updown.x: updown.cpp
#	g++ updown.cpp -o updown.x

datos.txt: updown.x
	./$< 1000 > $@

#datos.txt: updown.x
#	./updown.x 1000 > datos.txt

Clean:
	rm -f datos.txt updown.x

CleanAll:
	rm -f datos.txt updown.x datos.pdf

datos.pdf: datos.txt updown.gp
	gnuplot updown.gp
