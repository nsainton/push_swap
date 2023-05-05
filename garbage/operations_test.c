/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 01:58:49 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/06 22:29:23 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_stacks(t_stack *a, t_stack *b)
{
	clear_stack(a);
	clear_stack(b);
}

static int	create_stacks(t_stack **a, t_stack **b, t_cchar *args, t_compfunc *cmp)
{
	*b = NULL;
	if (create_stack(a, "A"))
		return (1);
	if (!(fill_stack(*a, args) || create_stack(b, "B")))
		return (0);
	clear_stacks(*a, *b);
	return (1);
}


int	push_test(t_cchar *args)
{
	t_stack *a;
	t_stack *b;

	if (create_stacks(&a, &b, args))
		return (1);
	print_stack(a);
	while (a->size)
	{
		push(a, b);
		print_stack(a);
		print_stack(b);
	}
	while (b->size)
	{
		push(b, a);
		print_stack(a);
		print_stack(b);
	}
	clear_stacks(a, b);
	return (0);
}

int	swap_test(t_cchar *args)
{
	t_stack *a;
	t_stack *b;

	if (create_stacks(&a, &b, args))
		return (1);
	print_stack(a);
	swap(a);
	ft_printf("Swap\n");
	print_stack(a);
	ft_printf("Swap\n");
	swap(a);
	print_stack(a);
	clear_stacks(a, b);
	return (0);
}

int	rotate_test(t_cchar *args)
{
	t_stack *a;
	t_stack *b;
	size_t	i;

	if (create_stacks(&a, &b, args))
		return (1);
	print_stack(a);
	i = 0;
	while (i < getsize(a))
	{
		rotate(a);
		print_stack(a);
		i ++;
	}
	while (i > 0)
	{
		rrotate(a);
		print_stack(a);
		i --;
	}
	clear_stacks(a, b);
	return (0);
}
