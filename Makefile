CC = clang++
CFLAGS = -Wall -Werror -Wextra -std=c++98

MINE = mine
REAL = real

SRCS	=	tests/main.cpp

INC		=	containers/map.hpp						\
			containers/set.hpp						\
			containers/stack.hpp					\
			containers/vector.hpp					\
			utils/binary_search_tree_iterator.hpp	\
			utils/iterator_traits.hpp				\
			utils/iterator.hpp						\
			utils/node.hpp							\
			utils/pair.hpp							\
			utils/random_access_iterator.hpp		\
			utils/red_black_tree.hpp				\
			utils/sfinae.hpp						\
			utils/utils.hpp


all: $(MINE) $(REAL)

$(MINE): $(SRCS) $(INC)
	$(CC) $(CFLAGS) $(SRCS) -o $@ -D FT

$(REAL): $(SRCS) $(INC)
	$(CC) $(CFLAGS) $(SRCS) -o $@

clean: fclean

fclean:
	rm -f $(MINE) $(REAL)

re: fclean all
