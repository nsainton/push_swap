/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:39:04 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/03 02:54:58 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	incsize(t_stack *stk)
{
	setsize(stk, getsize(stk) + 1);
}

void	decsize(t_stack *stk)
{
	setsize(stk, getsize(stk) - 1);
}

t_list	*findbottom(t_stack *stk)
{
	t_list *tmp;

	if (stk->size < 2)
		return (stk->bottom);
	tmp = stk->top;
	while (tmp->next->next)
		tmp = tmp->next;
	return (tmp);
}
