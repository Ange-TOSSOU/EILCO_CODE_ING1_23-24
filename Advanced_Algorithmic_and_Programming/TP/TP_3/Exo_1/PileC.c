#include "PileC.h"
#include "module_supp.h"

char* convertir_infixe_postfixe(char expI[])
{
  char *postfixe = calloc(strlen(expI)+1, sizeof(char)), c;
  int i, j;

  ElementC *pile_op = NULL;

  for(i=0, j=0; (c=expI[i]) != '\0'; ++i)
  {
    if(is_digit(c))
    {
      postfixe[j] = c;
      ++j;
    }
    else if(is_operator(c))
      pile_op = pushC_AT(pile_op, c);
    else if(c == ')')
    {
      pile_op = popC_AT(pile_op, postfixe+j);
      ++j;
    }
  }

  return postfixe;
}

ElementC* cleanC_AT(ElementC* pile)
{
  while(pile != NULL)
    pile = popC_AT(pile, NULL);

  return pile;
}

ElementC* createC_AT(char a)
{
  ElementC* e = (ElementC*)malloc(sizeof(ElementC));
  e->value = a;
  e->next = NULL;

  return e;
}

ElementC* pushC_AT(ElementC* pile, char a)
{
  ElementC* e = createC_AT(a);

  e->next = pile;

  return e;
}

ElementC* findC_AT(ElementC* pile, char a)
{
  while(pile != NULL)
  {
    if(pile->value == a)
      return pile;

    pile = pile->next;
  }

  return NULL;
}

ElementC* popC_AT(ElementC* pile, char* a)
{
  ElementC *cur = pile;

  if(cur != NULL)
  {
    pile = cur->next;
    if(a != NULL)
      *a = cur->value;
    free(cur);
  }
  
  return pile;
}

void printC_AT(ElementC* pile)
{
  char begin = 1;
  
  while(pile != NULL)
  {
    if(begin)
    {
      printf("{%c}", pile->value);
      begin = 0;
    }
    else
      printf(" -> {%c}", pile->value);

    pile = pile->next;
  }

  if(begin)
    printf("The pile is empty.");

  printf("\n");
}
