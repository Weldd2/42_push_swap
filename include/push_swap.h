/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:49:33 by antoinemura       #+#    #+#             */
/*   Updated: 2024/12/17 18:34:56 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* Inclusion des bibliothèques standard */
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include "str.h"
# include "mem.h"

/* Définition des limites des entiers */
# define INT_MIN -2147483648
# define INT_MAX 2147483647

/* 
 * Structure représentant un nœud dans une liste chaînée.
 * Contient une valeur entière et un pointeur vers le nœud suivant.
 */
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

/* 
 * Structure contenant les coûts de rotation pour un élément et sa cible.
 * e_up_cost: Coût de rotation vers le haut de la liste source.
 * e_down_cost: Coût de rotation vers le bas de la liste source.
 * t_up_cost: Coût de rotation vers le haut de la liste cible.
 * t_down_cost: Coût de rotation vers le bas de la liste cible.
 */
typedef struct s_rotation_costs
{
	int	e_up_cost;
	int	e_down_cost;
	int	t_up_cost;
	int	t_down_cost;
}	t_rotation_costs;

/* 
 * Enumération des différents cas de rotation possibles.
 */
typedef enum e_rotation_case
{
	BOTH_UP,
	BOTH_DOWN,
	FROM_UP_TO_DOWN,
	FROM_DOWN_TO_UP
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
typedef struct s_move
{
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
	t_node	*head;
	int		length;
	char	*name;
	int		max;
	int		min;
}	t_list;

/* 
 * Contexte pour la recherche de l'élément le plus proche.
 */
typedef struct s_find_closest_context
{
	t_node	*current_node;
	int		index;
	int		found;
	int		closest_value;
	int		closest_index;
}	t_find_closest_context;

/* 
 * Contexte pour déterminer le meilleur mouvement.
 */
typedef struct s_best_move_context
{
	t_move				best_move;
	t_node				*current_node;
	int					index;
	int					min_cost;
	int					local_index;
	t_rotation_costs	rotation_costs;
	t_rotation_case		rotation_case;
}	t_best_move_context;

/* 
 * Enumération des types de comparaison pour la recherche.
 */
typedef enum e_comparison_type
{
	COMPARE_SMALLEST,
	COMPARE_LARGEST
}	t_comparison_type;

/**
 * @brief Initialise les listes `list_a` et `list_b` avec les valeurs fournies.
 *
 * @param list_a Pointeur vers la première liste à initialiser.
 * @param list_b Pointeur vers la deuxième liste à initialiser.
 * @param values Tableau d'entiers contenant les valeurs à ajouter.
 * @param nb_val Nombre de valeurs dans le tableau `values`.
 */
void			init_t_lists(
					t_list *list_a, t_list *list_b, int *values, int nb_val);

/**
 * @brief Libère la mémoire allouée pour une liste.
 *
 * @param list La liste à libérer.
 */
void			free_t_list(t_list list);

/**
 * @brief Récupère la valeur d'un élément dans la liste à un index spécifique.
 *
 * @param list La liste dans laquelle chercher.
 * @param index L'index de l'élément à récupérer.
 * @return La valeur de l'élément trouvé.
 */
int				get_elem_by_index(t_list list, int index);

/**
 * @brief Exécute l'algorithme principal de tri de Turk.
 *
 * @param list_a Pointeur vers la liste A.
 * @param list_b Pointeur vers la liste B.
 */
void			turk_algorithm(t_list *list_a, t_list *list_b);

/**
 * @brief Trouve l'index de la valeur la plus proche selon le type de 
 * comparaison.
 *
 * @param value La valeur de référence.
 * @param list La liste dans laquelle chercher.
 * @param type Type de comparaison (par exemple, le + petit ou le + grand).
 * @return L'index de la valeur la plus proche.
 */
int				find_closest_index(
					int value, t_list list, t_comparison_type type);

/**
 * @brief Détermine le meilleur mouvement à effectuer entre deux listes.
 *
 * @param from La liste source.
 * @param target La liste cible.
 * @param type Type de comparaison pour déterminer le meilleur mouvement.
 * @return Structure contenant les informations du meilleur mouvement.
 */
t_move			get_best_move(
					t_list from, t_list target, t_comparison_type type);

/**
 * @brief Trie les éléments d'une liste en les déplaçant vers une autre liste.
 *
 * @param from Pointeur vers la liste source.
 * @param to Pointeur vers la liste cible.
 * @param type Type de comparaison pour le tri.
 */
void			sort(t_list *from, t_list *to, t_comparison_type type);

/**
 * @brief Trie une liste contenant exactement trois éléments.
 *
 * @param list Pointeur vers la liste à trier.
 */
void			sort_3(t_list *list);

/**
 * @brief Analyse les arguments de la ligne de commande et les parse
 *  dans les listes.
 *
 * @param argc Nombre d'arguments.
 * @param argv Tableau de chaînes de caractères des arguments.
 * @param list_a Pointeur vers la liste A.
 * @param list_b Pointeur vers la liste B.
 */
void			parse_args(
					int argc, char **argv, t_list *list_a, t_list *list_b);

/**
 * @brief Convertit une chaîne de caractères en un entier de type `long long`.
 *
 * @param nptr Pointeur vers la chaîne de caractères à convertir.
 * @return La valeur entière convertie.
 */
long long		ft_atoi(const char *nptr);

/**
 * @brief Vérifie si une valeur est dupliquée dans un tableau de valeurs.
 *
 * @param values Tableau d'entiers à vérifier.
 * @param nb_values Nombre de valeurs dans le tableau.
 * @param value La valeur à vérifier.
 * @return `true` si un duplicata est trouvé, sinon `false`.
 */
bool			has_duplicate(int *values, int nb_values, int value);

/**
 * @brief Échange les deux premiers éléments d'une liste.
 *
 * @param list Pointeur vers la liste à modifier.
 */
void			swap(t_list *list);

/**
 * @brief Déplace le premier élément d'une liste source vers une liste cible.
 *
 * @param l_from Pointeur vers la liste source.
 * @param l_to Pointeur vers la liste cible.
 */
void			push(t_list *l_from, t_list *l_to);

/**
 * @brief Effectue une rotation vers le haut d'une liste 
 * (le premier élément devient le dernier).
 *
 * @param list Pointeur vers la liste à modifier.
 */
void			rotate(t_list *list);

/**
 * @brief Effectue une rotation vers le bas d'une liste 
 * (le dernier élément devient le premier).
 *
 * @param list Pointeur vers la liste à modifier.
 */
void			rrotate(t_list *list);

/**
 * @brief Effectue une rotation simultanée vers le haut des deux listes.
 *
 * @param a Pointeur vers la première liste.
 * @param b Pointeur vers la deuxième liste.
 */
void			rotate_ab(t_list *a, t_list *b);

/**
 * @brief Effectue une rotation simultanée vers le bas des deux listes.
 *
 * @param a Pointeur vers la première liste.
 * @param b Pointeur vers la deuxième liste.
 */
void			rrotate_ab(t_list *a, t_list *b);

/**
 * @brief Trouve l'index de la valeur maximale dans une liste de nœuds.
 *
 * @param n Pointeur vers le premier nœud de la liste.
 * @return L'index de la valeur maximale.
 */
int				find_max_index(t_node *n);

/**
 * @brief Trouve la valeur maximale dans une liste de nœuds.
 *
 * @param n Pointeur vers le premier nœud de la liste.
 * @return La valeur maximale trouvée.
 */
int				find_max_value(t_node *n);

/**
 * @brief Trouve l'index de la valeur minimale dans une liste de nœuds.
 *
 * @param n Pointeur vers le premier nœud de la liste.
 * @return L'index de la valeur minimale.
 */
int				find_min_index(t_node *n);

/**
 * @brief Trouve la valeur minimale dans une liste de nœuds.
 *
 * @param n Pointeur vers le premier nœud de la liste.
 * @return La valeur minimale trouvée.
 */
int				find_min_value(t_node *n);

/**
 * @brief Retourne le maximum de deux entiers.
 *
 * @param a Premier entier.
 * @param b Deuxième entier.
 * @return Le plus grand des deux entiers.
 */
int				max(int a, int b);

/**
 * @brief Retourne le minimum de deux entiers.
 *
 * @param a Premier entier.
 * @param b Deuxième entier.
 * @return Le plus petit des deux entiers.
 */
int				min(int a, int b);

/**
 * @brief Affiche les éléments d'une liste avec son nom.
 *
 * @param list La liste à afficher.
 * @param name Nom de la liste pour l'affichage.
 */
void			print_list(t_list list, char *name);

/**
 * @brief Vérifie si une liste est triée selon un critère de direction.
 *
 * @param list La liste à vérifier.
 * @param direction Pointeur vers une fonction définissant la direction du tri.
 * @return `true` si la liste est triée, sinon `false`.
 */
bool			is_sorted(t_list list, int (*direction)(int, int));

/**
 * @brief Fonction de comparaison pour un tri décroissant.
 *
 * @param a Premier entier à comparer.
 * @param b Deuxième entier à comparer.
 * @return Résultat de la comparaison.
 */
int				descending(int a, int b);

/**
 * @brief Fonction de comparaison pour un tri croissant.
 *
 * @param a Premier entier à comparer.
 * @param b Deuxième entier à comparer.
 * @return Résultat de la comparaison.
 */
int				ascending(int a, int b);

/**
 * @brief Affiche un message d'erreur et termine le programme.
 */
void			ft_error(void);

/**
 * @brief Détermine le cas de rotation optimal basé sur les coûts de rotation.
 *
 * @param costs Structure contenant les coûts de rotation.
 * @param local_min Pointeur vers l'entier où le coût minimum sera stocké.
 * @return Le cas de rotation déterminé.
 */
t_rotation_case	determine_rot_case(
					t_rotation_costs costs, int *local_min);

/**
 * @brief Met à jour le meilleur mouvement trouvé si le coût local
 * est inférieur au minimum actuel.
 *
 * @param best Pointeur vers la structure du meilleur mouvement actuel.
 * @param min_cost Pointeur vers le coût minimum actuel.
 * @param local_min Le coût local à comparer.
 * @param co Structure contenant les coûts de rotation.
 * @return `true` si le meilleur mouvement a été mis à jour, sinon `false`.
 */
bool			update_best_move(
					t_move *best, int *min_cost, int local_min, \
					t_rotation_costs co);

/**
 * @brief Trie les éléments d'une liste source vers une liste 
 * cible en fonction du type de comparaison.
 *
 * @param from Pointeur vers la liste source.
 * @param to Pointeur vers la liste cible.
 * @param type Type de comparaison pour le tri.
 */
void			sort(t_list *from, t_list *to, t_comparison_type type);

/**
 * @brief Applique le cas de rotation déterminé entre deux listes.
 *
 * @param from Pointeur vers la liste source.
 * @param to Pointeur vers la liste cible.
 * @param costs Structure contenant les coûts de rotation.
 * @param rotation_case Le cas de rotation à appliquer.
 */
void			apply_rotation_case(
					t_list *from, t_list *to, t_rotation_costs costs, \
					t_rotation_case rotation_case);

/**
 * @brief Effectue une rotation simultanée vers le haut des deux
 * listes avec des coûts spécifiques.
 *
 * @param from Pointeur vers la première liste.
 * @param to Pointeur vers la deuxième liste.
 * @param e_up_cost Coût de rotation vers le haut pour la liste `from`.
 * @param t_up_cost Coût de rotation vers le haut pour la liste `to`.
 */
void			rotate_both_up(
					t_list *from, t_list *to, int e_up_cost, int t_up_cost);

/**
 * @brief Effectue une rotation simultanée vers le bas des deux
 * listes avec des coûts spécifiques.
 *
 * @param from Pointeur vers la première liste.
 * @param to Pointeur vers la deuxième liste.
 * @param e_down_cost Coût de rotation vers le bas pour la liste `from`.
 * @param t_down_cost Coût de rotation vers le bas pour la liste `to`.
 */
void			rotate_both_down(
					t_list *from, t_list *to, int e_down_cost, int t_down_cost);

/**
 * @brief Effectue des rotations opposées où la liste `from` est tournée vers le
 * haut et la liste `to` vers le bas.
 *
 * @param from Pointeur vers la liste source.
 * @param elem_cost Coût de rotation vers le haut pour la liste `from`.
 * @param to Pointeur vers la liste cible.
 * @param target_cost Coût de rotation vers le bas pour la liste `to`.
 */
void			opposite_rotations_elem_up_target_down(
					t_list *from, int elem_cost, t_list *to, int target_cost);

/**
 * @brief Effectue des rotations opposées où la liste `from` est tournée vers
 * le bas et la liste `to` vers le haut.
 *
 * @param from Pointeur vers la liste source.
 * @param elem_cost Coût de rotation vers le bas pour la liste `from`.
 * @param to Pointeur vers la liste cible.
 * @param target_cost Coût de rotation vers le haut pour la liste `to`.
 */
void			opposite_rotations_elem_down_target_up(
					t_list *from, int elem_cost, t_list *to, int target_cost);

#endif