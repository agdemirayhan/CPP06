# Compiler and flags
NAME := convert
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++17 -Iinclude

# Source files
SRC_DIR := src
OBJ_DIR := obj

SRC_FILES := main.cpp ScalarConverter.cpp
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

# Default target
all: $(NAME)

# Link executable
$(NAME): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each .cpp to obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create obj directory if not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean
clean:
	rm -rf $(OBJ_DIR)

# Full clean
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re
