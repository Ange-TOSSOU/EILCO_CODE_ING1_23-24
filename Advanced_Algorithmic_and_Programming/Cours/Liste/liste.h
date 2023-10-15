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
Element* insertFirst_AT(Element* list, int a);
Element* insertLast_AT(Element* list, int a);
Element* find_AT(Element* list, int a);
Element* remove_AT(Element* list, int a);

void print_AT(Element* list);
