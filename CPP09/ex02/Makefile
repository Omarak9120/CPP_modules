NAME	= PmergeMe
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -MD
RM		= rm -rf
CC		= c++
SRC_DIR = src/
OBJ_DIR = objects/

SRC		= main \
		  PmergeMe \
		  Vector \
		  Deque \

SRCS	= $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC)))
OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling..$(COLOR_END)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)The project is compiled..$(COLOR_END)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning...$(COLOR_END)"
	@$(RM) $(OBJ_DIR)
	@echo "$(GREEN)Cleaning done.$(COLOR_END)"


fclean: clean
	@echo "$(YELLOW)Cleaning everything...$(COLOR_END)"
	@$(RM) $(NAME) home_shrubbery
	@echo "$(GREEN)Cleaning done.$(COLOR_END)"

re:
	@echo "$(YELLOW)Recompiling...$(COLOR_END)"
	@make fclean
	@make all
	@echo "$(GREEN)The project has been recompiled.$(COLOR_END)"

t5:
	@$(eval ARG = $(shell seq 1 20000 | shuf -n 5))
	@./PmergeMe $(ARG)

t3k:
	@$(eval ARG = $(shell seq 1 20000 | shuf -n 3000))
	@./PmergeMe $(ARG)

t5k:
	@$(eval ARG = $(shell seq 1 20000 | shuf -n 5000))
	@./PmergeMe $(ARG)

t10k:
	@$(eval ARG = $(shell seq 1 20000 | shuf -n 10000))
	@./PmergeMe $(ARG)

t15k:
	@$(eval ARG = $(shell seq 1 50000 | shuf -n 15000))
	@./PmergeMe $(ARG)

tw:
	@./PmergeMe 5 a 3 1
	@echo
	@./PmergeMe 5 3 1a5
	@echo
	@./PmergeMe
	@echo
	@./PmergeMe 5
	@echo
	@./PmergeMe 5 6 7 8

.PHONY: all clean fclean re test

COLOR_END = \033[0;39m
CYAN3 = \033[1;4;96m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
BWhite = \033[1;37m
RED = \033[1;91m
GREEN = \033[1;92m
CYAN2 = \x1B[1;36m
CYAN = \033[1;96m