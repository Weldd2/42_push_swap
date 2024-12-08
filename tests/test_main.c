#include "test_push_swap.h"

int main(void)
{
	test_init();
	printf("\033[0;32m✔ Test INIT OK.\033[0m\n");
	// OPERATIONS
	test_swap();
	printf("\033[0;32m✔ Test SWAP OK.\033[0m\n");
	test_push();
	printf("\033[0;32m✔ Test PUSH OK.\033[0m\n");
	test_rotate();
	printf("\033[0;32m✔ Test ROTATE OK.\033[0m\n");
	test_rrotate();
	printf("\033[0;32m✔ Test RROTATE OK.\033[0m\n");

	test_closest_smaller();
	printf("\033[0;32m✔ Test CLOSEST SMALLER OK.\033[0m\n");
	// test_calculate_smallest_move_cost();
	// printf("\033[0;32m✔ Test SMALLEST MOVE COST OK.\033[0m\n");

	test_is_sorted();
	printf("\033[0;32m✔ Test IS SORTED OK.\033[0m\n");

	printf("Tous les tests ont réussi.\n");
	// Libération des ressources allouées
	return (0);
}
