CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Sed.cpp
OBJ = main.o Sed.o
NAME = sed_replace

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp Sed.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
