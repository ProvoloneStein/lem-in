/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 08:37:44 by pstein            #+#    #+#             */
/*   Updated: 2020/02/08 21:03:47 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <fcntl.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct			s_room
{
	struct s_connect	*connect;
	int					num_of_lem;
	int					metka;
	int					v;
	char				*name;
	int					x;
	int					y;
	int					is_start;
	int					is_end;
	struct s_room		*next;
	struct s_room		*last;
}						t_room;

typedef struct			s_connect
{
	struct s_connect	*next;
	struct s_room		*con_room;
}						t_connect;

typedef struct			s_way
{
	struct s_way		*next;
	int					len;
	int					opt;
	struct s_names		*mw;
}						t_way;

typedef struct			s_names
{
	struct s_names		*next;
	char				*name;
}						t_names;

/*
** -----------------------alg.c-----------------------------------
** alg files has ways found alg functions
*/

t_room					*find_end(t_room *room);
int						ft_start(t_room *h_room, t_way **way, int count);

/*
** -----------------------alg2.c-----------------------------------
** alg files has ways found alg functions
*/

void					make_way(t_way **way, t_way *end);
int						check_have_con(t_room *r1, char *name);
void					makepod(t_room *room);
int						itteration(t_room *room);
void					clean_len(t_room *room);

/*
** -----------------------alg3.c-----------------------------------
** alg files has ways found alg functions
*/

int						del_con(t_room *del_room, t_room *h_room);
void					make_wayname(char *name, t_way *way);
t_way					*mkway(int i);
void					go_back(t_room *room, t_way *ways);

/*
** -----------------------lemin.c-----------------------------------
** lemin main
*/

int						make_opt(t_way *way);
int						ft_reader(int *count, int ac, char **av, t_room **room);
void					free_way(t_way *way);
t_way					*ways_fix(t_way *way);

/*
** -----------------------perecos.c-----------------------------------
** way crossing fix
*/

int						sv_a(t_names *w_name, t_way *a);
int						c_ln(t_way *k1, t_way *k2, int i, int j);
int						v_hd(t_way *k1, t_way *k2, t_names *hd1, t_names *hd2);
int						perecos(t_way *a, t_way *b);
void					*check_perecos(t_way *way);

/*
** -----------------------print_alg.c-----------------------------------
** multi
*/

int						way_count(t_way *way);
int						check_opt(t_way *way, int wtway);
int						print_round(t_way *way, int count, int r, int way_c);
int						doit(t_way *way, int count);

/*
** -----------------------print_alg2.c-----------------------------------
** multi
*/

t_names					*find_name(t_way *way, int i, int waycount, int round);
t_way					*find_way(t_way *way, int waycount, int i, int round);
int						countcheck(t_way *way);
int						opt_alg(t_way *way, int count);

/*
** -----------------------room_reader.c-----------------------------------
** room reader and validator
*/

int						line_checker(char *line, int *start, int *end);
int						one_rm_rd(int fd, int *start, int *end, t_room **room);
int						other_helper(char *line, t_room *room, int i);
int						else_rm_rd(int fd, int *start, int *end, t_room *room);
int						room_reader(int fd, t_room **room);

/*
** -----------------------room_reader1.c-----------------------------------
** room reader and validator
*/

void					free_room(t_room *room);
int						check_cord(char *str, int i);
int						is_room(char *str);

/*
** -----------------------read_con.c-----------------------------------
** read and validate connections
*/

t_connect				*mk_con(t_room *rom, t_room *left);
void					con_help(int *k, t_room **rt, t_room **lt, t_room *rm);
int						connected(char *line, t_room *head);
int						line_checker_con(char *line, t_room *head);
int						ft_connect_reader(int fd, t_room **room);

/*
** -----------------------read.c-----------------------------------
** another reader functions
*/

int						ft_free_room(char *line, t_room *room);
int						first_line(int fd);
char					*makename(char **l);
void					makelst_hlp(t_room *lst);
t_room					*makelist(char *l, int *start, int *end);

/*
** -----------------------read.c-----------------------------------
** sort by len
*/

void					printway(t_way *way);
int						ft_str_in(char *line, char *name);
int						ft_bonus(t_way *way, int rnd, char **av, int n);
int						len_sort_1(t_way **way);
t_way					*len_sort(t_way *way);
int						find_duplicates(t_room **room);

#endif
