#include <stdio.h>
#include <stdlib.h>

struct element
{
  int value;
  struct element *next;
};
typedef struct element Element;

Element* clean_AT(Element* pile);
Element* create_AT(int a);
Element* push_AT(Element* pile, int a);
Element* find_AT(Element* pile, int a);
Element* pop_AT(Element* pile);

void print_AT(Element* pile);
