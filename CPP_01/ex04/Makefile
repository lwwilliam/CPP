NAME = ex04

SRC = main.cpp Files.cpp

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRC)
	g++ -std=c++98 $(SRC) $(CFLAGS) -o $(NAME) -fsanitize=address

fclean :
	rm -f *.replace
	rm -f $(NAME)

re : fclean all

test : 
	make && ./ex04 example.txt s s
