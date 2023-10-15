#include <stdio.h>
#include <stdlib.h>

struct element
{
  int value;
  struct element *next;
};
typedef struct element Element;

Element* clean_AT(Element* list);
Element* create_AT(int a);
Element* pushFirst_AT(Element* list, int a);
Element* pushLast_AT(Element* list, int a);
Element* find_AT(Element* list, int a);
Element* pop_AT(Element* list, int a);

void print_AT(Element* list);
