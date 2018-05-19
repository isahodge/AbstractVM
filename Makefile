# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihodge <ihodge@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 13:52:57 by ihodge            #+#    #+#              #
#    Updated: 2018/05/18 19:08:21 by ihodge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm
LIST = Create Instr vm_execute BaseException

SRC = $(addsuffix .cpp, $(LIST))
OBJ = $(addsuffix .o, $(LIST))

CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

parser.tab.cc parser.tab.h: parser.yxx
	bison -o parser.tab.cc -d parser.yxx
	gcc -c parser.tab.cc

lex.yy.c: scanner.lex parser.tab.h
	flex -o lex.yy.cc scanner.lex
	gcc -c lex.yy.cc

$(NAME): $(OBJ) lex.yy.o parser.tab.o parser.tab.h
	@g++ -ll $(CCFLAGS) parser.tab.o lex.yy.o $(OBJ) -o $(NAME)
	@echo "\033[32;1m"$(NAME)" created\033[0m"

$(OBJ): %.o : %.cpp
	g++ $(CCFLAGS) -c $< -o $@

clean:
	@echo "\033[31;1mCleaning..\033[0m"
	@rm -f $(OBJ)

fclean:
	@echo "\033[31;1mFull Cleaning..\033[0m"
	@rm -f $(OBJ)
	@rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re
