#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocheresh <ocheresh@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/28 09:47:56 by ocheresh          #+#    #+#              #
#    Updated: 2018/10/28 11:00:19 by ocheresh         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all clean fclean re mclean mfclean mre

NAME :=		libft.a

OBJ_PATH :=	.obj/

CC :=		clang
CFLAGS :=	-Wall -Wextra -Werror

HFILES :=	libft
FILES := 	ft_atoi ft_bzero ft_cstr ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint \
ft_itoa ft_listsize ft_lstadd ft_lstadd_end ft_lstdel ft_lstdelone ft_lstiter ft_lstmap \
ft_lstnew ft_memalloc ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel ft_memmove \
ft_memset ft_putchar ft_putchar_fd ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd \
ft_putstr ft_putstr_fd ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdel \
ft_strdup ft_strequ ft_striter ft_striteri ft_strjoin ft_strlcat ft_strlen ft_strmap \
ft_strmapi ft_strncat ft_strncmp ft_strncpy ft_strnequ ft_strnew ft_strnstr ft_strrchr \
ft_strsplit ft_strstr ft_strsub ft_strtrim ft_swap ft_tolower ft_toupper ft_wordfinder

HDRS :=		$(addsuffix .h, $(HFILES))
SRCS :=		$(addsuffix .c, $(FILES))
OBJS :=		$(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@echo "\\033[92masm->$(NAME) was created!\\033[0m"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\\033[91mRemove all asm->$(NAME) objects files.\\033[0m"

fclean:
	@rm -rf $(OBJ_PATH) $(NAME)
	@echo "\\033[91mRemove all asm->$(NAME) files.\\033[0m"

re: fclean all
