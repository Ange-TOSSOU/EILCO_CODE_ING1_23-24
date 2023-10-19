#include <stdio.h>
#include <stdlib.h>

struct element
{
  float value;
  struct element *next;
};
typedef struct element Element;

float evaluer(char expression[]);

Element* clean_AT(Element* pile);
Element* create_AT(float a);
Element* push_AT(Element* pile, float a);
Element* find_AT(Element* pile, float a);
Element* pop_AT(Element* pile, float* a);

void print_AT(Element* pile);
