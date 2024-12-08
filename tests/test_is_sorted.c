/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 02:44:59 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/09 17:59:55 by antoinemura      ###   ########.fr       */
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

	char	*args4[] = {"./push_swap", "10", "25", "0", "90", NULL};
	init_t_lists(&list_a, &list_b, 5, args4);
	assert(is_sorted(list_a) == 1);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args5[] = {"./push_swap", "25", "0", "90", NULL};
	init_t_lists(&list_a, &list_b, 4, args5);
	assert(is_sorted(list_a) == 1);
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
	assert(is_reverse_sorted(list_a) == 0);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args1[] = {"./push_swap", "6", "5", "4", "3", "2", "1", "7", NULL};
	init_t_lists(&list_a, &list_b, 8, args1);
	assert(is_reverse_sorted(list_a) == 0);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args2[] = {"./push_swap", "5", "4", "3", "2", "1", "7", "6", NULL};
	init_t_lists(&list_a, &list_b, 8, args2);
	assert(is_reverse_sorted(list_a) == 0);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args3[] = {"./push_swap", "5", "4", "3", "2", "1", "6", "7", NULL};
	init_t_lists(&list_a, &list_b, 8, args3);
	assert(is_reverse_sorted(list_a) == 1);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args4[] = {"./push_swap", "10", "25", "0", "90", NULL};
	init_t_lists(&list_a, &list_b, 5, args4);
	assert(is_reverse_sorted(list_a) == 1);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args5[] = {"./push_swap", "25", "0", "90", NULL};
	init_t_lists(&list_a, &list_b, 4, args5);
	assert(is_reverse_sorted(list_a) == 0);
	free_t_list(list_a);
	free_t_list(list_b);
}
