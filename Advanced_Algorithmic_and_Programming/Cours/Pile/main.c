#include "pile.h"

int main()
{
  Element* stack = NULL;

  printStack(stack);

  stack = pushElement(stack, 6);
  stack = pushElement(stack, 2);
  stack = pushElement(stack, 3);
  printStack(stack);

  stack = pushElement(stack, 9);
  stack = pushElement(stack, 9);
  stack = pushElement(stack, 2);
  printStack(stack);

  stack = cleanStack(stack);
  printStack(stack);

  stack = pushElement(stack, 2);
  stack = pushElement(stack, 3);
  stack = pushElement(stack, 7);
  printStack(stack);
  
  stack = popElement(stack, NULL);
  printStack(stack); 
  
  stack = cleanStack(stack);
  printStack(stack); 

  return EXIT_SUCCESS;
}

