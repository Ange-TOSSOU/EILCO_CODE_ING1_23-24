#include "pile.h"
#include "module_supp.h"

float evaluer(char expression[])
{
  char c;
  int i;
  float a, b, r = 0;
  Element *pile = NULL;

  for(i=0; (c=expression[i]) != '\0'; ++i)
  {
    if(is_digit(c))
      pile = push_AT(pile, c-'0');
    else if(is_operator(c))
    {
      pile = pop_AT(pile, &b);
      pile = pop_AT(pile, &a);
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
          return EXIT_FAILURE;
      }
      pile = push_AT(pile, r);
    }
  }

  if( (pile != NULL) && (pile->next == NULL) )
    pile = pop_AT(pile, &r);
  else
  {
    if(i != 0)
      return EXIT_FAILURE;
  }

  return r;
}

Element* clean_AT(Element* pile)
{
  while(pile != NULL)
    pile = pop_AT(pile, NULL);

  return pile;
}

Element* create_AT(float a)
{
  Element* e = (Element*)malloc(sizeof(Element));
  e->value = a;
  e->next = NULL;

  return e;
}

Element* push_AT(Element* pile, float a)
{
  Element* e = create_AT(a);

  e->next = pile;

  return e;
}

Element* find_AT(Element* pile, float a)
{
  while(pile != NULL)
  {
    if(pile->value == a)
      return pile;

    pile = pile->next;
  }

  return NULL;
}

Element* pop_AT(Element* pile, float* a)
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

void print_AT(Element* pile)
{
  float begin = 1;
  
  while(pile != NULL)
  {
    if(begin)
    {
      printf("{%.2f}", pile->value);
      begin = 0;
    }
    else
      printf(" -> {%.2f}", pile->value);

    pile = pile->next;
  }

  if(begin)
    printf("The pile is empty.");

  printf("\n");
}
