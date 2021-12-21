CC = clang++
CFLAGS = -Wall -Werror -Wextra -std=c++98

STACK = stack

STACK_SOURCES = tests/stack_test.cpp

INCLUDES = ./containers

#COLORS
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

$(STACK): $(OBJ)
	@$(CC) $(CFLAGS) -I $(INCLUDES) $(STACK_SOURCES) -o $@

clean: fclean

fclean:
	rm -f $(STACK)
	@echo cleaned!

re: fclean all
