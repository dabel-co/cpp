NAME = phoneBook
FLAGS = -std=c++98 #-Wall -Werror -Wextra
CPP = c++
FILES =	Contact.cpp \
		PhoneBook.cpp \

all: $(NAME)
$(NAME) : 
	@$(CPP) $(FLAGS) $(FILES) -o $(NAME)
clean:
	rm -f $(NAME)
fclean: clean
	make fclean -C ./Libft
	make clean -C ./mlx
	rm -f libmlx.dylib
re: clean all

.PHONY : all clean fclean re check_libft
