/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:14:28 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/11 16:16:50 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

void	test_swap()
{
	// ===== INIT ===== //
	t_list	list_a;
	t_list	list_b;
	char	*args[] = {"./push_swap", "1", "2", "3", "4", NULL};
	parse_args(5, args, &list_a, &list_b);
	// ================ //
	
	list_a.list->value = 1;
	list_a.list->next->value = 2;
	swap(&list_a);
	assertLinkedList(list_a.list, (int[]){2, 1, 3, 4}, 4);
}
