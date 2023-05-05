/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:41:41 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/14 14:08:43 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	do_ops_both(t_stack *a, t_stack *b, t_moves *moves)
{
	size_t	ops;

	ops = 0;
	while (moves->rrr > 0)
	{
		moves->rrr --;
		ops += rrotate_both(a, b);
	}
	while (moves->rr > 0)
	{
		moves->rr --;
		ops += rotate_both(a, b);
	}
	return (ops);
}

size_t	do_ops_a(t_stack *a, t_moves *moves)
{
	size_t	ops;

	ops = 0;
	while (moves->ra > 0)
	{
		moves->ra --;
		ops += rotate(a);
	}
	while (moves->rra > 0)
	{
		moves->rra --;
		ops += rrotate(a);
	}
	return (ops);
}

size_t	do_ops_b(t_stack *b, t_moves *moves)
{
	size_t	ops;

	ops = 0;
	while (moves->rb > 0)
	{
		moves->rb --;
		ops += rotate(b);
	}
	while (moves->rrb > 0)
	{
		moves->rrb --;
		ops += rrotate(b);
	}
	return (ops);
}

size_t	do_ops(t_stack *a, t_stack *b, t_moves *moves)
{
	size_t	ops;

	ops = 0;
	ops += do_ops_both(a, b, moves);
	ops += do_ops_a(a, moves);
	ops += do_ops_b(b, moves);
	return (ops);
}
