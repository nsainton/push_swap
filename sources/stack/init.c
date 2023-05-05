/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:10:37 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/14 14:14:12 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	next_number(t_cchar **arg)
{
	while (**arg && **arg != ' ')
		*arg += 1;
	while (**arg && **arg == ' ')
		*arg += 1;
}

t_list	*create_node(t_cint number)
{
	int		*content;
	t_list	*node;

	content = ft_calloc(1, sizeof * content);
	if (! content)
		return (NULL);
	*content = number;
	node = ft_lstnew(content);
	if (node)
		return (node);
	free(content);
	return (NULL);
}

int	create_stack(t_stack **stk, t_cchar *name, t_compfunc comp)
{
	*stk = ft_calloc(1, sizeof **stk);
	if (! *stk)
		return (1);
	if (setname(*stk, name))
	{
		free(*stk);
		return (1);
	}
	setcomp(*stk, comp);
	return (0);
}

int	fill_stack(t_stack **stk, t_cchar **args, t_cint nb)
{
	int	index;

	index = 0;
	while (index < nb)
	{
		if (fill_stack_arg(stk, *(args + index)))
			return (1);
		index ++;
	}
	return (0);
}

int	fill_stack_arg(t_stack **stk, t_cchar *arg)
{
	int		nbr;
	t_list	*lst;
	t_cchar	*cpy;

	cpy = arg;
	nbr = ft_atoi(cpy);
	while (*cpy)
	{
		lst = create_node(nbr);
		if (! lst || is_in(gettop(*stk), nbr))
		{
			if (lst)
				free(lst);
			clear_stack(stk);
			return (1);
		}
		addbottom(*stk, lst);
		next_number(&cpy);
		nbr = ft_atoi(cpy);
	}
	return (0);
}
