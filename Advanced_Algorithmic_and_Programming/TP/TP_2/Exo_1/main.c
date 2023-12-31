#include "liste.h"

int main()
{
  int i, pos;
  Client *liste = NULL;
  Client* tab[4];
  tab[0] = creerClient(0, 5, 2, 20);
  tab[1] = creerClient(1, -1, 9, 5);
  tab[2] = creerClient(2, 1, 1, 10);
  tab[3] = creerClient(3, 2, 2, 15);
  for(i=0; i<4; i++)
  {
    pos = meilleurePosition(liste, tab[i]);
    liste = insertionClient(liste, tab[i], pos);
    afficher(liste);
    printf(" distance parcourue %f\n\n", distanceTotale(liste));
  }

  liste = cleanAllClients(liste);
  afficher(liste);

  return EXIT_SUCCESS;
}

