/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:00:13 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 13:50:30 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2024/12/07 20:14:28 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/07 23:45:19 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

void	test_closest()
{
	// ===== INIT ===== //
	t_list	list_a;
	t_list	list_b;
	char	*args[] = {"./push_swap", "1", "7", "8", "3", "4", "-4", NULL};
	parse_args(7, args, &list_a, &list_b);
	// ================ //

	// ===== cLOSEST SMALLER ===== //
	assert(find_closest_index(0, list_a, COMP_SMALLER) == 5);
	assert(find_closest_index(2, list_a, COMP_SMALLER) == 0);
	assert(find_closest_index(-1, list_a, COMP_SMALLER) == 5);
	assert(find_closest_index(5, list_a, COMP_SMALLER) == 4);
	assert(find_closest_index(6, list_a, COMP_SMALLER) == 4);
	assert(find_closest_index(9, list_a, COMP_SMALLER) == 2);
	assert(find_closest_index(-10, list_a, COMP_SMALLER) == 2);
	// ============================ //

	// ===== cLOSEST BIGGER ===== //
	assert(find_closest_index(0, list_a, COMP_BIGGER) == 0);
	assert(find_closest_index(2, list_a, COMP_BIGGER) == 3);
	assert(find_closest_index(-1, list_a, COMP_BIGGER) == 0);
	assert(find_closest_index(5, list_a, COMP_BIGGER) == 1);
	assert(find_closest_index(6, list_a, COMP_BIGGER) == 1);
	assert(find_closest_index(9, list_a, COMP_BIGGER) == 5);
	assert(find_closest_index(-10, list_a, COMP_BIGGER) == 5);
	// ============================ //

	free_t_list(list_a);
	free_t_list(list_b);

	char	*args2[] = {"./push_swap", "1", "2", "3", "4", "5", NULL};
	parse_args(6, args2, &list_a, &list_b);
	push(&list_a, &list_b);
	push(&list_a, &list_b);
	t_move move = get_best_move(list_a, list_b, COMP_BIGGER);
	assert(move.e_up_cost_value == 3);
	assert(move.target_value == 1);
}


void	test_get_best_move()
{
	// ===== INIT ===== //
	t_list	list_a;
	t_list	list_b;
	t_move	move;
	char	*args[] = {"./push_swap", "99", "0", "25", "-38", "10", "7", "42", NULL};
	parse_args(8, args, &list_a, &list_b);
	// ================ //

	push(&list_a, &list_b);
	push(&list_a, &list_b);

	// ===== cLOSEST SMALLER ===== //
	move = get_best_move(list_a, list_b, COMP_SMALLER);
	assert(move.e_up_cost_index == 0);
	assert(move.target_index == 0);
	// ============================ //

	free_t_list(list_a);
	free_t_list(list_b);

	// ===== INIT ===== //
	char	*args2[] = {"./push_swap", "99", "0", "25", "-38", "10", "7", "42", NULL};
	parse_args(8, args2, &list_a, &list_b);
	// ================ //

	while(list_a.length > 3)
		push(&list_a, &list_b);

	// ===== cLOSEST BIGGER ===== //
	move = get_best_move(list_a, list_b, COMP_BIGGER);
	assert(move.e_up_cost_index == 0);
	assert(move.target_index == 1);
	// ============================ //
}

void	test_sort()
{
	// ===== INIT ===== //
	t_list	list_a;
	t_list	list_b;
	char	*args[] = {"./push_swap", "139","497","825","730","958","414", "924","856", NULL};
	parse_args(9, args, &list_a, &list_b);
	// ================ //
	
	push(&list_a, &list_b);
	push(&list_a, &list_b);
	
	while(list_a.length > 3)
		sort(&list_a, &list_b, COMP_SMALLER);

	
	assert(is_sorted(list_b, descending) == true);

	sort_3(&list_a);
	assert(is_sorted(list_a, ascending) == true);

	while(list_b.length > 0)
		sort(&list_b, &list_a, COMP_BIGGER);
	assert(is_sorted(list_a, ascending) == true);
}