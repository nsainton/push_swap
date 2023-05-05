/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:25:35 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/06 22:23:01 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	disorder(t_cstack *stk)
{
	t_list		*lst;
	size_t		index;
	t_compfunc	func;

	if (getsize(stk) < 2)
		return (0);
	lst = gettop(stk);
	index = 0;
	func = getcomp(stk);
	while (getnext(lst))
	{
		index ++;
		if (func(lst, lst->next))
			return (index);
		lst = getnext(lst);
	}
	return (0);
}
