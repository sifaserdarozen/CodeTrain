#makefile of training

BIN_DIR= ./bin
SRC_DIR= ./src
LIB_DIR= ./lib
INCLUDE= -I../../3rdParty/catch

CPP_OPTIONS= -Wall -g -std=c++11
#disable warnings about unknown pragmas since catch gives one forevery REQUIRE()
CPP_OPTIONS+= -Wno-unknown-pragmas

OPERATING_SYSTEM= $(shell uname -o)

ifeq ($(OPERATING_SYSTEM), GNU/Linux)
CPP_COMPILER= g++
else ifeq ($(OPERATING_SYSTEM), FreeBSD)
CPP_COMPILER= g++47
else
CPP_COMPILER= g++
endif

EXECUTABLES= utests

TARGETS= $(EXECUTABLES)

CPP_OBJS= $(patsubst $(SRC_DIR)/%.cpp, $(LIB_DIR)/%.o, $(wildcard $(SRC_DIR)/*.cpp))

TARGET_LIB= $(LIB_DIR)/$(NAME)_lib.a

.PHONY: link compile clean

link: compile $(TARGETS)
	@echo -- Link Ended

clean:
	rm -f $(BIN_DIR)/*
	rm -f $(LIB_DIR)/*
	@echo "--> Clean Ended"

compile: $(CPP_OBJS)
	@echo "Compiling ended for.... " $(CPP_OBJS)

$(LIB_DIR)/%.o: $(SRC_DIR)/%.cpp | $(LIB_DIR)
	@echo "Compiling... $@"
	$(CPP_COMPILER) $(CPP_OPTIONS) -c $< $(INCLUDE) -o $@

$(LIB_DIR):
	mkdir -p $(LIB_DIR)
    
$(TARGETS): $(TARGET_LIB) | $(BIN_DIR)
	$(CPP_COMPILER) $(CPP_OPTIONS) $(SRC_DIR)/$@.cpp $^ $(INCLUDE) -o ./bin/$@
    
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(TARGET_LIB): $(CPP_OBJS)
	ar rvs  $(TARGET_LIB) $(CPP_OBJS)
