# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:35:04 by ybereshc          #+#    #+#              #
#    Updated: 2019/06/21 20:07:04 by ikhrypko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BINARY		:= corewar
CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror
LIB_DIR		:= my_printf/
LIB_NAME	:= $(LIB_DIR)libftprintf.a

HEADERS		:= virtual_machine.h vis.h op.h
SOURCES		:= bar.c carrier.c corewar.c flag.c init.c main.c memory.c \
op_arithm.c op_help.c op_jump_fork.c op_ld.c op_live_aff.c op_st.c \
operation.c output.c parse.c parse_binary.c verbosity_levels.c vis.c

OBJECTS		:= $(SOURCES:.c=.o)

all: libft $(BINARY)

$(BINARY): $(OBJECTS)
	@$(CC) $(CFLAGS) -lncurses $(OBJECTS) $(LIB_NAME) -o $(BINARY)
	@echo "\\033[92m$(BINARY) was created!\\033[0m"

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	@make -C $(LIB_DIR)

clean:
	@make clean -C $(LIB_DIR)
	@rm -rf $(OBJECTS)
	@echo "\\033[91mRemove all $(BINARY) objects files.\\033[0m"

fclean:
	@make fclean -C $(LIB_DIR)
	@rm -rf $(OBJECTS) $(BINARY)
	@echo "\\033[91mRemove all $(BINARY) files.\\033[0m"

re: fclean all
