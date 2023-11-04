#include <stdio.h>
#include <stdlib.h>

struct element
{
  int value;
  struct element *next;
};
typedef struct element Element;

Element* cleanList(Element* list);
Element* createElement(int a);
Element* pushElementStartOfList(Element* list, int a);
Element* pushElementEndOfList(Element* list, int a);
Element* findElement(Element* list, int a);
Element* popElement(Element* list, int a);

void printList(Element* list);

