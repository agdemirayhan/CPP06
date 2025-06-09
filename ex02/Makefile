CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -Iinclude

NAME = identify

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = main.cpp identify.cpp generate.cpp

OBJ_FILES = $(OBJ_DIR)/main.o $(OBJ_DIR)/identify.o $(OBJ_DIR)/generate.o

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $@

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/identify.o: $(SRC_DIR)/identify.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/generate.o: $(SRC_DIR)/generate.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
