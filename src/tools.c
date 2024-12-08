/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:06:46 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/08 00:04:30 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_list *list)
{
	t_node	*current;

	current = list->list;
	while (current != NULL)
	{
		printf("%d", current->value);
		if (current->next != NULL)
			printf(" ");
		current = current->next;
	}
	printf("\n");
}
