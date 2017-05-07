CC = g++
CC_FLAGS = -c -Wall -o 
LD_FLAGS = -o
SRC_FILES = $(wildcard src/*.cpp)
TEST_FILES = $(wildcard test/*.cpp)
OBJ_FILES = $(addprefix obj/,$(notdir $(SRC_FILES:.cpp=.o)))
OUT = huff_encode

$(OUT): $(OBJ_FILES)
	$(CC) $(LD_FLAGS) $@ $^ -std=c++11
	@mv $(OUT) bin/

obj/%.o :src/%.cpp
	$(CC) $(CC_FLAGS) $@ $^ -std=c++11

clean:
	-rm obj/*.o
	-rm bin/$(OUT)
	-rm bin/output/*.txt
	-rm bin/output/*.hdr

run:
	@make
	bin/$(OUT) $(ARGS)

quick:
	@make
	bin/$(OUT) hi.txt bye.txt 
# ADD ARGUMENTS

test: $(OBJ)
	$(CC) $(TEST_FILES) -o bin/test --std=c++11

run-test:
	bin/test

