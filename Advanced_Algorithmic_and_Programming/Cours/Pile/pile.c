#include "pile.h"


Element* clean_AT(Element* pile)
{
  while(pile != NULL)
    pile = pop_AT(pile);

  return pile;
}

Element* create_AT(int a)
{
  Element* e = (Element*)malloc(sizeof(Element));
  e->value = a;
  e->next = NULL;

  return e;
}

Element* push_AT(Element* pile, int a)
{
  Element* e = create_AT(a);

  e->next = pile;

  return e;
}

Element* find_AT(Element* pile, int a)
{
  while(pile != NULL)
  {
    if(pile->value == a)
      return pile;

    pile = pile->next;
  }

  return NULL;
}

Element* pop_AT(Element* pile)
{
  Element *cur = pile;

  if(cur != NULL)
  {
    pile = cur->next;
    free(cur);
  }
  
  return pile;
}

void print_AT(Element* pile)
{
  int begin = 1;
  
  while(pile != NULL)
  {
    if(begin)
    {
      printf("{%d}", pile->value);
      begin = 0;
    }
    else
      printf(" -> {%d}", pile->value);

    pile = pile->next;
  }

  if(begin)
    printf("The pile is empty.");

  printf("\n");
}
