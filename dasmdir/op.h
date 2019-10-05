/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2019/06/21 19:43:42 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _OP_H
# define _OP_H
# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER			4
# define MAX_PLAYERS				4
# define MEM_SIZE				(4*1024)
# define IDX_MOD					(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define ALT_COMMENT_CHAR		';'
# define LABEL_CHAR				':'
# define DIRECT_CHAR				'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING			".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA				50
# define NBR_LIVE				21
# define MAX_CHECKS				10

typedef char	t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

# define LLI long long int

typedef struct		s_dasm
{
	char			*name_file;
	char			*str_file;
	char			*temp_str;
	int				fd_ext;
	int				fd_ent;
	int				size;
	char			instruct[16][12];
}					t_dasm;

int					is_instruct2(int t, t_dasm *file);
int					is_instruct(int t, t_dasm *file);
void				init_instruct(char instruct[16][12]);
char				*p_to_code_type_2(char c);
char				*p_to_code_type(char c);
int					parser_to_int_2(char *str);
int					parser_to_int(char *str);
char				*fts_itoa_base(long long int n, int base);
char				*bynar_from_int(int t);
int					int_from_bynar(char **t_str);
int					minus_bynar(char **t_str);
void				fts_putnbr_fd2(long long int n, int fd);
void				read_registr(t_dasm *file, int *count);
int					parse_read_direct(t_dasm *file, int k, LLI *res,
	char **mp_minus);
void				read_direct(t_dasm *file, int *count, int temp);
void				read_indirect(t_dasm *file, int *count);
int					parse_read_no_arg(t_dasm *file, int k, int *temp2,
	char **mp_minus);
void				read_no_arg_instr(t_dasm *file, int temp, int temp2);
char				*fts_sjoin(char *s1, char *s2, int t);
void				arg_instr(t_dasm *file, int temp, int r, int i);
int					instruct(t_dasm *file);

#endif
