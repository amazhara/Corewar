/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machine.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:48:56 by amazhara          #+#    #+#             */
/*   Updated: 2019/06/20 21:20:24 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VIRTUAL_MACHINE_H
# define _VIRTUAL_MACHINE_H

# include "my_printf/includes/ft_printf.h"
# include "op.h"
# include "vis.h"

typedef struct s_op					t_op;
typedef struct s_op_inf				t_op_inf;
typedef struct s_champ				t_champ;
typedef struct s_carrier			t_carrier;
typedef struct s_carriers			t_carriers;
typedef enum e_verbosity_levels		t_vl;

struct				s_carrier
{
	int				id;
	int				champ_id;
	unsigned char	flag;
	unsigned char	code_curr;
	int				cycles_id;
	int				cycles_to_exec;
	unsigned char	*pos;
	int				regs[REG_NUMBER + 1];
	bool			dead;
};

struct				s_carriers
{
	t_carrier		**carr;
	ssize_t			len;
	ssize_t			max;
};

struct				s_op_inf
{
	t_arg_type		arg_type[3];
	unsigned char	*pos_read;
	bool			error;
	bool			op_error;
	bool			reg_error;
	bool			is_arg;
	bool			is_zjmp;
	int				skip;
	unsigned char	*zjmp_pos;
	int				zjmp_code;
	t_carrier		*carr;
};

struct				s_op
{
	char			*name;
	int				argc;
	t_arg_type		argv[3];
	uint			op_id;
	int				cycles_to_exec;
	char			*comment;
	int				args_type;
	int				dir_size;
	void			(*exec)(t_op_inf*);
};

struct				s_champ
{
	char			name[PROG_NAME_LENGTH + 1];
	uint			code_size;
	char			comment[COMMENT_LENGTH + 1];
	unsigned char	code[CHAMP_MAX_SIZE];
	int				id;
};

enum				e_verbosity_levels
{
	s_lives = 1,
	s_operations = 4,
	s_cycles = 2,
	s_deaths = 8,
	s_pc_movements = 16
};

void				error(char *line);
void				check(void);
void				code_execute(t_carrier *carr);
void parse(char **av);
int					byte_swap32(uint32_t number);
t_carrier			*carrier_place(int champ_id, unsigned char *pos);
void				carrier_current_code(t_carrier *carr);
void				mem_init(void);
int					mem_pos(int move);
void				mem_add(unsigned char *carr_pos, int pos
, void *bytes, int size);
void				main_cycle(void);
void				take_op_arg_types(t_op_inf *inf, t_carrier *carr);
void				take_skip_size(t_op_inf *inf, t_carrier *carr);
uint				byte_get(void *src, int size);
int					byte_option_arg(t_arg_type arg_type);
int					operation_type(t_op_inf *inf, int ind
, int args_num, int dir_size);
int					memory_option_arg(t_arg_type arg_type);
t_champ				*champ_read(char *path);
void				champ_add(t_champ *champ, int id);
void				champs_introduce(void);
void				flag_n(char **av, int *i);
void				flag_dump(char **av, int *i);
void				flag_v(char **av, int *i);
void				dump(void);
void				live(t_op_inf *inf);
void				ld(t_op_inf *inf);
void				st(t_op_inf *inf);
void				add(t_op_inf *inf);
void				sub(t_op_inf *inf);
void				byte_and(t_op_inf *inf);
void				byte_or(t_op_inf *inf);
void				byte_xor(t_op_inf *inf);
void				zjmp(t_op_inf *inf);
void				ldi(t_op_inf *inf);
void				sti(t_op_inf *inf);
void				carrier_fork(t_op_inf *inf);
void				lld(t_op_inf *inf);
void				lldi(t_op_inf *inf);
void				aff(t_op_inf *inf);
void				carrier_lfork(t_op_inf *inf);
int					operation_type_ld(t_op_inf *inf, int ind
, int args_num, int dir_size);
int					jump_pos(int pos);
void				show_lives(int id);
void				show_cycles(void);
void				show_deaths(t_carrier *carr);
void				show_pc_movements(int size, int begin);

int					g_dump;
int					g_champs_count;
t_champ				*g_champs[4];
t_champ				*g_last_live;
t_carriers			*g_carriers;
int					g_cycles;
int					g_cycles_die;
int					g_carr_num;
int					g_lives_count;
int					g_checks_count;
int					g_vis;
int					g_a;
t_vl				g_vl;
int					g_delete_count;
int					g_check_time;
unsigned char		g_mem[MEM_SIZE];

static t_op			g_op_tab[] =
{
	{0, 0, {0}, 0, 0, 0, 0, 0, NULL},
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, &live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, &ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, &st},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, &add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10,
		"soustraction", 1, 0, &sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, &byte_and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, &byte_or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, &byte_xor},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, &zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		10, 25, "load index", 1, 1, &ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		11, 25, "store index", 1, 1, &sti},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, &carrier_fork},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, &lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		14, 50, "long load index", 1, 1, &lldi},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, &carrier_lfork},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, &aff}
};

#endif
