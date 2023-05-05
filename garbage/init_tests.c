/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:48:56 by nsainton          #+#    #+#             */
/*   Updated: 2023/02/04 02:24:37 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac < 2)
		return (ft_printf("No arguments\n"));
	if (push_test(av[1]))
		return (ft_printf("Push failed\n"));
	else
		ft_printf("Push done\n");
	if (swap_test(av[1]))
		return (ft_printf("Swap failed\n"));
	else
		ft_printf("Swap done\n");
	if (rotate_test(av[1]))
		return (ft_printf("Rotate failed\n"));
	else
		ft_printf("Rotate done\n");
}
