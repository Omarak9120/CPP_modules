CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp zombie.cpp newZombie.cpp randomChump.cpp
OBJ = $(SRC:.cpp=.o)
NAME = Zombie

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp zombie.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
