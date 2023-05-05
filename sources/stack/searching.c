/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:28:47 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/14 14:19:56 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	n_biggest(t_cstack *stk, t_csizet index)
{
	int		biggest;
	size_t	i;

	if (getsize(stk) < index)
		return (0);
	biggest = *(int *)getcontent(findmax(gettop(stk)));
	i = 1;
	while (i < index)
	{
		biggest = next_element(stk, biggest);
		i ++;
	}
	return (biggest);
}

int	next_elem(t_clist *stk, int elem)
{
	int		next_elem;

	next_elem = 0;
	while (stk && *(int *)(stk->content) <= elem)
		stk = getnext(stk);
	if (stk)
		next_elem = *(int *)(stk->content);
	while (stk)
	{
		if (*(int *)(stk->content) < next_elem && \
		*(int *)(stk->content) > elem)
			next_elem = *(int *)(stk->content);
		stk = getnext(stk);
	}
	return (next_elem);
}

int	is_in(t_clist *lst, t_cint nbr)
{
	while (lst)
	{
		if (*(int *)getcontent(lst) == nbr)
			return (1);
		lst = getnext(lst);
	}
	return (0);
}

int	next_element(t_cstack *stk, t_cint nbr)
{
	t_list	*lst;
	int		next;
	int		tmp;

	lst = gettop(stk);
	while (lst && *(int *)getcontent(lst) >= nbr)
		lst = getnext(lst);
	if (! lst)
		return (*(int *)getcontent(findmax(gettop(stk))));
	next = *(int *)getcontent(lst);
	while (lst)
	{
		tmp = *(int *)getcontent(lst);
		if (nbr > tmp && tmp > next)
			next = tmp;
		lst = getnext(lst);
	}
	return (next);
}
