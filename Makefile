# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihodge <ihodge@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 13:52:57 by ihodge            #+#    #+#              #
#    Updated: 2018/05/18 18:15:43 by ihodge           ###   ########.fr        #
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

lex.yy.c: scanner.lex parser.tab.h
	flex -o lex.yy.cc scanner.lex

$(NAME): $(OBJ) lex.yy.cc parser.tab.cc parser.tab.h
	@g++ -ll parser.tab.cc lex.yy.cc $(SRC) -o $(NAME)
	@echo "\033[32;1m"$(NAME)" created\033[0m"

clean:
	@echo "\033[31;1mCleaning..\033[0m"
	@rm -f $(OBJ)

fclean:
	@echo "\033[31;1mFull Cleaning..\033[0m"
	@rm -f $(OBJ)
	@rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re
