CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -Iinclude

SRCDIR = src
OBJDIR = obj
NAME = serializer

SRCS = $(SRCDIR)/main.cpp $(SRCDIR)/Serializer.cpp
OBJS = $(OBJDIR)/main.o $(OBJDIR)/Serializer.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
