#include "file.h"

int main()
{
  File* f = createQ_AT();

  print_AT(f);

  f = push_AT(f, 6);
  f = push_AT(f, 2);
  f = push_AT(f, 3);
  print_AT(f);

  f = push_AT(f, 9);
  f = push_AT(f, 9);
  f = push_AT(f, 2);
  print_AT(f);

  f = clean_AT(f);
  print_AT(f);

  f = push_AT(f, 2);
  f = push_AT(f, 3);
  f = push_AT(f, 7);
  print_AT(f);
  
  f = pop_AT(f, NULL);
  print_AT(f); 
  
  f = clean_AT(f);
  print_AT(f); 

  return EXIT_SUCCESS;
}
