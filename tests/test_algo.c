/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:00:13 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/08 22:08:13 by antoinemura      ###   ########.fr       */
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
	t_list	*list_a;
	t_list	*list_b;
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

void	test_is_sorted()
{
	// ===== INIT ===== //
	t_list	*list_a;
	t_list	*list_b;
	char	*args[] = {"./push_swap", "1", "2", "3", "4", "5", "6", "7", NULL};
	init_t_lists(&list_a, &list_b, 8, args);
	// ================ //
	assert(is_sorted(list_a) == 0);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args1[] = {"./push_swap", "1", "2", "3", "4", "5", "6", "-1", NULL};
	init_t_lists(&list_a, &list_b, 8, args1);
	assert(is_sorted(list_a) == 0);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args2[] = {"./push_swap", "7", "1", "2", "3", "4", "5", "6", NULL};
	init_t_lists(&list_a, &list_b, 8, args2);
	assert(is_sorted(list_a) == 0);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args3[] = {"./push_swap", "1", "2", "3", "-4", "8", "6", "7", NULL};
	init_t_lists(&list_a, &list_b, 8, args3);
	assert(is_sorted(list_a) == 1);
	free_t_list(list_a);
	free_t_list(list_b);
}

void	test_calculate_smallest_move_cost()
{
	// ===== INIT ===== //
	t_list	*list_a;
	t_list	*list_b;
	t_move	move ;
	char	*args[] = {"./push_swap", "90", "0", "25", "-38", "10", "7", "42", NULL};
	init_t_lists(&list_a, &list_b, 8, args);
	// ================ //

	push(&list_a, &list_b);
	push(&list_a, &list_b);

	// ===== CLOSEST SMALLER ===== //
	// t_move	move = calculate_smallest_move_cost(list_a, list_b);
	// assert(move.a_index == 0);
	// assert(move.b_index == 0);
	// ============================ //

	while (list_a->length != 3)
	{
		print_list(list_a, "list_a");
		print_list(list_b, "list_b");
		printf("=========================================\n");
		move = calculate_smallest_move_cost(list_a, list_b);
		printf("=========================================\n");
		sort(move, &list_a, &list_b);
		printf("is sorted ? = %d\n", is_sorted(list_b));
	}
	sort_3(&list_a);
	print_list(list_a, "a");
	print_list(list_b, "b");
}
