/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:37:47 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/07 18:51:11 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_init_node(int value)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->next = NULL;
	// n->prev = NULL;
	return (n);
}

void	ft_add_front_node(t_node **lst, t_node *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_node	*ft_list_to_node(int argc, char **argv)
{
	int		i;
	t_node	*current;
	t_node	*prev;

	i = argc - 1;
	prev = NULL;
	while (i >= 1)
	{
		current = ft_init_node(ft_atoi(argv[i]));
		current->next = prev;
		prev = current;
		i--;
	}
	return (current);
}
