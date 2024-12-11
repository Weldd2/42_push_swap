/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:59:15 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/11 01:59:07 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_list	list_a;
	t_list	list_b;

	init_t_lists(&list_a, &list_b, argc, argv);
	turk_algorithm(&list_a, &list_b);
	print_list(list_a, "a");
	print_list(list_b, "b");
	return (0);
}
// TODO : Gérer les erreurs de doublons et le cas où la chaîne en entrée (split)
// TODO : Implémenter les fonctions de libération de la mémoire
// TODO : Implémenter la gestion quand params = 4
// TODO : implémenter un rotate et rrotate intelligent avec mediane
