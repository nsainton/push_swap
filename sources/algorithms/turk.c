/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:33:10 by nsainton          #+#    #+#             */
/*   Updated: 2023/05/05 17:14:34 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	distance_from_top(t_cstack *stk, t_cint nb)
{
	t_list	*lst;
	int		distance;
	int		size;

	lst = gettop(stk);
	distance = 0;
	while (lst && nb != *(int *)getcontent(lst))
	{
		lst = getnext(lst);
		distance ++;
	}
	size = (int)getsize(stk);
	if (distance > size / 2)
		distance -= size;
	return (distance);
}

int	compute_cost(t_cstack *stk[2], t_cint nb, t_moves *moves)
{
	t_cost	cost;
	int		movements;

	update_cost(stk[0], stk[1], nb, &cost);
	update_movements(moves, &cost);
	movements = number_of_moves(moves, &moves->direction);
	clear_moves(moves, moves->direction);
	return (movements);
}

int	least_moves(t_cstack *stk[2], t_moves *moves, t_cint lim)
{
	t_clist	*lst;
	int		min;
	int		min_moves;
	int		tmp;
	t_moves	tmp_moves;

	lst = gettop(stk[0]);
	while (lst && *(int *)getcontent(lst) >= lim)
		lst = getnext(lst);
	min = *(int *)getcontent(lst);
	min_moves = compute_cost(stk, min, moves);
	while (lst)
	{
		tmp = INT_MAX;
		if (*(int *)getcontent(lst) < lim)
			tmp = compute_cost(stk, *(int *)getcontent(lst), &tmp_moves);
		if (tmp < min_moves)
		{
			min = *(int *)getcontent(lst);
			min_moves = tmp;
			ft_memcpy(moves, &tmp_moves, sizeof * moves);
		}
		lst = getnext(lst);
	}
	return (min);
}

size_t	best_push(t_stack *a, t_stack *b, t_csizet min_size)
{
	t_moves	moves;
	int		lim;
	size_t	operations;

	if (! disorder(a))
		return (0);
	lim = n_biggest(a, min_size);
	operations = init_reserve(a, b, lim, min_size);
	if (! operations)
		return (sort_small(a));
	while (getsize(a) > min_size)
	{
		least_moves((t_cstack *[]){a, b}, &moves, lim);
		operations += do_ops(a, b, &moves);
		operations += push(a, b);
	}
	operations += max_on_top(b);
	operations += sort_small(a);
	while (getsize(b))
		operations += push(b, a);
	return (operations);
}

size_t	sort_small(t_stack *stk)
{
	t_clist	*max;
	size_t	operations;

	if (!disorder(stk))
		return (0);
	operations = 0;
	max = findmax(gettop(stk));
	if (max == getbottom(stk))
		return (swap(stk));
	if (max == gettop(stk))
		operations += rotate(stk);
	else
		operations += rrotate(stk);
	if (disorder(stk))
		return (operations + swap(stk));
	else
		return (operations);
}
