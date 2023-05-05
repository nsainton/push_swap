/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 06:03:08 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/03 04:03:58 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addbottom(t_stack *stk, t_list *node)
{
	node->next = NULL;
	setbottom(stk, node);
	if (! stk->size)
		stk->top = getbottom(stk);
	incsize(stk);
}

void	addtop(t_stack *stk, t_list *node)
{
	node->next = gettop(stk);
	settop(stk, node);
	if (! stk->size)
		stk->bottom = gettop(stk);
	incsize(stk);
}

t_list	*deltop(t_stack *stk)
{
	t_list	*tmp;

	tmp = gettop(stk);
	if (! tmp)
		return (tmp);
	settop(stk, tmp->next);
	tmp->next = NULL;
	decsize(stk);
	if (! getsize(stk))
		clearstack(stk);
	return (tmp);
}

t_list	*delbottom(t_stack *stk)
{
	t_list	*tmp;

	tmp = getbottom(stk);
	if (! tmp)
		return (tmp);
	stk->bottom = findbottom(stk);
	if (stk->bottom != tmp)
		stk->bottom->next = NULL;
	else
		setbottom(stk, NULL);
	decsize(stk);
	if (! getsize(stk))
		clearstack(stk);
	return (tmp);
}
