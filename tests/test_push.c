/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:14:28 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/10 18:21:16 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

void	test_push()
{
	// ===== INIT ===== //
	t_list	list_a;
	t_list	list_b;
	char	*args[] = {"./push_swap", "1", "2", "3", "4", NULL};
	init_t_lists(&list_a, &list_b, 5, args);
	// ================ //

	push(&list_a, &list_b);

	// ===== LIST_A ===== //
	assertLinkedList(list_a.list, (int[]){2, 3, 4}, 3);
	assert(list_a.min == 2);
	assert(list_a.max == 4);
	assert(list_a.length == 3);
	// ================== //

	// ===== LIST_B ===== //
	assertLinkedList(list_b.list, (int[]){1}, 1);
	assert(list_b.min == 1);
	assert(list_b.max == 1);
	assert(list_b.length == 1);
	// ================== //
}
