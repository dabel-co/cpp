
NAME = megaphone
FLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++
FILES =	megaphone.cpp

#REMOVE FLAG
all: $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(FILES) -o $(NAME)

clean:
	rm -f $(NAME)
fclean: clean
	make fclean -C ./Libft
re: clean all

.PHONY : all clean fclean re