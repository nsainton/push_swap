/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 06:41:27 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/03 02:47:17 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	*getname(t_stack *stk)
{
	return (stk->name);
}

size_t	getsize(t_stack *stk)
{
	return (stk->size);
}

t_list	*gettop(t_stack *stk)
{
	return (stk->top);
}

t_list *getbottom(t_stack *stk)
{
	return (stk->bottom);
}
