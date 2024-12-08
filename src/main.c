/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:59:15 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/08 21:42:31 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	// Initialisation des listes
	init_t_lists(&list_a, &list_b, argc, argv);

	turk_algorithm(&list_a, &list_b);
	print_list(list_a, "a");
	// Libération des ressources allouées (à implémenter)
	// free_nodes(node_a);
	free(list_a);
	free(list_b);

	return (0); // Retourner 0 pour indiquer que le programme s'est terminé avec succès
	// TODO : Gérer les erreurs de doublons et le cas où la chaîne en entrée (split)
	// TODO : Implémenter les fonctions de libération de la mémoire
}
