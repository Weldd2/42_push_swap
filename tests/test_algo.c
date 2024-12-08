/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:00:13 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/08 10:09:34 by antoinemura      ###   ########.fr       */
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
	init_t_lists(&list_a, &list_b);
	init_t_nodes(&list_a, &list_b, 7, args);
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
