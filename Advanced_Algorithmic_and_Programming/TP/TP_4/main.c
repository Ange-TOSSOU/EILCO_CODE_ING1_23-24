#include "arbre_binaire_recherche.h"

int main()
{
  Node *arbre = NULL;

  arbre = pushRecursive_AT(arbre, create_AT(20));
  arbre = pushRecursive_AT(arbre, create_AT(6));
  arbre = pushRecursive_AT(arbre, create_AT(31));
  arbre = pushRecursive_AT(arbre, create_AT(5));
  arbre = pushRecursive_AT(arbre, create_AT(10));
  arbre = pushRecursive_AT(arbre, create_AT(25));
  arbre = pushRecursive_AT(arbre, create_AT(38));
  arbre = pushRecursive_AT(arbre, create_AT(31));
  arbre = pushRecursive_AT(arbre, create_AT(27));
  arbre = pushRecursive_AT(arbre, create_AT(31));
  arbre = pushRecursive_AT(arbre, create_AT(20));
  arbre = pushRecursive_AT(arbre, create_AT(10));
  arbre = pushRecursive_AT(arbre, create_AT(10));
  arbre = pushRecursive_AT(arbre, create_AT(10));
  arbre = pushRecursive_AT(arbre, create_AT(2));
  arbre = pushRecursive_AT(arbre, create_AT(12));
  arbre = pushRecursive_AT(arbre, create_AT(9));
  arbre = pushRecursive_AT(arbre, create_AT(54));
  arbre = pushRecursive_AT(arbre, create_AT(7));
  arbre = pushRecursive_AT(arbre, create_AT(11));
  arbre = pushRecursive_AT(arbre, create_AT(18));
  arbre = pushRecursive_AT(arbre, create_AT(38));
  arbre = pushRecursive_AT(arbre, create_AT(54));
  arbre = pushRecursive_AT(arbre, create_AT(7));

  printf("IS_BINAIRE_RECHERCHE : %d\n\n", is_arbre_binaire_recherche(arbre));

  printRecursive_AT(arbre, 1);
  printf("\n");
  printRecursive_AT(arbre, 2);
  printf("\n");
  printRecursive_AT(arbre, 3);
  printf("\n\n");
  printf("Min : %d\n", minKeyRecursive_AT(arbre));
  printf("Max : %d\n\n", maxKeyRecursive_AT(arbre));
  printf("Taille : %d\n\n", tailleRecursive_AT(arbre));
  printf("Hauteur : %d\n\n", hauteurRecursive_AT(arbre));
  printf("Feuilles : %d\n\n", nombreFeuillesRecursive_AT(arbre));

  arbre = pop_AT(arbre, 2);
  printRecursive_AT(arbre, 3);
  printf("\n\n");

  arbre = pop_AT(arbre, 9);
  printRecursive_AT(arbre, 3);
  arbre = pushRecursive_AT(arbre, create_AT(9));
  printf("\n\n");

  arbre = pop_AT(arbre, 10);
  printRecursive_AT(arbre, 3);
  arbre = pushRecursive_AT(arbre, create_AT(10));
  printf("\n\n");

  arbre = pop_AT(arbre, 20);
  printRecursive_AT(arbre, 3);
  arbre = pushRecursive_AT(arbre, create_AT(20));
  printf("\n\n");

  printRecursive_AT(arbre, 3);
  printf("\n\n");

  return EXIT_SUCCESS;
}
