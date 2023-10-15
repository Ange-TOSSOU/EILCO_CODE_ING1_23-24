#include "liste.h"

int main()
{
  Element* list = NULL;

  print_AT(list);

  list = pushFirst_AT(list, 6);
  list = pushFirst_AT(list, 2);
  list = pushFirst_AT(list, 3);
  print_AT(list);

  list = pushLast_AT(list, 9);
  list = pushLast_AT(list, 9);
  list = pushLast_AT(list, 2);
  print_AT(list);

  list = clean_AT(list);
  print_AT(list);

  list = pushFirst_AT(list, 2);
  list = pushFirst_AT(list, 3);
  list = pushFirst_AT(list, 7);
  print_AT(list);
  
  /*list = pop_AT(list, 3);
  print_AT(list);*/
  list = pop_AT(list, 2);
  print_AT(list); 
  
  list = clean_AT(list);
  print_AT(list); 

  return EXIT_SUCCESS;
}
