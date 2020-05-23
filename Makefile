main: main.cpp
	g++ -g -Wall -o main main.cpp `pkg-config opencv --cflags --libs`

clear:
	rm main