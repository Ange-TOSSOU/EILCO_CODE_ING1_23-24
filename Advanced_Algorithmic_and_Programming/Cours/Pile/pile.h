#ifndef PILEH
#define PILEH

#include <stdio.h>
#include <stdlib.h>

struct element
{
  int value;
  struct element *next;
};
typedef struct element Element;

Element* cleanStack(Element* stack);
Element* createElement(int a);
Element* pushElement(Element* stack, int a);
Element* findElement(Element* stack, int a);
Element* popElement(Element* stack, int* a);

void printStack(Element* stack);

#endif

