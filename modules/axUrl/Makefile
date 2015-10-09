
LIB_NAME = axUrl
UNAME := $(shell uname)

## MAC
ifeq ($(UNAME), Darwin)
CC = clang++
CC_FLAGS = -std=c++11 -Wall
STATIC_LIB_NAME = lib$(LIB_NAME).a

## LINUX
else ifeq($(UNAME), Linux)
#CC = g++
#CC_FLAGS = -std=c++0x -Wall
STATIC_LIB_NAME = lib$(LIB_NAME).a

## WINDOWS
#else

## RASPBERRY PI
CC = g++-4.9
CC_FLAGS = -DANDROID -std=c++14 -Wall -pedantic
endif

INCLUDE_SRC = -Iinclude/ -I../axUtils/include/ -I/usr/local/include/

OBJDIR = build
SRC_DIR = source
INCLUDE_DIR = include/

CPP_FILES := $(wildcard source/*.cpp)
OBJ_FILES := $(addprefix build/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS :=

all: $(OBJ_FILES)
	ar rcs lib/$(STATIC_LIB_NAME) $(OBJ_FILES)

build/%.o: source/%.cpp
	$(CC) $(CC_FLAGS) $(INCLUDE_SRC) -c -o $@ $<

clean:
	rm -f $(OBJDIR)/*.o
	rm -f lib/$(STATIC_LIB_NAME)



