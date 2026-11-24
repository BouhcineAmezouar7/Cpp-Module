SRC = HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp \
		main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = Weapon

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Weapon.hpp HumanB.hpp HumanA.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re