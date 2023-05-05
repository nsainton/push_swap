/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 03:20:30 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/04 00:09:41 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delstacktop(t_stack *stk)
{
	t_list	*lst;
	size_t	i;
	size_t	size;


	i = 0;
	size = getsize(stk);
	while (i < size)
	{
		lst = deltop(stk);
		if (! lst)
			return ;
		ft_printf("Here is node : %d | ", i);
		print_node(lst);
		free(lst->content);
		free(lst);
		i ++;
	}
}

void	delstackbottom(t_stack *stk)
{
	t_list	*lst;
	size_t	i;
	size_t	size;


	i = 0;
	size = getsize(stk);
	while (i < size)
	{
		lst = deltop(stk);
		if (! lst)
			return ;
		ft_printf("Here is node : %d | ", i);
		print_node(lst);
		free(lst->content);
		free(lst);
		i ++;
	}
}

void	del_top(t_stack *stk)
{
	t_list	*tmp;

	if (! getsize(stk))
		return ;
	if (getsize(stk))
	{
		stk->top = NULL;
		stk->bottom = NULL;
		stk->size = 0;
		return ;
	}
	ft_dprintf(2, "Top of stack is : %d\n", *(int *)stk->top->content);
	print_stack(stk);
	ft_dprintf(2, "Stack printed\n");
	tmp = stk->top->next;
	if (tmp == NULL)
		ft_dprintf(2, "NULL\n");
	ft_dprintf(2, "e");
	stk->top = tmp;
	ft_dprintf(2, "r");
	stk->size -= 1;
	ft_dprintf(2, "e\n");
}
