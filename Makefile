# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:35:04 by ybereshc          #+#    #+#              #
#    Updated: 2019/06/21 20:14:29 by ikhrypko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VM_DIR		:= vmdir/
ASM_DIR		:= asmdir/
DASM_DIR	:= dasmdir/

all:
	@make -C $(VM_DIR)
	@make -C $(ASM_DIR)
	@make -C $(DASM_DIR)
	@cp $(VM_DIR)corewar .
	@cp $(ASM_DIR)asm .
	@cp $(DASM_DIR)dasm .

clean:
	@make clean -C $(VM_DIR)
	@make clean -C $(ASM_DIR)
	@make clean -C $(DASM_DIR)

fclean:
	@make fclean -C $(VM_DIR)
	@rm -rf corewar
	@make fclean -C $(ASM_DIR)
	@rm -rf asm
	@make fclean -C $(DASM_DIR)
	@rm -rf dasm

re: fclean all
