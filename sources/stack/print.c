/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:54:32 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/14 14:11:43 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	node_print(void *content)
{
	ft_putnbr_fd(*(int *)content, PRINT_OUT);
	ft_putchar_fd('\n', PRINT_OUT);
}

void	print_node(t_list *lst)
{
	node_print(lst->content);
}

void	print_stack(t_cstack *stk)
{
	ft_dprintf(PRINT_OUT, "This is stack : %s\n", getname(stk));
	ft_dprintf(PRINT_OUT, "The stack size is : %u\n", getsize(stk));
	ft_lstiter(gettop(stk), node_print);
	ft_dprintf(PRINT_OUT, "Stack : %s has been printed\n", getname(stk));
}
