# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/16 16:53:47 by amazhara          #+#    #+#              #
#    Updated: 2019/06/21 20:22:43 by ikhrypko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re mclean mfclean mre

NAME :=		libftprintf.a

SRC_PATH :=	src/
INC_PATH :=	includes/
LIB_PATH :=	libft/
OBJ_PATH :=	.obj/

CC :=		clang
CFLAGS :=	-Wall -Wextra -Werror
IFLAGS :=	-I $(INC_PATH) -I $(LIB_PATH)

LIB :=		$(LIB_PATH)libft.a
HFILES :=	ft_printf
FILES :=	check_type ft_base_len ft_fitoa ft_printf norm_case output_buf_x output_f pars_and_process pars_u_x \
			printf_stars process_c process_d_i process_f process_p process_pc process_s process_u_x

HDRS :=		$(addprefix $(INC_PATH), $(addsuffix .h, $(HFILES)))
SRCS :=		$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS :=		$(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))


all: $(LIB) $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJS)
	@cp $(LIB) $(NAME)
	@ar -r $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\\033[92m$(NAME) was created!\\033[0m"
$(LIB):
	@make -C $(LIB_PATH)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)$(SRC_PATH)
$(OBJ_PATH)%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean: mclean
	@make clean -C $(LIB_PATH)
	@echo "\\033[91mRemove all $(NAME) objects files.\\033[0m"
fclean: mfclean
	@make fclean -C $(LIB_PATH)
	@echo "\\033[91mRemove all $(NAME) files.\\033[0m"
re: fclean all

mclean:
	@rm -rf $(OBJ_PATH)
mfclean:
	@rm -rf $(NAME)
	@rm -rf $(OBJ_PATH)
mre: mfclean all
