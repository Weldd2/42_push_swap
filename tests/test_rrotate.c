/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:14:28 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/08 00:05:51 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

void	test_rrotate()
{
	// ===== INIT ===== //
	t_list	*list_a;
	t_list	*list_b;
	char	*args[] = {"./push_swap", "1", "2", "3", "4", NULL};
	init_t_lists(&list_a, &list_b);
	init_t_nodes(&list_a, &list_b, 5, args);
	// ================ //

	rrotate(&list_a);
	assertLinkedList(list_a->list, (int[]){2, 3, 4, 1}, 4);
}
