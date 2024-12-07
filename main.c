/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:59:15 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/07 18:55:05 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(t_node **lst)
{
	t_node	*current;

	current = *lst;
	while (current != NULL)
	{
		printf("%d", current->value);
		if (current->next != NULL)
			printf(" ");
		current = current->next;
	}
	printf("\n");
}

void init_t_nodes(t_node **a, t_node **b, int argc, char **argv)
{
	*a = ft_list_to_node(argc, argv);
	if (*a == NULL)
	{
		write(1, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	*b = NULL;
}

void init_t_lists(t_list **list_a, t_list **list_b)
{
	*list_a = malloc(sizeof(t_list));
	if (*list_a == NULL)
	{
		write(1, "Error\n", 7);
		exit(EXIT_FAILURE);
	}

	*list_b = malloc(sizeof(t_list));
	if (*list_b == NULL)
	{
		write(1, "Error\n", 7);
		free(*list_a);
		exit(EXIT_FAILURE);
	}
	(*list_a)->list = NULL;
	(*list_a)->median = 0;
	(*list_a)->min = 0;
	(*list_a)->max = 0;
	(*list_b)->list = NULL;
	(*list_b)->median = 0;
	(*list_b)->min = 0;
	(*list_b)->max = 0;
}


int main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	t_node	*node_a;
	t_node	*node_b;

	// Initialisation des listes
	init_t_lists(&list_a, &list_b);

	// Initialisation des nœuds
	init_t_nodes(&node_a, &node_b, argc, argv);

	// Assignation des nœuds aux listes
	list_a->list = node_a;
	list_b->list = node_b;

	turk_algorithm(&list_a, &list_b);
	print_list(&(list_a->list));
	print_list(&(list_b->list));

	// Libération des ressources allouées (à implémenter)
	// free_nodes(node_a);
	free(list_a);
	free(list_b);

	return (0); // Retourner 0 pour indiquer que le programme s'est terminé avec succès
	// TODO : Gérer les erreurs de doublons et le cas où la chaîne en entrée (split)
	// TODO : Implémenter les fonctions de libération de la mémoire
}
