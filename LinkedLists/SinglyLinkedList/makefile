all:
	echo "clean,make, and build"
build:
	g++ main.cpp LinkedList.cpp -o list
run:
	./list
clean:
	remove-item list.exe -force
debug:
	g++  -g main.cpp LinkedList.cpp -o list
	gdb ./list
