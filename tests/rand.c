/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:49:11 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/08 00:49:31 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// Fonction pour vérifier si une valeur existe déjà dans le tableau
int		value_exists(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (1);
		i++;
	}
	return (0);
}

// Fonction pour remplir le tableau avec des valeurs aléatoires uniques
void	fill_unique_random(int *array, int size, int min, int max)
{
	int	i;
	int	num;

	if ((max - min + 1) < size)
	{
		printf("Erreur : La plage de valeurs est trop petite pour la taille du tableau.\n");
		exit(1);
	}
	
	i = 0;
	while (i < size)
	{
		num = rand() % (max - min + 1) + min;
		if (!value_exists(array, i, num))
		{
			array[i] = num;
			i++;
		}
	}
}
