all : run

run : main.o
	g++ -o run main.o -framework OpenGL -framework GLUT 

main.o : main.cpp
	g++ -c main.cpp --std=c++11 -Wno-deprecated

clean:
	rm -f run *.o
