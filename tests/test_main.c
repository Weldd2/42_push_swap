#include "test_push_swap.h"

int main(void)
{
	printf("\033[0;32m✔ Testing INIT...\033[0m\n");
	test_init();
	printf("\033[0;32m✔ Test INIT OK.\033[0m\n");
	// OPERATIONS
	printf("\033[0;32m✔ Testing SWAP ...\033[0m\n");
	test_swap();
	printf("\033[0;32m✔ Test SWAP OK.\033[0m\n");

	printf("\033[0;32m✔ Testing PUSH ...\033[0m\n");
	test_push();
	printf("\033[0;32m✔ Test PUSH OK.\033[0m\n");

	printf("\033[0;32m✔ Testing ROTATE ...\033[0m\n");
	test_rotate();
	printf("\033[0;32m✔ Test ROTATE OK.\033[0m\n");

	printf("\033[0;32m✔ Testing RROTATE ...\033[0m\n");
	test_rrotate();
	printf("\033[0;32m✔ Test RROTATE OK.\033[0m\n");

	printf("\033[0;32m✔ Testing CLOSEST ...\033[0m\n");
	test_closest();
	printf("\033[0;32m✔ Test CLOSEST OK.\033[0m\n");

	printf("\033[0;32m✔ Testing IS SORTED ...\033[0m\n");
	test_is_sorted();
	printf("\033[0;32m✔ Test IS SORTED OK.\033[0m\n");

	printf("\033[0;32m✔ Testing IS REVERSE SORTED ...\033[0m\n");
	test_is_reverse_sorted();
	printf("\033[0;32m✔ Test IS REVERSE SORTED OK.\033[0m\n");

	printf("\033[0;32m✔ Testing SMALLEST MOVE COST ...\033[0m\n");
	test_get_best_move();
	printf("\033[0;32m✔ Test SMALLEST MOVE COST OK.\033[0m\n");

	printf("\033[0;32m✔ Testing SORT ...\033[0m\n");
	test_sort();
	printf("\033[0;32m✔ Test SORT OK.\033[0m\n");

	printf("Tous les tests ont réussi.\n");
	// Libération des ressources allouées
	return (0);
}
