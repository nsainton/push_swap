/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_conquer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 03:58:17 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/09 22:31:51 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	divide(t_stack *stk1, t_stack *stk2)
{
	size_t	index;
	size_t	size;
	int		med;
	size_t	operations;

	size = getsize(stk1);
	operations = 0;
	med = median(gettop(stk1), size);
	index = 0;
	ft_dprintf(PRINT_OUT, "Median of stack %s : %d\n", getname(stk1), med);
	while (index < size)
	{
		/*
		if (swap_needed(stk2, cmp2) && swap_needed(stk1, cmp1))
			operations += swap_both(stk1, stk2);
		*/
		if (* (int *)(gettop(stk1)->content) < med)
			operations += push(stk1, stk2);
		else
			operations += rotate_op(stk1);
		index ++;
	}
	return (operations);
}

	
size_t	conquer(t_stack *stk1, t_stack *stk2)
{
	size_t	ops;

	ops = getsize(stk2);
	while (getsize(stk2))
		push(stk2, stk1);
	return (ops);
}
