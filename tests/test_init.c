/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:14:13 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 13:31:50 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

// Exemple de test
void	test_init()
{
	t_list	list_a;
	t_list	list_b;
	char	*args[] = {"./push_swap", "1 2 3 4"};

	// Initialisation des listes
	parse_args(2, args, &list_a, &list_b);

	// ===== LIST_A ===== //
	assert(list_a.length == 4);
	assert(list_a.max == 4);
	assert(list_a.min == 1);
	assert(list_a.head->value == 1);
	assert(list_a.head->next->value == 2);
	assert(list_a.head->next->next->value == 3);
	assert(list_a.head->next->next->next->value == 4);
	// ================== //

	// ===== LIST_B ===== //
	assert(list_b.length == 0);
	assert(list_b.max == INT_MIN);
	assert(list_b.min == INT_MAX);
	assert(list_b.head == NULL);
	// ================== //

	// Vérifie que la liste se termine correctement
	if (list_a.head->next->next->next->next != NULL)
	{
		fprintf(stderr, "Assertion échouée: la liste ne se termine pas correctement.\n");
		ft_error();
	}
}
