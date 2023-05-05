/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 05:13:22 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/10 16:36:49 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ll	sum(t_cstack *stk)
{
	t_clist	*lst;
	t_ll	sum;

	lst = gettop(stk);
	sum = 0;
	while (lst)
	{
		sum += *(int *)(lst->content);
		lst = getnext(lst);
	}
	return (sum);
}

int	average(t_cstack *stk)
{
	t_ll	avg;

	avg = sum(stk);
	return ((int)(avg / getsize(stk)));
}

int	median(t_clist *stk, t_csizet size)
{
	t_clist	*lst;
	size_t	index;
	int		median;

	lst = findmin(stk);
	median = *(int *)getcontent(lst);
	index = 0;
	while (index < size / 2)
	{
		median = next_elem(stk, median);
		index ++;
	}
	return (median);
}
