/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:14:28 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/08 21:43:16 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

void	test_rotate()
{
	// ===== INIT ===== //
	t_list	*list_a;
	t_list	*list_b;
	char	*args[] = {"./push_swap", "1", "2", "3", "4", NULL};
	init_t_lists(&list_a, &list_b, 5, args);
	// ================ //

	rotate(&list_a);
	assertLinkedList(list_a->list, (int[]){4, 1, 2, 3}, 4);
}
