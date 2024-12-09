/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:44:48 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/09 18:08:23 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_t_list(t_list list)
{
	t_node	*next;
	t_node	*current;

	current = list.list;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
