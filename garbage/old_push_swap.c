/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 05:01:00 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/03 23:10:14 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = build_stack(av[1], "A");
	if (create_empty_stack(&b, "B") || ! a)
	{
		clear_stack(&a);
		clear_stack(&b);
		print_color_string("Allocation Error\n", 's', GRN, STDOUT_FILENO);
		return (0);
	}
}
