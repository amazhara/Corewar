# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/26 17:31:26 by amazhara          #+#    #+#              #
#    Updated: 2019/06/21 20:24:30 by ikhrypko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re mclean mfclean mre

NAME :=		libft.a

OBJ_PATH :=	.obj/

CC :=		clang
CFLAGS :=	-Wall -Wextra -Werror
IFLAGS :=	-I .

LIB :=		$(LIB_PATH)libft.a
HFILES :=	libft
FILES := 	ft_itoa ft_strcpy ft_strncpy ft_strcat ft_strncat ft_strlcat \
			ft_strdel ft_strclr ft_strmap ft_strmapi ft_strnjoin ft_isnum \
			ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim strchr_count \
			ft_strchr ft_strsplit ft_strrchr ft_strstr ft_strnstr ft_strcmp \
			ft_strncmp ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
			ft_toupper ft_tolower ft_memset ft_bzero ft_memcpy ft_memccpy \
			ft_memmove ft_memchr ft_memcmp ft_memalloc ft_memdel ft_strnew \
			ft_strpbrk ft_sqrt ft_strnpbrk ft_swap get_next_line ft_intlen \
			ft_itoa_base ft_uintlen ft_double_malloc ft_double_free ft_modul \
			ft_swap ft_strdup ft_strlen ft_atoi ft_strndup ft_array ft_read

HDRS :=		$(addsuffix .h, $(HFILES))
SRCS :=		$(addsuffix .c, $(FILES))
OBJS :=		$(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))


all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@echo "\\033[92m my_printf->$(NAME) was created!\\033[0m"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
$(OBJ_PATH)%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\\033[91mRemove all my_printf->$(NAME) objects files.\\033[0m"
fclean:
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)
	@echo "\\033[91mRemove all my_printf->$(NAME) files.\\033[0m"
re: fclean all
