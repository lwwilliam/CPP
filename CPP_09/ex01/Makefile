NAME = RPN

SRC = main.cpp RPN.cpp

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRC)
	g++ -std=c++98 $(SRC) $(CFLAGS) -o $(NAME) -fsanitize=address

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all