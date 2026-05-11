NAME = test

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -g -fsanitize=address
# -fsanitize=address

INCS = -I.
SRCS = main.cpp
OBJS=$(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: all clean fclean re

all: $(NAME)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
