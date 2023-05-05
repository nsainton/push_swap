/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:52:05 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/14 15:55:02 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "libraries.h"
# include "structures.h"
# include "enums.h"
# include "typedefs.h"

//Functions from turk.c [       5 functions]

int			distance_from_top(t_cstack *stk, t_cint nb);

int			compute_cost(t_cstack *stk[2], t_cint nb, t_moves *moves);

int			least_moves(t_cstack *stk[2], t_moves *moves, t_cint lim);

size_t		best_push(t_stack *a, t_stack *b, t_csizet min_size);

size_t		sort_small(t_stack *stk);

//Functions from do_ops.c [       4 functions]

size_t		do_ops_both(t_stack *a, t_stack *b, t_moves *moves);

size_t		do_ops_a(t_stack *a, t_moves *moves);

size_t		do_ops_b(t_stack *b, t_moves *moves);

size_t		do_ops(t_stack *a, t_stack *b, t_moves *moves);

//Functions from operations.c [       4 functions]

size_t		push(t_stack *src, t_stack *dst);

size_t		swap(t_stack *stk);

size_t		rotate(t_stack *stk);

size_t		rrotate(t_stack *stk);

//Functions from operations_both.c [       3 functions]

size_t		swap_both(t_stack *stk1, t_stack *stk2);

size_t		rotate_both(t_stack *stk1, t_stack *stk2);

size_t		rrotate_both(t_stack *stk1, t_stack *stk2);

//Functions from basic_operations.c [       4 functions]

size_t		push_op(t_stack *src, t_stack *dst);

size_t		swap_op(t_stack *stk);

size_t		rotate_op(t_stack *stk);

size_t		rrotate_op(t_stack *stk);

//Functions from getters.c [       5 functions]

size_t		getsize(const t_stack *stk);

char		*getname(const t_stack *stk);

t_list		*gettop(const t_stack *stk);

t_list		*getbottom(const t_stack *stk);

t_compfunc	getcomp(t_cstack *stk);

//Functions from setters.c [       5 functions]

void		settop(t_stack *stk, t_list *node);

void		setbottom(t_stack *stk, t_list *node);

int			setname(t_stack *stk, t_cchar *name);

void		setsize(t_stack *stk, t_csizet size);

void		setcomp(t_stack *stk, t_compfunc cmp);

//Functions from print.c [       3 functions]

void		print_node(t_list *lst);

void		print_stack(t_cstack *stk);

//Functions from init.c [       5 functions]

t_list		*create_node(t_cint number);

int			create_stack(t_stack **stk, t_cchar *name, t_compfunc comp);

int			fill_stack(t_stack **stk, t_cchar **args, t_cint nb);

int			fill_stack_arg(t_stack **stk, t_cchar *arg);

//Functions from helpers.c [       5 functions]

void		incsize(t_stack *stk);

void		decsize(t_stack *stk);

t_list		*findbottom(t_stack *stk);

size_t		max_on_top(t_stack *stk);

size_t		init_reserve(t_stack *base, t_stack *reserve, \
t_cint lim, t_csizet size);

//Functions from comparison.c [       5 functions]

int			descending(t_clist *p, t_clist *q);

int			ascending(t_clist *p, t_clist *q);

t_clist		*findextreme(t_clist *stk, t_compfunc cmp);

t_clist		*findmin(t_clist *stk);

t_clist		*findmax(t_clist *stk);

//Functions from algo_funcs.c [       3 functions]

t_ll		sum(t_cstack *stk);

int			average(t_cstack *stk);

int			median(t_clist *stk, t_csizet size);

//Functions from add.c [       2 functions]

void		addtop(t_stack *stk, t_list *node);

void		addbottom(t_stack *stk, t_list *node);

//Functions from delete.c [       4 functions]

t_list		*delbottom(t_stack *stk);

t_list		*deltop(t_stack *stk);

void		clear_stack(t_stack **stk);

//Functions from searching.c [       4 functions]

int			n_biggest(t_cstack *stk, t_csizet index);

int			next_elem(t_clist *stk, int elem);

int			is_in(t_clist *lst, t_cint nbr);

int			next_element(t_cstack *stk, t_cint nbr);

//Functions from infos.c [       4 functions]

void		update_cost(t_cstack *a, t_cstack *b, t_cint nb, t_cost *cost);

void		update_movements(t_moves *moves, const t_cost *cost);

int			number_of_moves(const t_moves *moves, int *direction);

void		clear_moves(t_moves *moves, t_cint direction);

//Functions from sorted.c [       1 functions]

size_t		disorder(t_cstack *stk);

//Functions from parsing.c [       3 functions]

int			parse_arg(t_cchar *arg);

int			parse_args(t_cchar **args, t_cint nb);

//Functions from atoi_errors.c [       2 functions]

int			atoi_errors(t_cchar **s, t_cchar *base, int *err);

//Functions from debug.c [       3 functions]

void		print_cost(const t_cost *cost);

void		print_moves(const t_moves *moves);

void		print_stacks_with_message(t_cstack *a, \
t_cstack *b, t_cchar *message);

#endif
