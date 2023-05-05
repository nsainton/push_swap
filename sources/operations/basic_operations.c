/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 07:29:19 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/11 11:36:51 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	push_op(t_stack *src, t_stack *dst)
{
	t_list	*tmp;

	if (! getsize(src))
		return (0);
	tmp = deltop(src);
	addtop(dst, tmp);
	return (1);
}

size_t	swap_op(t_stack *stk)
{
	t_list	*first;
	t_list	*second;

	if (stk->size < 2)
		return (0);
	first = deltop(stk);
	second = deltop(stk);
	addtop(stk, first);
	addtop(stk, second);
	return (1);
}

size_t	rotate_op(t_stack *stk)
{
	if (stk->size < 3)
		return (swap_op(stk));
	addbottom(stk, deltop(stk));
	return (1);
}

size_t	rrotate_op(t_stack *stk)
{
	if (stk->size < 3)
		return (swap_op(stk));
	addtop(stk, delbottom(stk));
	return (1);
}
