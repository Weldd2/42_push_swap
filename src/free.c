/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:44:48 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/08 21:56:27 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_t_list(t_list *list)
{
	t_node	*next;
	t_node	*current;

	if (!list)
	{
		write(1, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	current = list->list;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(list);
}
