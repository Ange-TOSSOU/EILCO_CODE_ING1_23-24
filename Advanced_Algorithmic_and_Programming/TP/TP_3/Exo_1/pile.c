#include "pile.h"
#include "module_supp.h"

float evaluer(char expression[])
{
  char c;
  int i;
  float a, b, r;
  Element *pile = NULL;

  for(i=0; (c=expression[i]) != '\0'; ++i)
  {
    if(is_digit(c))
      pile = pushElement(pile, c-'0');
    else if(is_operator(c))
    {
      pile = popElement(pile, &b);
      pile = popElement(pile, &a);
      if(c == '+')
        r = a + b;
      else if(c == '-')
        r = a - b;
      else if(c == '*')
        r = a * b;
      else
      {
        if(b != 0)
          r = a/b;
	else
          exit(EXIT_FAILURE);
      }
      pile = pushElement(pile, r);
    }
  }

  if( (pile != NULL) && (pile->next == NULL) )
    pile = popElement(pile, &r);
  else
  {
    if(i != 0)
      exit(EXIT_FAILURE);
  }

  return r;
}

Element* cleanStack(Element* pile)
{
  while(pile != NULL)
    pile = popElement(pile, NULL);

  return pile;
}

Element* createElement(float a)
{
  Element* e = (Element*)malloc(sizeof(Element));
  e->value = a;
  e->next = NULL;

  return e;
}

Element* pushElement(Element* pile, float a)
{
  Element* e = createElement(a);

  e->next = pile;

  return e;
}

Element* findElement(Element* pile, float a)
{
  while(pile != NULL)
  {
    if(pile->value == a)
      return pile;

    pile = pile->next;
  }

  return NULL;
}

Element* popElement(Element* pile, float* a)
{
  Element *cur = pile;

  if(cur != NULL)
  {
    pile = cur->next;
    if(a != NULL)
      *a = cur->value;
    free(cur);
  }
  
  return pile;
}

void printStack(Element* pile)
{
  float start = 1;
  
  while(pile != NULL)
  {
    if(start)
    {
      printf("{%.2f}", pile->value);
      start = 0;
    }
    else
      printf(" -> {%.2f}", pile->value);

    pile = pile->next;
  }

  if(start)
    printf("The stack is empty.");

  printf("\n");
}

