/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:08:15 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/14 14:27:32 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cost(const t_cost *cost)
{
	ft_dprintf(DEBUG_OUT, "a_moves : %d\n", cost->a_moves);
	ft_dprintf(DEBUG_OUT, "a_size : %d\n", cost->a_size);
	ft_dprintf(DEBUG_OUT, "b_moves : %d\n", cost->b_moves);
	ft_dprintf(DEBUG_OUT, "b_size : %d\n", cost->b_size);
}

void	print_moves(const t_moves *moves)
{
	ft_dprintf(DEBUG_OUT, "ra : %d\n", moves->ra);
	ft_dprintf(DEBUG_OUT, "rb : %d\n", moves->rb);
	ft_dprintf(DEBUG_OUT, "rr : %d\n", moves->rr);
	ft_dprintf(DEBUG_OUT, "rra : %d\n", moves->rra);
	ft_dprintf(DEBUG_OUT, "rrb : %d\n", moves->rrb);
	ft_dprintf(DEBUG_OUT, "rrr : %d\n", moves->rrr);
	ft_dprintf(DEBUG_OUT, "direction : %d\n", moves->direction);
}

void	print_stacks_with_message(t_cstack *a, t_cstack *b, t_cchar *message)
{
	ft_putendl_fd(message, DEBUG_OUT);
	print_stack(a);
	print_stack(b);
}
