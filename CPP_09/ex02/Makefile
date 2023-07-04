NAME = PmergeMe

SRC = main.cpp PmergeMe.cpp

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRC)
	g++ $(SRC) $(CFLAGS) -o $(NAME) -fsanitize=address

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all