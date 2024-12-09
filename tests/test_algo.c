/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:00:13 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/09 19:12:13 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:14:28 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/07 23:45:19 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

void	test_closest_smaller()
{
	// ===== INIT ===== //
	t_list	list_a;
	t_list	list_b;
	char	*args[] = {"./push_swap", "1", "7", "8", "3", "4", "-4", NULL};
	init_t_lists(&list_a, &list_b, 7, args);
	// ================ //

	// ===== CLOSEST SMALLER ===== //
	assert(find_closest_smaller_index(0, list_a) == 5);
	assert(find_closest_smaller_index(2, list_a) == 0);
	assert(find_closest_smaller_index(-1, list_a) == 5);
	assert(find_closest_smaller_index(5, list_a) == 4);
	assert(find_closest_smaller_index(6, list_a) == 4);
	assert(find_closest_smaller_index(9, list_a) == 2);
	assert(find_closest_smaller_index(-10, list_a) == 2);
	// ============================ //
}


void	test_calculate_smallest_move_cost()
{
	// ===== INIT ===== //
	t_list	list_a;
	t_list	list_b;
	char	*args[] = {"./push_swap", "99", "0", "25", "-38", "10", "7", "42", NULL};
	init_t_lists(&list_a, &list_b, 8, args);
	// ================ //

	push(&list_a, &list_b);
	push(&list_a, &list_b);

	// ===== CLOSEST SMALLER ===== //
	t_move	move = calculate_smallest_move_cost(list_a, list_b, find_closest_smaller_index);
	assert(move.elem_index == 0);
	assert(move.target_index == 0);
	// ============================ //
}

void	test_sort()
{
	// ===== INIT ===== //
	t_list	list_a;
	t_list	list_b;
	char	*args[] = {"./push_swap", "139","497","825","730","958","414", "924","856", NULL};
	init_t_lists(&list_a, &list_b, 9, args);
	// ================ //
	
	push(&list_a, &list_b);
	push(&list_a, &list_b);
	
	while(list_a.length > 3)
		sort(&list_a, &list_b);
	
	assert(is_reverse_sorted(list_b) == 0);

	sort_3(&list_a);
	assert(is_sorted(list_a) == 0);

	printf("push b vers a en triant a (RETOUR)\n");
	while(list_b.length > 0)
		sort_2(&list_a, &list_b);
	assert(is_sorted(list_a) == 0);
}