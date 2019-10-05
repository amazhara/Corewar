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

BINARY	:= asm
CC		:= clang
CFLAGS	:= -Wall -Wextra -Werror

LIB_DIR	:= libft/
LIB		:= $(LIB_DIR)libft.a
ft_printf  := ../vmdir/my_printf/libftprintf.a

HEADERS	:= asm.h op.h
SOURCES	:= src/asm1.c src/asm10.c src/asm11.c src/asm12.c src/asm13.c src/asm14.c src/main.c\
src/asm2.c src/asm3.c src/asm4.c src/asm5.c src/asm6.c src/asm7.c src/asm8.c src/asm9.c
OBJECTS	:= $(SOURCES:.c=.o)

all: mlib $(BINARY)

$(BINARY): $(OBJECTS)
	@$(CC) $(CFLAGS) -I. $(LIB) $(ft_printf) $(OBJECTS) -o $(BINARY)
	@echo "\\033[92m$(BINARY) was created!\\033[0m"

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I. -c $< -o $@

mlib:
	@make -C $(LIB_DIR)

clean:
	@rm -rf $(OBJECTS)
	@make clean -C $(LIB_DIR)
	@echo "\\033[91mRemove all $(BINARY) objects files.\\033[0m"

fclean:
	@rm -rf $(OBJECTS) $(BINARY)
	@make fclean -C $(LIB_DIR)
	@echo "\\033[91mRemove all $(BINARY) files.\\033[0m"

re: fclean all
