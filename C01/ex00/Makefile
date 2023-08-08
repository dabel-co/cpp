# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabel-co <dabel-co@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 11:11:48 by dabel-co          #+#    #+#              #
#    Updated: 2023/07/13 18:07:21 by dabel-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie
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