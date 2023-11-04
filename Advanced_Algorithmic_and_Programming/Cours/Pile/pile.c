#include "pile.h"


Element* cleanStack(Element* stack)
{
  while(stack != NULL)
    stack = popElement(stack, NULL);

  return stack;
}

Element* createElement(int a)
{
  Element* e = (Element*)malloc(sizeof(Element));
  e->value = a;
  e->next = NULL;

  return e;
}

Element* pushElement(Element* stack, int a)
{
  Element* e = createElement(a);

  e->next = stack;

  return e;
}

Element* findElement(Element* stack, int a)
{
  while(stack != NULL)
  {
    if(stack->value == a)
      return stack;

    stack = stack->next;
  }

  return NULL;
}

Element* popElement(Element* stack, int* a)
{
  Element *cur = stack;

  if(cur != NULL)
  {
    stack = cur->next;
    if(a != NULL)
      *a = cur->value;
    free(cur);
  }
  
  return stack;
}

void printStack(Element* stack)
{
  int start = 1;
  
  while(stack != NULL)
  {
    if(start)
    {
      printf("{%d}", stack->value);
      start = 0;
    }
    else
      printf(" -> {%d}", stack->value);

    stack = stack->next;
  }

  if(start)
    printf("The stack is empty.");

  printf("\n");
}

