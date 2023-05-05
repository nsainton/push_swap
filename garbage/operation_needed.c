/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_needed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 05:17:11 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/07 20:54:21 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	push_needed(t_cstack *stk, t_cint avg)
{
	if (! getsize(stk))
		return (0);
	if (*(int *)getcontent(gettop(stk)) < avg)
		return (PUSH);
	return (0);
}

size_t	swap_needed(t_cstack *stk, t_clist *ext)
{
	if (getsize(stk) < 2)
		return (0);
	if ((getcomp(stk))(gettop(stk), getnext(gettop(stk))) && gettop(stk) != ext)
		return (SWAP);
	return (0);
}

size_t	rotate_needed(t_cstack *stk, t_csizet disorder)
{
	return ((disorder < getsize(stk) / 2) * ROTATE);
}

size_t	rrotate_needed(t_cstack *stk, t_csizet disorder)
{
	return ((disorder >= getsize(stk) / 2) * RROTATE);
}
