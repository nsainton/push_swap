/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:51:18 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/14 14:23:54 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_cost(t_cstack *a, t_cstack *b, t_cint nb, t_cost *cost)
{
	int	next;

	next = next_element(b, nb);
	cost->a_moves = distance_from_top(a, nb);
	cost->b_moves = distance_from_top(b, next);
	cost->a_size = (int)getsize(a);
	cost->b_size = (int)getsize(b);
}

void	update_movements(t_moves *moves, const t_cost *cost)
{
	ft_bzero(moves, sizeof * moves);
	moves->ra = cost->a_moves;
	moves->rra = cost->a_size - cost->a_moves;
	if (cost->a_moves < 0)
	{
		moves->rra = -1 * cost->a_moves;
		moves->ra = cost->a_moves + cost->a_size;
	}
	moves->rb = cost->b_moves;
	moves->rrb = cost->b_size - cost->b_moves;
	if (cost->b_moves < 0)
	{
		moves->rrb = -1 * cost->b_moves;
		moves->rb = cost->b_moves + cost->b_size;
	}
	moves->rr = min_int(moves->ra, moves->rb);
	moves->ra = max_int(0, moves->ra - moves->rr);
	moves->rb = max_int(0, moves->rb - moves->rr);
	moves->rrr = min_int(moves->rra, moves->rrb);
	moves->rra = max_int(0, moves->rra - moves->rrr);
	moves->rrb = max_int(0, moves->rrb - moves->rrr);
}

int	number_of_moves(const t_moves *moves, int *direction)
{
	int	uu;
	int	ud;
	int	du;
	int	dd;
	int	minimum;

	uu = moves->rr + moves->ra + moves->rb;
	ud = moves->ra + moves->rrb + moves->rr + moves->rrr;
	du = moves->rra + moves->rb + moves-> rr + moves-> rrr;
	dd = moves->rrr + moves->rra + moves->rrb;
	minimum = min_int(min_int(min_int(uu, ud), du), dd);
	if (minimum == uu)
		*direction = UU;
	else if (minimum == ud)
		*direction = UD;
	else if (minimum == du)
		*direction = DU;
	else
		*direction = DD;
	return (minimum);
}

void	clear_moves(t_moves *moves, t_cint direction)
{
	int	rrr;
	int	rr;
	int	opposite;

	opposite = (direction == UD || direction == DU);
	rrr = moves->rrr;
	rr = moves->rr;
	moves->rrr = moves->rrr * (direction == DD);
	moves->rr = moves->rr * (direction == UU);
	moves->ra = moves->ra * (direction == UU || direction == UD) + \
	rr * (opposite && direction == UD);
	moves->rb = moves->rb * (direction == UU || direction == DU) + \
	rr * (opposite && direction == DU);
	moves->rra = moves->rra * (direction == DD || direction == DU) + \
	rrr * (opposite && direction == DU);
	moves->rrb = moves->rrb * (direction == DD || direction == UD) + \
	rrr * (opposite && direction == UD);
}
