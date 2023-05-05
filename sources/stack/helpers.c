/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:18:05 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/12 05:07:35 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	incsize(t_stack *stk)
{
	setsize(stk, getsize(stk) + 1);
}

void	decsize(t_stack *stk)
{
	if (stk->size)
		setsize(stk, getsize(stk) - 1);
}

t_list	*findbottom(t_stack *stk)
{
	t_clist	*lst;

	lst = gettop(stk);
	if (getsize(stk) < 3)
		return ((t_list *)lst);
	while (getnext(getnext(lst)))
		lst = getnext(lst);
	return ((t_list *)lst);
}

size_t	max_on_top(t_stack *stk)
{
	int		max;
	int		top;
	size_t	operations;

	max = *(int *)getcontent(findmax(gettop(stk)));
	top = distance_from_top(stk, max);
	operations = 0;
	while (top > 0)
	{
		top --;
		operations += rotate(stk);
	}
	while (top < 0)
	{
		top ++;
		operations += rrotate(stk);
	}
	return (operations);
}

size_t	init_reserve(t_stack *base, t_stack *reserve, t_cint lim, t_csizet size)
{
	size_t	operations;

	if (getsize(base) < size + 1)
		return (0);
	operations = 0;
	while (*(int *)getcontent(gettop(base)) >= lim)
		operations += rotate(base);
	operations += push(base, reserve);
	if (getsize(base) < size + 1)
		return (operations);
	while (*(int *)getcontent(gettop(base)) >= lim)
		operations += rotate(base);
	operations += push(base, reserve);
	if (ascending(gettop(reserve), getnext(gettop(reserve))))
		operations += swap(reserve);
	return (operations);
}
