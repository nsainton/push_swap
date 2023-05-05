/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_deletion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 06:17:27 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/03 04:05:44 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stack(t_stack **stk)
{
	if (! *stk)
	{
		print_color_string("There was no stack\n", RED, STDOUT_FILENO);
		return ;
	}
	ft_lstclear(&((*stk)->top), free);
	if ((*stk)->name)
	{
		print_stack_status((*stk)->name, 'd');
		free((*stk)->name);
	}
	else
		print_color_string("The unnamed stack was deleted\n", RED, \
		STDOUT_FILENO);
	free(*stk);
	*stk = NULL;
}
