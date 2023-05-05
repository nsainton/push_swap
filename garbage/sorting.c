/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:49:59 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/08 01:17:27 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t sort_ops(t_cstack *stk, t_clist *extreme, t_csizet disord)
{
	return (swap_needed(stk, extreme) | rotate_needed(stk, disord) | \
	rrotate_needed(stk, disord));
}

size_t	choose_move(t_stack *stk, t_csizet ops)
{
	if (ops & SWAP)
		return (swap(stk));
	if (ops & ROTATE)
		return (rotate(stk));
	if (ops & RROTATE)
		return (rrotate(stk));
	else
		return (0);
}
	
size_t	sort_stack(t_stack *stk)
{
	size_t	operations;
	size_t	disord;
	size_t	ops;
	t_clist	*ext;

	disord = disorder(stk);
	operations = 0;
	ext = findextreme(gettop(stk), getcomp(stk));
	while (disord)
	{
		ops = sort_ops(stk, ext, disord);
		ops += choose_move(stk, ops);
		disord = disorder(stk);
	}
	return (operations);
}
