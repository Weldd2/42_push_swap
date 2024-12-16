/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:15:49 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 19:53:43 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Fonction pour effectuer le reverse rotate d'une liste sans afficher */
static void	perform_reverse_rotate(t_list *list)
{
	t_node	*first;
	t_node	*before_last;
	t_node	*last;

	if (list == NULL || list->head == NULL || list->head->next == NULL)
		return ;
	first = list->head;
	before_last = first;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = first;
	list->head = last;
}

void	rrotate(t_list *list)
{
	perform_reverse_rotate(list);
	write(1, "rr", 2);
	write(1, list->name, 1);
	write(1, "\n", 1);
}

void	rrotate_ab(t_list *a, t_list *b)
{
	int	rrotated;

	rrotated = 0;
	if (a != NULL && a->head != NULL && a->head->next != NULL)
	{
		perform_reverse_rotate(a);
		rrotated = 1;
	}
	if (b != NULL && b->head != NULL && b->head->next != NULL)
	{
		perform_reverse_rotate(b);
		rrotated = 1;
	}
	if (rrotated)
		write(1, "rrr\n", 4);
}
