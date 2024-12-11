/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:14:28 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/11 16:16:50 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

void	test_rotate()
{
	// ===== INIT ===== //
	t_list	list_a;
	t_list	list_b;
	char	*args[] = {"./push_swap", "1", "2", "3", "4", NULL};
	parse_args(5, args, &list_a, &list_b);
	// ================ //

	rotate(&list_a);
	assertLinkedList(list_a.list, (int[]){2, 3, 4, 1}, 4);
}
