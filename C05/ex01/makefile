NAME = Sign
CC = c++
RM = rm -f
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 

SRCS =	main.cpp Bureaucrat.cpp Form.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	@clear
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean test