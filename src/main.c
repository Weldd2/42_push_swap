/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:59:15 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/12 15:08:49 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_list	list_a;
	t_list	list_b;
	int	min_index;

	parse_args(argc, argv, &list_a, &list_b);
	turk_algorithm(&list_a, &list_b);
	min_index = 0;
	min_index = find_min_index(list_a.list);
	while (list_a.list->value != list_a.min)
	{
		if (min_index > list_a.length / 2)
			rrotate(&list_a);
		else
			rotate(&list_a);
	}
	// print_list(list_a, "a");
	// print_list(list_b, "b");
	free_t_list(list_a);
	free_t_list(list_b);
	return (0);
}
// TODO : implémenter un rotate et rrotate intelligent avec mediane
