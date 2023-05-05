/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:46:02 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/04 00:15:19 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addtop(t_stack *stk, t_list *node)
{
	if (! getsize(stk))
	{
		settop(stk, node);
		setbottom(stk, node);
		incsize(stk);
		return ;
	}
	setnext(node, gettop(stk));
	settop(stk, node);
	incsize(stk);
}

void	addbottom(t_stack *stk, t_list *node)
{
	if (! getsize(stk))
	{
		settop(stk, node);
		setbottom(stk, node);
		incsize(stk);
		return ;
	}
	setnext(getbottom(stk), node);
	setbottom(stk, node);
	incsize(stk);
}
