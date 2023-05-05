/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_filling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:32:26 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/01 23:36:49 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	on_stack(t_stack *stk, int nbr)
{
	t_list	*node;

	node = stk->top;
	while (node)
	{
		if (*(int *)node->content == nbr)
			return (1);
		node = node->next;
	}
	return (0);
}

static void	arg_loop(const char **args)
{	
	while (**args && **args != ' ')
		*args += 1;
	if (**args && **args == ' ')
		*args += 1;
}

static t_list	*create_cell(int nbr)
{
	int		*cell;
	t_list	*new_elem;

	cell = ft_calloc(1, sizeof *cell);
	if (cell == NULL)
		return (NULL);
	*cell = nbr;
	new_elem = ft_lstnew(cell);
	if (new_elem == NULL)
		free(cell);
	return (new_elem);
}

t_stack	*build_stack(const char *args, const char *stack_name)
{
	t_stack		*stk;
	t_list		*cell;
	const char	*cpy;
	int			nbr;

	cpy = args;
	if (create_stack(&stk, stack_name, args))
		return (NULL);
	while (*cpy)
	{
		nbr = ft_atoi(cpy);
		cell = create_cell(nbr);
		if (on_stack(stk, nbr) || ! cell)
		{
			if (cell)
				free(cell);
			clear_stack(&stk);
			return (NULL);
		}
		addbottom(stk, cell);
		arg_loop(&cpy);
	}
	return (stk);
}
