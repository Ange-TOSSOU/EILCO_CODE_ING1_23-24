#include <stdio.h>
#include <stdlib.h>

struct element
{
  float value;
  struct element *next;
};
typedef struct element Element;

float evaluer(char expression[]);

Element* cleanStack(Element* pile);
Element* createElement(float a);
Element* pushElement(Element* pile, float a);
Element* findElement(Element* pile, float a);
Element* popElement(Element* pile, float* a);

void printStack(Element* pile);

