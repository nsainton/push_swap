/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:25:59 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/14 13:29:49 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	empty_stack(t_stack *stk)
{
	settop(stk, NULL);
	setbottom(stk, NULL);
}

t_list	*delbottom(t_stack *stk)
{
	t_list	*btm;
	t_list	*newbtm;

	btm = getbottom(stk);
	if (getsize(stk) == 1)
		empty_stack(stk);
	else if (getsize(stk) == 2)
		setbottom(stk, NULL);
	else
	{
		newbtm = findbottom(stk);
		setnext(newbtm, NULL);
		setbottom(stk, newbtm);
	}
	decsize(stk);
	return (btm);
}

t_list	*deltop(t_stack *stk)
{
	t_list	*top;

	top = gettop(stk);
	settop(stk, getnext(top));
	setnext(top, NULL);
	decsize(stk);
	return (top);
}

void	clear_stack(t_stack **stk)
{
	t_list	*lst;

	if (! *stk)
		return ;
	lst = gettop(*stk);
	ft_dprintf(PRINT_OUT, "In function : %s\n", __func__);
	ft_dprintf(PRINT_OUT, "This is the stack : %s\n", getname(*stk));
	print_stack(*stk);
	ft_dprintf(PRINT_OUT, "This was the stack : %s\n", getname(*stk));
	if (lst == NULL)
		ft_dprintf(PRINT_OUT, "The top of the stack is NULL\n");
	else
		ft_dprintf(PRINT_OUT, "The top of the stack is not NULL, watch out !\n");
	ft_lstclear(&lst, free);
	ft_dprintf(PRINT_OUT, "The stack : %s has been cleared\n", getname(*stk));
	free(getname(*stk));
	free(*stk);
	*stk = NULL;
}
