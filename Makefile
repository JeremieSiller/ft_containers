CC = clang++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp

OBJ = $(SRC)


valgrind:
	docker run -ti -v $(PWD):/test memory-test:0.1 bash -c "cd /test/; g++ -o main *.cpp && valgrind --leak-check=full ./main"
