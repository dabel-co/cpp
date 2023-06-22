NAME = phoneBook
FLAGS = -std=c++98 -Wall -Werror -Wextra
CPP = c++
FILES =	Contact.cpp \
		PhoneBook.cpp \

all: $(NAME)
$(NAME) : 
	@$(CPP) $(FLAGS) $(FILES) -o $(NAME)
clean:
	rm -f $(NAME)
fclean: clean
re: clean all

.PHONY : all clean fclean re
