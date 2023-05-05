/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 22:48:07 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/07 21:04:06 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	push(t_stack *src, t_stack *dst)
{
	size_t	res;

	res = push_op(src, dst);
	if (res)
		ft_dprintf(OPS_OUT, "p%s\n", getname(dst));
	return (res);
}

size_t	swap(t_stack *stk)
{
	size_t	res;

	res = swap_op(stk);
	if (res)
		ft_dprintf(OPS_OUT, "s%s\n", getname(stk));
	return (res);
}

size_t	rotate(t_stack *stk)
{
	size_t	res;

	if (getsize(stk) < 3)
		return (swap(stk));
	res = rotate_op(stk);
	if (res)
		ft_dprintf(OPS_OUT, "r%s\n", getname(stk));
	return (res);
}

size_t	rrotate(t_stack *stk)
{
	size_t	res;

	if (getsize(stk) < 3)
		return (swap(stk));
	res = rrotate_op(stk);
	if (res)
		ft_dprintf(OPS_OUT, "rr%s\n", getname(stk));
	return (res);
}
