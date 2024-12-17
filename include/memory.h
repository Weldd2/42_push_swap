/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 22:16:01 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/17 01:05:54 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>

# define ARENA_BLOC_SIZE 65536

typedef struct s_arena_mem_block_list
{
	struct s_arena_mem_block_list	*next;
	void							*block;
}	t_arena_mem_block_list;

/**
 * @brief Libère toute la mémoire allouée par l'arène.
 *
 * Cette fonction parcourt tous les blocs de l'arène et les libère,
 * puis réinitialise la tête de l'arène à NULL.
 */
void	ft_free_arena(void);

/**
 * @brief Alloue de la mémoire dans l'arène.
 *
 * Cette fonction alloue un bloc de mémoire de la taille spécifiée
 * à partir de l'arène. Si l'arène n'a pas assez d'espace, un nouveau
 * bloc est ajouté.
 *
 * @param size Taille de la mémoire à allouer.
 * @return void* Pointeur vers la mémoire allouée ou NULL si la taille est zéro.
 */
void	*ft_arena_alloc(size_t size);

#endif