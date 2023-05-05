/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:14:19 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/06 22:17:30 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	getsize(const t_stack *stk)
{
	return (stk->size);
}

char	*getname(const t_stack *stk)
{
	return (stk->name);
}

t_list	*gettop(const t_stack *stk)
{
	return (stk->top);
}

t_list	*getbottom(const t_stack *stk)
{
	return (stk->bottom);
}

t_compfunc	getcomp(t_cstack *stk)
{
	return (stk->cmp);
}
