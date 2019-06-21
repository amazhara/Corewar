/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:05:41 by ikhrypko          #+#    #+#             */
/*   Updated: 2019/06/21 13:37:54 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VIS_H
# define _VIS_H

# include "virtual_machine.h"
# include <ncurses.h>
# define IDENT 3
# define ESC '\e'
# define SPACE ' '
# define GR 8
# define GR_NUM 355
# define PAUSE "PAUSE    "
# define RUN "RUNNING "

typedef struct s_cell	t_cell;
typedef struct s_but	t_but;

struct		s_cell
{
	int				color;
	int				live;
	int				bold;
};

struct		s_but
{
	int				button;
	int				speed;
	int				run;
	WINDOW			*win;
};

t_cell			g_b[MEM_SIZE];
t_but			g_wis;

void		show_champs(void);
void		info(void);
void		buttons(void);
void		init_color_map(int pos, int c, int size);
void		colors_init(void);
void		init_carr(void);
void		prep(void);
void		colors_default(void);
int			get_color(int i);
void		primt_map(void);
void		ccycle_v(void);
void		main_cycle_v(void);
void		bold_color(unsigned char *carr_pos, int pos, int c, int size);

#endif
