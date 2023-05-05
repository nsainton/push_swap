/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:47:45 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/14 15:51:23 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (print_color("Error\n", 's', RED, ERROR_OUT));
	if (parse_args((t_cchar **)av + 1, ac - 1))
		return (print_color("Error\n", 's', RED, ERROR_OUT));
	if (create_stack(&a, "a", descending))
		return (print_color("Error\n", 's', RED, ERROR_OUT));
	b = NULL;
	if (fill_stack(&a, (t_cchar **)av + 1, ac - 1) || \
	create_stack(&b, "b", ascending) || ! getsize(a))
	{
		clear_stack(&a);
		clear_stack(&b);
		return (print_color("Error\n", 's', RED, ERROR_OUT));
	}
	best_push(a, b, 3);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
