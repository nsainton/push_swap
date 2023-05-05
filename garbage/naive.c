/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:37:28 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/07 05:50:41 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
This algorithm works by comparing the first to elems on the stack
If the top is bigger than the bottom and the top ain't the biggest element
We swap both elements.
Then we send the top element to the bottom until the stack is sorted
Operations Used : swap, rotate
Number of Stacks Used : 1
Number of operations in the worst case for 100 elems : 14652
Number of operations in the worst case for 500 elems : 373252
Number of operations in the worst case for 1000 elems : 1496502
Average number of operations in the worst case (0 - 500 elems) : 124500
Average number of operations in the worst case (0 - 100 elems) : 4900
*/

size_t	naive_sort(t_stack *stk)
{
	size_t		operations;
	t_compfunc	cmp;
	t_list		*lst;
	t_clist		*ext;

	operations = 0;
	cmp = getcomp(stk);
	ext = findextreme(gettop(stk), cmp);
	while (disorder(stk))
	{
		lst = gettop(stk);
		if (cmp(lst, getnext(lst)) && lst != ext)
		{
			swap(stk);
			operations ++;
		}
		rotate(stk);
		operations ++;
	}
	return (operations);
}
