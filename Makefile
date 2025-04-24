CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++11 -I./include
LDFLAGS = 

SRC_DIR = src
BIN_DIR = bin

TARGET = $(BIN_DIR)/module_demo

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC_DIR)/sample_module.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -rf $(BIN_DIR)
