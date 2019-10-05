/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhrypko <ikhrypko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:56:28 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/06/21 19:58:21 by ikhrypko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ASM_H
# define _ASM_H

# include "libft/libft.h"
# include "op.h"
# include "unistd.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_label
{
	char			*name;
	int				size;
}					t_label;

typedef struct		s_asm
{
	char			*result;
	char			*temp;
	char			*name;
	char			*str_file;
	int				numb_str;
	int				numb_colum;
	int				indx;
	char			instruct[16][12];
	char			tabl[10][9];
	int				mal[2];
	int				size;
	int				fd;
	int				tp;
	t_label			*lab;
}					t_asm;

char				*fts_strndup(char *str, int k);
char				*fts_sjoin(char *s1, char *s2, int t);
long long int		fts_latoi(const char *nptr);
int					check_name(int argc, const char *str, t_asm *file);
int					read_file(t_asm *file, const char *argv);
int					synt_error(t_asm *file);
int					obnul_colum_str(t_asm *file, char c);
int					plus_numb_col(t_asm *file, int *i);
void				propusk_tab(char *line, int *i, t_asm *file);
int					put_name(t_asm *file, t_header *head, int i, int t);
int					put_comment(t_asm *file, t_header *head, int i, int t);
int					put_name_comment(t_asm *file, t_header *head, char *str,
	int *t);
int					put_comment_name(t_asm *file, t_header *head, char *str,
	int *t);
int					find_name_comment(t_asm *file, t_header *head, int *i);
int					char_label(char c, char *str);
int					is_label(char *str);
int					is_instr(char *str);
int					is_instruct(char *str);
int					is_registr(char *str);
int					cintl(long long int n);
int					is_direct(char *str);
int					is_indirect_2(char *str, int i);
int					is_indirect(char *str);
int					is_separator(char *str);
int					is_direct_label(char *s, int i);
int					is_comment(char *str);
int					is_end(char *str);
int					gnl(char **res, char **line);
int					is_instr_2_2(char *str);
int					is_instr_2(char *str);
int					check_arg_instr(char *str, char *instr, int numb_arg);
int					fts_cstr_new(char const *s, char c);
int					check_instr(char *str, char instruct[16][12]);
void				init_tabl(char tabl[10][9]);
void				init_instruct(char instruct[16][12]);
int					mal_int(int ret, int ind, t_asm *file);
void				size_instr(char *str, t_asm *file, int size, int i);
int					is_indirect_label(char *str);
int					check_label_direct(t_asm *file, char *str);
char				*str_to_correct(char *str);
int					put_size_in_label(t_asm *file, char *str);
int					compare_3(char *str, char *tabl, t_asm *file);
int					compare_2(char *str, char *tabl, t_asm *file);
int					compare(char *str, char *tabl, t_asm *file);
int					error_string(int t);
int					compare_str(char *res, t_asm *file);
int					compare_labels(t_asm *file, char *str, int t);
void				count_labels(char *str, t_asm *file, int t);
int					fin_check_lab(t_asm *file, int *i);
char				*parser_to_code_type_2(char *str);
char				*parser_to_code_type(char *str);
int					cw_invert_endian(int x);
int					cw_invert_endian2(int x);
int					convert(int a);
void				print_code_type_arg(char *str, t_asm *file);
void				sum_type_of_arg(char *str, int *i, char **res);
void				type_of_arg(char *str, t_asm *file, int i, int k);
void				init_size(int *size, char *str, t_asm *file);
void				byte_direct(char *str, t_asm *file, int k);
void				byte_direct_label(char *str, t_asm *file, int k);
void				byte_indirect_lab(char *str, t_asm *file);
void				byte_indirect(char *str, t_asm *file);
void				byte_regist(char *str, t_asm *file);
void				parse_args_byte(char *str, int k, t_asm *file);
void				args_to_byte(char *str, int k, t_asm *file, int i);
void				str_to_byte(char *str, t_asm *file);
int					propusk_comment(char *str);
int					check_any_instruct(char *str);
int					byte_code(t_asm *file, int i);
void				join_comment(t_asm *file, t_header *head);
void				join_size(t_asm *file);
void				join_name(t_asm *file, t_header *head);
void				all_to_code(t_asm *file, t_header *head, int i);

#endif
