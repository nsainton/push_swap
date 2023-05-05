/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:24:38 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/03 03:19:10 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setsize(t_stack *stk, size_t size)
{
	stk->size = size;
}

int	setname(t_stack *stk, const char *name)
{
	if (stk->name)
		free(stk->name);
	stk->name = ft_strdup(name);
	return (stk->name == NULL);
}

void	settop(t_stack *stk, t_list *node)
{
	stk->top = node;
}

void	setbottom(t_stack *stk, t_list *node)
{
	if (! (stk->bottom && node))
	{
		stk->bottom = node;
		return ;
	}
	stk->bottom->next = node;
	stk->bottom = stk->bottom->next;
}
