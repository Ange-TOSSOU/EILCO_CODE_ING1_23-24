#include "liste.h"

int main()
{
  Element* list = NULL;

  print_AT(list);

  list = insertFirst_AT(list, 6);
  list = insertFirst_AT(list, 2);
  list = insertFirst_AT(list, 3);
  print_AT(list);

  list = insertLast_AT(list, 9);
  list = insertLast_AT(list, 9);
  list = insertLast_AT(list, 2);
  print_AT(list);

  list = clean_AT(list);
  print_AT(list);

  list = insertFirst_AT(list, 2);
  list = insertFirst_AT(list, 3);
  list = insertFirst_AT(list, 7);
  print_AT(list);
  
  /*list = remove_AT(list, 3);
  print_AT(list);*/
  list = remove_AT(list, 2);
  print_AT(list); 
  
  list = clean_AT(list);
  print_AT(list); 

  return EXIT_SUCCESS;
}
