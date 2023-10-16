#include "pile.h"

int main()
{
  Element* pile = NULL;

  print_AT(pile);

  pile = push_AT(pile, 6);
  pile = push_AT(pile, 2);
  pile = push_AT(pile, 3);
  print_AT(pile);

  pile = push_AT(pile, 9);
  pile = push_AT(pile, 9);
  pile = push_AT(pile, 2);
  print_AT(pile);

  pile = clean_AT(pile);
  print_AT(pile);

  pile = push_AT(pile, 2);
  pile = push_AT(pile, 3);
  pile = push_AT(pile, 7);
  print_AT(pile);
  
  /*pile = pop_AT(pile, 3, NULL);
  print_AT(pile);*/
  pile = pop_AT(pile, NULL);
  print_AT(pile); 
  
  pile = clean_AT(pile);
  print_AT(pile); 

  return EXIT_SUCCESS;
}
