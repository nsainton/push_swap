/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:43:51 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/07 19:28:01 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	settop(t_stack *stk, t_list *node)
{
	stk->top = node;
}

void	setbottom(t_stack *stk, t_list *node)
{
	stk->bottom = node;
}

int	setname(t_stack *stk, t_cchar *name)
{
	if (stk->name)
		free(stk->name);
	stk->name = ft_strdup(name);
	return (stk->name == NULL);
}

void	setsize(t_stack *stk, t_csizet size)
{
	stk->size = size;
}

void	setcomp(t_stack *stk, t_compfunc cmp)
{
	stk->cmp = cmp;
}
