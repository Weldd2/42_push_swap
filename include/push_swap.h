/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:49:33 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/16 13:51:04 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* Inclusion des bibliothèques standard */
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include "str.h"  // fonctions str de libft

/* Définition des limites des entiers */
# define INT_MIN -2147483648
# define INT_MAX 2147483647

/* 
 * Structure représentant un nœud dans une liste chaînée.
 * Contient une valeur entière et un pointeur vers le nœud suivant.
 */
typedef struct s_node
{
	int				value;   // Valeur de l'élément
	struct s_node	*next;   // Pointeur vers le nœud suivant
}	t_node;

/* 
 * Structure contenant les coûts de rotation pour un élément et sa cible.
 * e_up_cost: Coût de rotation vers le haut de la liste source.
 * e_down_cost: Coût de rotation vers le bas de la liste source.
 * t_up_cost: Coût de rotation vers le haut de la liste cible.
 * t_down_cost: Coût de rotation vers le bas de la liste cible.
 */
typedef struct s_rotation_costs {
	int	e_up_cost;
	int	e_down_cost;
	int	t_up_cost;
	int	t_down_cost;
}	t_rotation_costs;

/* 
 * Enumération des différents cas de rotation possibles.
 */
typedef enum e_rotation_case {
	BOTH_UP,          // Rotation vers le haut des deux listes
	BOTH_DOWN,        // Rotation vers le bas des deux listes
	FROM_UP_TO_DOWN,  // Rotation vers le haut de la source et vers le bas de la cible
	FROM_DOWN_TO_UP   // Rotation vers le bas de la source et vers le haut de la cible
}	t_rotation_case;

/* 
 * Structure représentant un mouvement potentiel.
 * elem_index: Index de l'élément dans la liste source.
 * elem_value: Valeur de l'élément.
 * target_index: Index de la position cible dans la liste cible.
 * target_value: Valeur de la position cible.
 * costs: Coûts de rotation associés au mouvement.
 * rotation_case: Cas de rotation déterminé pour ce mouvement.
 */
typedef struct s_move {
	int					element_index;
	int					element_value;
	int					target_index;
	int					target_value;
	t_rotation_costs	costs;
	t_rotation_case		rotation_case;
}	t_move;

/* 
 * Structure représentant une liste chaînée.
 * list: Pointeur vers le premier nœud de la liste.
 * length: Nombre d'éléments dans la liste.
 * name: Nom de la liste (par exemple, "A" ou "B").
 * max: Valeur maximale dans la liste.
 * min: Valeur minimale dans la liste.
 */
typedef struct s_list
{
	t_node	*head;    // Pointeur vers le premier nœud
	int		length;   // Nombre d'éléments
	char	*name;    // Nom de la liste
	int		max;      // Valeur maximale
	int		min;      // Valeur minimale
}	t_list;

/* 
 * Contexte pour la recherche de l'élément le plus proche.
 */
typedef struct s_find_closest_context
{
	t_node	*current_node; // Nœud actuel dans la recherche
	int		index;         // Index actuel
	int		found;         // Indicateur si un élément proche a été trouvé
	int		closest_value; // Valeur la plus proche trouvée
	int		closest_index; // Index de la valeur la plus proche
}	t_find_closest_context;

/* 
 * Contexte pour déterminer le meilleur mouvement.
 */
typedef struct s_best_move_context
{
	t_move				best_move;   // Meilleur mouvement trouvé
	t_node				*current_node; // Nœud actuel dans l'évaluation
	int					index;         // Index actuel
	int					min_cost;      // Coût minimum trouvé
	int					local_index;   // Index local pour les rotations
	t_rotation_costs	rotation_costs; // Coûts de rotation actuels
	t_rotation_case		rotation_case;  // Cas de rotation actuel
}	t_best_move_context;

/* 
 * Enumération des types de comparaison pour la recherche.
 */
typedef enum e_comparison_type {
	COMPARE_SMALLEST,
	COMPARE_LARGEST
}	t_comparison_type;

// ===== INIT ===== //
void	init_t_lists(t_list *list_a, t_list *list_b, int *values, int nb_val);
// ================ //

void	free_t_list(t_list list);
int		get_elem_by_index(t_list list, int index);
void	turk_algorithm(t_list *list_a, t_list *list_b);
t_node	*ft_list_to_node(t_list *list, int argc, char **argv);
int		find_closest_index(int value, t_list list, t_comparison_type type);
t_move	get_best_move(t_list from, t_list target, t_comparison_type type);
void	sort(t_list *from, t_list *to, t_comparison_type type);
void	sort_3(t_list *list);
void	parse_args(int argc, char **argv, t_list *list_a, t_list *list_b);

long long	ft_atoi(const char *nptr);
bool		has_duplicate(int *values, int nb_values, int value);

// ===== OPE ===== //
void	swap(t_list *list);
void	push(t_list *l_from, t_list *l_to);
void	rotate(t_list *list);
void	rrotate(t_list *list);
void	rotate_ab(t_list *a, t_list *b);
void	rrotate_ab(t_list *a, t_list *b);
// =============== //

int		find_max_index(t_node *n);
int		find_max_value(t_node *n);
int		find_min_index(t_node *n);
int		find_min_value(t_node *n);
int		max(int a, int b);
int		min(int a, int b);

void	print_list(t_list list, char *name);
bool	is_sorted(t_list list, int (*direction)(int, int));
int		descending(int a, int b);
int		ascending(int a, int b);
void	ft_error(void);

t_rotation_case	determine_rot_case(t_rotation_costs costs, int *local_min);
bool	update_best_move(t_move *best, int *min_cost, int local_min, t_rotation_costs co);
t_move	get_best_move(t_list from, t_list target, t_comparison_type type);

#endif