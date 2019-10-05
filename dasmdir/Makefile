#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/02 18:30:53 by ocheresh          #+#    #+#              #
#    Updated: 2019/02/02 18:30:54 by ocheresh         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = dasm

LIB_DIR	:= ../asmdir/libft/
LIB		:= $(LIB_DIR)libft.a
FT_PRINTF  := ../vmdir/my_printf/libftprintf.a

HEADERS = op.h dasm.h
FILE = main.c instruct.c parser.c bynar.c read.c instr.c
CFLAGS = -Wall -Wextra -Werror
OBJECTS = $(FILE:.c=.o) 

all: $(NAME)

$(NAME): $(OBJECTS)
	@clang $(CFLAGS) $(LIB) $(FT_PRINTF) $(OBJECTS) -o $(NAME)
	@echo "\\033[92m$(NAME) was created!\\033[0m"

%.o: %.c $(HEADERS)
	clang $(CFLAGS) -I. -c $< -o $@

clean:
	@rm -rf $(OBJECTS)
	@echo "\\033[91mRemove all $(NAME) objects files.\\033[0m"

fclean:
	@rm -rf $(OBJECTS) $(NAME)
	@echo "\\033[91mRemove all $(NAME) files.\\033[0m"

re: fclean all

.PHONY: clean fclean all re
