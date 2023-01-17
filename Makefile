_END="\033[0m"
_RED="\033[0;31m"
_GREEN="\033[0;32m"
_YELLOW="\033[0;33m"
_CYAN="\033[0;36m"

CC = c++
LIBFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17
INC = -IolcPixelGameEngine
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

NAME = game_of_life

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(_GREEN)Compiling $(OBJ)...$(END)
	@$(CC) $(OBJ) -o $@ $(LIBFLAGS)

%.o: %.cpp
	@echo $(_CYAN)Compiling $<...$(END)
	@$(CC) $(INC) -o $@ -c $< $(CFLAGS)

clean:
	@echo $(_YELLOW)Cleaning $(OBJ)...$(END)
	@rm -f $(OBJ)

fclean: clean
	@echo $(_RED)Cleaning $(NAME)...$(END)
	@rm -f $(NAME)

re: fclean all
