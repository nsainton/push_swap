/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:47:45 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/14 12:03:43 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack *b;
	size_t	operations;
	//int		avg;
	//int		med;

	if (ac < 2)
		return (ft_dprintf(PRINT_OUT, "Incorrect number of arguments\n"));
	/*
	int	i;
	int	arg;
	int	err;

	i = -1;
	while (++i < ac)
		ft_dprintf(DEBUG_OUT, "This is av[%d] : %s\n", i, av[i]);
	i = -1;
	err = 0;
	while (++i < ac)
	{
		cpy = (t_cchar **)av + i;
		arg = atoi_errors((t_cchar **)av + i, DEC, &err);
		if (err)
		{
			ft_dprintf(DEBUG_OUT, "An error has been detected\n");
			ft_dprintf(DEBUG_OUT, "This was the original argument : %s\n", *cpy);
			ft_dprintf(DEBUG_OUT, "This is the integer returned : %d\n", arg);
		}
		else
		{
			ft_dprintf(DEBUG_OUT, "No error has been detected\n");
			ft_dprintf(DEBUG_OUT, "This was the original argument : %s\n", *cpy);
			ft_dprintf(DEBUG_OUT, "This is the integer returned : %d\n", arg);
		}
	}
	*/
	if (parse_args((t_cchar **)av + 1, ac - 1))
		return (EXIT_FAILURE);
	if (create_stack(&a, "a", descending))
	{
		print_color("Error\n", 's', RED, PRINT_OUT);
		return (EXIT_FAILURE);
	}
	b = NULL;
	if (fill_stack(&a, (t_cchar *)*(av + 1)) || create_stack(&b, "b", ascending) || \
	! getsize(a))
	/*
	if (fill_stack_bash(&a, (t_cchar **)av + 1) || create_stack(&b, "b", ascending) || \
	! getsize(a))
	*/
	{
		clear_stack(&a);
		clear_stack(&b);
		return (ft_dprintf(PRINT_OUT, "Problem, stack A size is probably 0\n"));
	}
	//close(PRINT_OUT);
	//t_list *lst = gettop(a);
	print_stack(a);
	print_stack(b);
	/*
	if (getsize(a) < 3)
	{
		clear_stack(&b);
		if (getsize(a) == 2 && descending(gettop(a), getnext(gettop(a))))
			swap(a);
		clear_stack(&a);
		return (0);
	}
	if (! disorder(a))
	{
		clear_stack(&b);
		clear_stack(&a);
		return (0);
	}
	*/
	/*
	while (lst)
	{
		ft_dprintf(DEBUG_OUT, "Distance from top : %d\n", distance_from_top(a, *(int*)getcontent(lst)));
		lst = getnext(lst);
	}
	*/
	/*
	while (lst)
	{
		ft_dprintf(DEBUG_OUT, "elem : %d | ", *(int *)getcontent(lst));
		ft_dprintf(DEBUG_OUT, "Next elem : %d\n", next_element(a, *(int *)getcontent(lst)));
		lst = getnext(lst);
	}
	avg = average(a);
	med = median(gettop(a), getsize(a));
	//operations = divide(a, b);
	operations = getsize(a) / 2;
	while (getsize(a) > operations)
		push_op(a, b);
	//print_stack(a);
	//print_stack(b);
	t_list *lst = gettop(a);
	if (descending(lst, getnext(lst)))
		swap(a);
	push(a, b);
	push(a, b);
	print_stack(a);
	print_stack(b);
	lst = gettop(a);
	int nb = *(int *)getcontent(lst);
	operations = 0;
	t_moves	moves;
	*/
	/*
	while (lst)
	{
		nb = *(int *)getcontent(lst);
		ft_dprintf(DEBUG_OUT, "elem : %d | number of moves : %d\n", nb, compute_cost((t_cstack *[]){a, b}, nb, &moves));
		lst = getnext(lst);
	}
	*/
	//ft_dprintf(DEBUG_OUT, "Least moves elems : %d\n", least_moves((t_cstack *[]){a, b}, &moves));
	/*
	while (getsize(a) > 0)
	{
		nb = least_moves((t_cstack *[]){a, b}, &moves);
		ft_printf("Bonjour\n");
		ft_dprintf(DEBUG_OUT, "IN FUNCTION : %s\n", __func__);
		print_moves(&moves);
		ft_dprintf(DEBUG_OUT, "This is the pushed elem : %d\n", nb);
		sleep(1);
		if (getsize(a) < 3)
		{
			print_stack(a);
			print_stack(b);
			sleep(4);
		}
		ft_dprintf(DEBUG_OUT, "State of stacks before applying the operations in order to push : %d\n", nb);
		print_stack(a);
		print_stack(b);
		operations += do_ops(a, b, &moves);
		ft_dprintf(DEBUG_OUT, "The operations in order to push : %d have been done\n", nb);
		print_stack(a);
		print_stack(b);
		operations += push(a, b);
		ft_dprintf(DEBUG_OUT, "The number : %d has been pushed\n", nb);
		print_stack(a);
		print_stack(b);
	}
	nb = *(int *)getcontent(findmax(gettop(b)));
	int top = distance_from_top(b, nb);
	while (top > 0)
	{
		rotate(b);
		top --;
	}
	while (top < 0)
	{
		rrotate(b);
		top ++;
	}
	while (getsize(b))
		push(b, a);
	ft_dprintf(PRINT_OUT, "The stack : %s has been divided in %u operations\n", getname(a), operations);
	operations += sort_print(a);
	operations += sort_print(b);
	ft_dprintf(PRINT_OUT, "This is the average of the stack %s : %d\n", getname(a), avg);
	ft_dprintf(PRINT_OUT, "This is the median of the stack %s : %d\n", getname(a), med);
	ft_dprintf(PRINT_OUT, "Stack %s size is : %u\nStack %s size is : %u\n", getname(a), getsize(a), getname(b), getsize(b));
	ft_dprintf(PRINT_OUT, "The total number of ops is : %u\n", operations);
	operations += conquer(a, b);
	print_stack(a);
	ft_dprintf(PRINT_OUT, "Stack : %s has been sorted in %u operations\n", getname(a), operations);
	med = med + avg;
	print_stack(a);
	print_stack(b);
	*/
	operations = best_push(a, b, 3);
	print_stack(a);
	print_stack(b);
	clear_stack(&a);
	clear_stack(&b);
	ft_dprintf(PRINT_OUT, "Number of operations : %u\n", operations);
	return (0);
}
