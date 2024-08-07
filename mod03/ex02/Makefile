NAME=shape

RM=rm
MKDIR=mkdir -p

CPP=c++
CPPFLAGS=-Wall -Werror -Wextra -std=c++98 -g3 -fsanitize=address
INC=-I inc
FILES = main

BIN_DIR=bin
BIN=$(BIN_DIR)/$(NAME)

OBJ_DIR=obj
OBJ=$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES))) 

SRC_DIR=src
SRC=$(addprefix $(SRC_DIR)/, $(addsuffix .cpp, $(FILES))) 

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp
	$(MKDIR) $(OBJ_DIR)
	$(CPP) $(CPPFLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	$(MKDIR) $(BIN_DIR)
	@echo "\033[1;33m\t\tCompiling all source files into unique binary\033[0;m"
	$(CPP) $(CPPFLAGS) -o $(BIN) $(OBJ)

all: $(NAME)


clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(BIN)

re: fclean all

run:
	$(BIN)

.PHONY: all clean fclean re