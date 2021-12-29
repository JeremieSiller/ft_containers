CC = clang++

CFLAGS = -std=c++98

FTFLAG = -D FT

TARGET_REAL = real

TARGET_MINE = mine

TARGET = diff_file

SRC = vector.cpp
HPP = ../containers/vector.hpp

$(TARGET): $(SRC) $(HPP) $(TARGET_REAL) $(TARGET_MINE)
	-diff $(TARGET_REAL) $(TARGET_MINE) > $@
	cat $@
$(TARGET_REAL): $(SRC) $(HPP)
	$(CC) $(CFLAGS) $(SRC) -o $@_exec
	./$@_exec > $(TARGET_REAL)

$(TARGET_MINE): $(SRC) $(HPP)
	$(CC) $(CFLAGS) $(FTFLAG) $(SRC) -o $@_exec
	./$@_exec > $(TARGET_MINE)

clean:
	rm -f $(TARGET_MINE) $(TARGET_REAL) $(TARGET_REAL)_exec $(TARGET_MINE)_exec

fclean: clean
	rm -f $(TARGET)

re: fclean $(TARGET)
