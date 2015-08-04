
LIB_NAME = axAudioWidget

UNAME := $(shell uname)

## MAC
ifeq ($(UNAME), Darwin)
CC = clang++
CC_FLAGS = -std=c++11 -Wall
STATIC_LIB_NAME = lib$(LIB_NAME).a
DYN_LIB_NAME = lib$(LIB_NAME).dylib

## LINUX
else 
ifeq($(UNAME), Linux)
CC = g++
CC_FLAGS = -std=c++0x -Wall
STATIC_LIB_NAME = lib$(LIB_NAME).a
DYN_LIB_NAME = lib$(LIB_NAME).so

## WINDOWS
# else

## RASPBERRY PI
# CC = g++-4.9
# CC_FLAGS = -std=c++14 -Wall -pedantic
endif

INCLUDE_SRC = -I/usr/local/include/ -I/usr/local/include/freetype2/ -Iinclude/ -I../axEvent/include/ -I../axCore/include/ -I../axUtils/include/ -I../axGL/include/ -I../axCore/core/Mac/ -I../axAudio/include/ -I../axWidget/include/

OBJDIR = build
SRC_DIR = source
INCLUDE_DIR = include/

CPP_FILES := $(wildcard source/*.cpp)
OBJ_FILES := $(addprefix build/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS := 

all: $(OBJ_FILES)
	ar rcs lib/$(STATIC_LIB_NAME) $(OBJ_FILES)
	# $(CC) $(CC_FLAGS) -dynamiclib $(OBJ_FILES) -o lib/$(DYN_LIB_NAME)

install: $(OBJ_FILES)
	@mkdir -p /usr/local/lib/axLib/
	cp lib/$(DYN_LIB_NAME) /usr/local/lib/axLib/
	@mkdir -p /usr/local/include/axLib/
	cp $(wildcard include/*.h) /usr/local/include/axLib/


build/%.o: source/%.cpp
	$(CC) $(CC_FLAGS) $(INCLUDE_SRC) -c -o $@ $<

clean: 
	rm -f $(OBJ_FILES)
	rm -f lib/$(STATIC_LIB_NAME)


