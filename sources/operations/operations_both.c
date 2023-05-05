/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 03:44:22 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/10 17:05:06 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	swap_both(t_stack *stk1, t_stack *stk2)
{
	size_t	ret;

	ret = swap_op(stk1) + swap_op(stk2);
	if (ret)
		ft_dprintf(OPS_OUT, "ss\n");
	return (ret > 0);
}

size_t	rotate_both(t_stack *stk1, t_stack *stk2)
{
	size_t	ret;

	ret = rotate_op(stk1) + rotate_op(stk2);
	if (ret)
		ft_dprintf(OPS_OUT, "rr\n");
	return (ret > 0);
}

size_t	rrotate_both(t_stack *stk1, t_stack *stk2)
{
	size_t	ret;

	ret = rrotate_op(stk1) + rrotate_op(stk2);
	if (ret)
		ft_dprintf(OPS_OUT, "rrr\n");
	return (ret > 0);
}
