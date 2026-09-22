CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Iinc

SRC_DIR := src
TEST_DIR := tests
BUILD_DIR := build

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
TARGET := $(BUILD_DIR)/main

TEST_SOURCES := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJECTS := $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/test_%.o,$(TEST_SOURCES))
TEST_TARGET := $(BUILD_DIR)/run_tests

GTEST_LIBS := -lgtest -lgtest_main -pthread

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

PROD_OBJS_NO_MAIN := $(filter-out $(BUILD_DIR)/main.o, $(OBJECTS))

$(TEST_TARGET): $(PROD_OBJS_NO_MAIN) $(TEST_OBJECTS)
	$(CXX) $(PROD_OBJS_NO_MAIN) $(TEST_OBJECTS) $(GTEST_LIBS) -o $(TEST_TARGET)

$(BUILD_DIR)/test_%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

cc:
	bear -- make build		

run: $(TARGET)
	./$(TARGET)

# Compiles and instantly runs your unit tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)



clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: all clean
