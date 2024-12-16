/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:16:55 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 19:53:11 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Fonction pour effectuer la rotation d'une liste sans afficher */
static void	perform_rotate(t_list *list)
{
	t_node	*first;
	t_node	*last;

	if (list == NULL || list->head == NULL || list->head->next == NULL)
		return ;
	first = list->head;
	last = first;
	while (last->next)
		last = last->next;
	list->head = first->next;
	first->next = NULL;
	last->next = first;
}

void	rotate(t_list *list)
{
	perform_rotate(list);
	write(1, "r", 1);
	write(1, list->name, 1);
	write(1, "\n", 1);
}

void	rotate_ab(t_list *a, t_list *b)
{
	int	rotated;

	rotated = 0;
	if (a != NULL && a->head != NULL && a->head->next != NULL)
	{
		perform_rotate(a);
		rotated = 1;
	}
	if (b != NULL && b->head != NULL && b->head->next != NULL)
	{
		perform_rotate(b);
		rotated = 1;
	}
	if (rotated)
		write(1, "rr\n", 3);
}
