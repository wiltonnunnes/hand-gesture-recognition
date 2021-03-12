main: $(FILENAME).cpp
	clear
	build

build: $(FILENAME).cpp
	g++ -g -Wall -o $(FILENAME) $(FILENAME).cpp `pkg-config opencv --cflags --libs`

clear:
	rm $(FILENAME)