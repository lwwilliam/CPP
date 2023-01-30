NAME = a.out

SRC = main.cpp Fixed.cpp

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRC)
	g++ -std=c++98 $(SRC) $(CFLAGS) -fsanitize=address

fclean :
	rm -f $(NAME)

re : fclean all
