CC = g++
CC_FLAGS = -c -Wall -o 
LD_FLAGS = -o
SRC_FILES = $(wildcard src/*.cpp)
TEST_FILES = $(wildcard test/*.cpp) src/Huffman*
OBJ_FILES = $(addprefix obj/,$(notdir $(SRC_FILES:.cpp=.o)))
OUT = huff_encode

default: $(OBJ_FILES)
# create main
	$(CC) $(SRC_FILES) $(LD_FLAGS) bin/$(OUT) --std=c++11

obj/%.o :src/%.cpp
	$(CC) $(CC_FLAGS) $@ $^ --std=c++11

clean:
	-rm obj/*.o
	-rm bin/$(OUT)
	-rm bin/test
	-rm bin/output/*

run:
	@make
	bin/$(OUT) $(args)

quick:
	@make
	bin/$(OUT) hi2.txt bye.txt 

tester: $(OBJ)
	$(CC) $(TEST_FILES) -o bin/test --std=c++11
	bin/test

