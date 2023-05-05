/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:22:27 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/02 23:44:23 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	movetobottom(t_stack *stk)
{
	t_list *tmp;

	tmp = deltop(stk);
	addbottom(stk, tmp);
}

void	movetotop(t_stack *stk)
{
	t_list	*tmp;

	tmp = delbottom(stk);
	addtop(stk, tmp);
}
