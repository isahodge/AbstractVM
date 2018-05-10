# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihodge <ihodge@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 13:52:57 by ihodge            #+#    #+#              #
#    Updated: 2018/05/09 16:47:30 by ihodge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm
LIST = main Create Int8 Int16 Int32 Float Double

SRC = $(addsuffix .cpp, $(LIST))
OBJ = $(addsuffix .o, $(LIST))

CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@g++ $(SRC) $(CCFLAGS) -o $(NAME)
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
