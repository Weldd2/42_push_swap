/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 02:44:59 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/12 15:08:49 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

void	test_is_sorted()
{
	// ===== INIT ===== //
	t_list	list_a;
	t_list	list_b;
	char	*args[] = {"./push_swap", "1", "2", "3", "4", "5", "6", "7", NULL};
	parse_args(8, args, &list_a, &list_b);
	// ================ //
	assert(is_sorted(list_a, ascending) == true);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args1[] = {"./push_swap", "1", "2", "3", "4", "5", "6", "-1", NULL};
	parse_args(8, args1, &list_a, &list_b);
	assert(is_sorted(list_a, ascending) == true);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args2[] = {"./push_swap", "7", "1", "2", "3", "4", "5", "6", NULL};
	parse_args(8, args2, &list_a, &list_b);
	assert(is_sorted(list_a, ascending) == true);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args3[] = {"./push_swap", "1", "2", "3", "-4", "8", "6", "7", NULL};
	parse_args(8, args3, &list_a, &list_b);
	assert(is_sorted(list_a, ascending) == false);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args4[] = {"./push_swap", "10", "25", "0", "90", NULL};
	parse_args(5, args4, &list_a, &list_b);
	assert(is_sorted(list_a, ascending) == false);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args5[] = {"./push_swap", "25", "0", "90", NULL};
	parse_args(4, args5, &list_a, &list_b);
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
	parse_args(8, args, &list_a, &list_b);
	// ================ //
	assert(is_sorted(list_a, descending) == true);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args1[] = {"./push_swap", "6", "5", "4", "3", "2", "1", "7", NULL};
	parse_args(8, args1, &list_a, &list_b);
	assert(is_sorted(list_a, descending) == true);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args2[] = {"./push_swap", "5", "4", "3", "2", "1", "7", "6", NULL};
	parse_args(8, args2, &list_a, &list_b);
	assert(is_sorted(list_a, descending) == true);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args3[] = {"./push_swap", "5", "4", "3", "2", "1", "6", "7", NULL};
	parse_args(8, args3, &list_a, &list_b);
	assert(is_sorted(list_a, descending)== false);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args4[] = {"./push_swap", "10", "25", "0", "90", NULL};
	parse_args(5, args4, &list_a, &list_b);
	assert(is_sorted(list_a, descending)== false);
	free_t_list(list_a);
	free_t_list(list_b);

	char	*args5[] = {"./push_swap", "25", "0", "90", NULL};
	parse_args(4, args5, &list_a, &list_b);
	assert(is_sorted(list_a, descending) == true);
	free_t_list(list_a);
	free_t_list(list_b);
}
