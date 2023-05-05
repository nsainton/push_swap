/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 05:53:32 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/01 20:17:40 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_stack(t_stack *stk, const char *name)
{
	stk->top = NULL;
	stk->bottom = NULL;
	setsize(stk, 0);
	return (setname(stk, name));
}

int	create_stack(t_stack **stk, const char *name, const char *args)
{
	if (parse_args(args))
		return (1);
	if (create_empty_stack(stk, name))
		return (1);
	print_stack_status((*stk)->name, 'c');
	return (0);
}

int	create_empty_stack(t_stack **stk, const char *name)
{
	*stk = ft_calloc(1, sizeof **stk);
	if (*stk == NULL)
		return (1);
	if (init_stack(*stk, name))
	{
		clear_stack(stk);
		return (1);
	}
	return (0);
}
