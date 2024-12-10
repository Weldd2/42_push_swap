/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 02:44:59 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/10 18:40:46 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

void	test_is_sorted()
{
	// ===== INIT ===== //
	t_list	list_a;
	t_list	list_b;
	char	*args[] = {"./push_swap", "1", "2", "3", "4", "5", "6", "7", NULL};
	init_t_lists(&list_a, &list_b, 8, args);
	// ================ //
	print_list(list_a, "a");
	assert(is_sorted(list_a, ascending) == true);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args1[] = {"./push_swap", "1", "2", "3", "4", "5", "6", "-1", NULL};
	init_t_lists(&list_a, &list_b, 8, args1);
	assert(is_sorted(list_a, ascending) == true);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args2[] = {"./push_swap", "7", "1", "2", "3", "4", "5", "6", NULL};
	init_t_lists(&list_a, &list_b, 8, args2);
	assert(is_sorted(list_a, ascending) == true);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args3[] = {"./push_swap", "1", "2", "3", "-4", "8", "6", "7", NULL};
	init_t_lists(&list_a, &list_b, 8, args3);
	assert(is_sorted(list_a, ascending) == false);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args4[] = {"./push_swap", "10", "25", "0", "90", NULL};
	init_t_lists(&list_a, &list_b, 5, args4);
	assert(is_sorted(list_a, ascending) == false);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args5[] = {"./push_swap", "25", "0", "90", NULL};
	init_t_lists(&list_a, &list_b, 4, args5);
	assert(is_sorted(list_a, ascending) == false);
	free_t_list(list_a);
	free_t_list(list_b);
}

void	test_is_reverse_sorted()
{
	// ===== INIT ===== //
	t_list	list_a;
	t_list	list_b;
	char	*args[] = {"./push_swap", "7", "6", "5", "4", "3", "2", "1", NULL};
	init_t_lists(&list_a, &list_b, 8, args);
	// ================ //
	assert(is_sorted(list_a, descending) == true);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args1[] = {"./push_swap", "6", "5", "4", "3", "2", "1", "7", NULL};
	init_t_lists(&list_a, &list_b, 8, args1);
	assert(is_sorted(list_a, descending) == true);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args2[] = {"./push_swap", "5", "4", "3", "2", "1", "7", "6", NULL};
	init_t_lists(&list_a, &list_b, 8, args2);
	assert(is_sorted(list_a, descending) == true);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args3[] = {"./push_swap", "5", "4", "3", "2", "1", "6", "7", NULL};
	init_t_lists(&list_a, &list_b, 8, args3);
	assert(is_sorted(list_a, descending)== false);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args4[] = {"./push_swap", "10", "25", "0", "90", NULL};
	init_t_lists(&list_a, &list_b, 5, args4);
	assert(is_sorted(list_a, descending)== false);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args5[] = {"./push_swap", "25", "0", "90", NULL};
	init_t_lists(&list_a, &list_b, 4, args5);
	assert(is_sorted(list_a, descending) == true);
	free_t_list(list_a);
	free_t_list(list_b);
}
