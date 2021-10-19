CC = clang++
CFLAGS = -Wall -Werror -Wextra

NAME = ft_containers

SOURCES =	main.cpp

#COLORS
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

OBJECTS = $(SOURCES:.cpp=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)
	@echo $(G)"  __ _                    _        _                     ";
	@echo $(G)" / _| |                  | |      (_)                    ";
	@echo $(G)"| |_| |_   ___ ___  _ __ | |_ __ _ _ _ __   ___ _ __ ___ ";
	@echo $(G)"|  _| __| / __/ _ \| '_ \| __/ _\` | | '_ \ / _ \ '__/ __|";
	@echo $(G)"| | | |_ | (_| (_) | | | | || (_| | | | | |  __/ |  \__ \\";
	@echo $(G)"|_|  \__| \___\___/|_| |_|\__\__,_|_|_| |_|\___|_|  |___/";
	@echo $(G)"      ______                                             ";
	@echo $(G)"     |______|                                            ";
	@echo $(B)"                                 by @nschumac & @jsiller ";

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $@

clean:
	@echo $(Y)removing object-files...
	@sleep 0.3
	@rm -f $(OBJECTS)
	@echo $(G)done removing object-files$(W)


fclean:
	@echo $(Y)cleaning all binary files
	@sleep 0.2
	@make clean
	@sleep 0.2
	@echo $(Y)removing executable
	@rm -f $(NAME)
	@sleep 0.2
	@echo $(G)executable removed
	@echo $(G)fclean done$(W)

git:
	git add .
	git commit -m "$(msg)"
	git push
	git push GitHub

re: fclean all

val:
	docker run -ti -v $(PWD):/test memory-test:0.1 bash -c "cd /test/; gcc -o main main.c validate/*.c libft/*/*.c && valgrind --leak-check=full ./main x.cub; rm -f main"
