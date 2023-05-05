/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 07:52:36 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/10 07:55:50 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_stack_bash(t_stack **stk, t_cchar **args)
{
	int		nbr;
	t_list	*lst;

	while (*args)
	{
		nbr = ft_atoi(*args);
		lst = create_node(nbr);
		if (! lst || is_in(gettop(*stk), nbr))
		{
			if (lst)
				free(lst);
			clear_stack(stk);
			return (1);
		}
		addbottom(*stk, lst);
		args ++;
	}
	return (0);
}
