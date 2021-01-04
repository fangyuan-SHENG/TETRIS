lgtk=`pkg-config --cflags --libs gtk+-3.0`


win: main.o buttons.o
	g++ main.o buttons.o win $(lgtk)

main.o: main.cpp buttons.hpp
	g++ -c -g main.cpp -o main.o $(lgtk)

buttons.o: buttons.cpp buttons.hpp
	g++ -c -g buttons.cpp -o buttons.o $(lgtk)

clean:
	rm *.o win

