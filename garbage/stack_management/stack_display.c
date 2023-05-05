/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 06:11:11 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/03 00:06:28 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	node_print(void *node)
{
	ft_printf("%d\n", *(int *)node);
}

static void	print_stack_infos(const size_t size, const char *name)
{
	ft_dprintf(2, "Printing stack : %s\n", name);
	ft_dprintf(2, "Stack %s size is : %u\n", name, size);
}

void print_stack_status(const char *name, int status)
{
	if (status ^ 'd' && status ^ 'u' && status ^ 'c' && status ^ 'p')
		return ;
	print_color_string("Stack ", GRN, STDOUT_FILENO);
	print_color_string(name, GRN, STDOUT_FILENO);
	print_color_string(" has been successfully ", GRN, STDOUT_FILENO);
	if (status == 'd')
		print_color_string("deleted\n", GRN, STDOUT_FILENO);
	else if (status == 'c')
		print_color_string("created\n", GRN, STDOUT_FILENO);
	else if (status == 'u')
		print_color_string("updated\n", GRN, STDOUT_FILENO);
	else if (status == 'p')
		print_color_string("printed\n", GRN, STDOUT_FILENO);
}
void	print_stack(t_stack *stk)
{
	print_stack_infos(stk->size, stk->name);
	ft_lstiter(stk->top, node_print);
	print_stack_status(stk->name, 'p');
}

void	print_node(t_list *lst)
{
	node_print(lst->content);
}
