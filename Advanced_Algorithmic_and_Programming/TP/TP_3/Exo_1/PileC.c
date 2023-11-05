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
      pile_op = pushElementC(pile_op, c);
    else if(c == ')')
    {
      pile_op = popElementC(pile_op, postfixe+j);
      ++j;
    }
  }

  return postfixe;
}

char* convertir_infixe_postfixe_generalisee(char expI[])
{
  char *postfixe = calloc(strlen(expI)+1, sizeof(char)), c;
  int i, j;

  ElementC *pile = NULL;

  for(i=0, j=0; (c=expI[i]) != '\0'; ++i)
  {
    if(c == '(')
      pile = pushElementC(pile, c);
    else if(is_digit(c))
    {
      postfixe[j] = c;
      ++j;
    }
    else if(is_operator(c))
    {
      if( (c == '*') || (c == '/') )
        pile = pushElementC(pile, c);
      else
      {
        while( (pile != NULL) && (pile->value == '*' || pile->value == '/') )
	{
          pile = popElementC(pile, postfixe+j);
	  ++j;
	}
	pile = pushElementC(pile, c);
      }
    }
    else if(c == ')')
    {
      while( (pile != NULL) && (pile->value != '(') )
      {
        pile = popElementC(pile, postfixe+j);
        ++j;
      }
      pile = popElementC(pile, NULL);
    }
  }
  while(pile != NULL)
  {
    pile = popElementC(pile, postfixe+j);
    ++j;
  }

  return postfixe;
}

ElementC* cleanStackC(ElementC* pile)
{
  while(pile != NULL)
    pile = popElementC(pile, NULL);

  return pile;
}

ElementC* createElementC(char a)
{
  ElementC* e = (ElementC*)malloc(sizeof(ElementC));
  e->value = a;
  e->next = NULL;

  return e;
}

ElementC* pushElementC(ElementC* pile, char a)
{
  ElementC* e = createElementC(a);

  e->next = pile;

  return e;
}

ElementC* findElementC(ElementC* pile, char a)
{
  while(pile != NULL)
  {
    if(pile->value == a)
      return pile;

    pile = pile->next;
  }

  return NULL;
}

ElementC* popElementC(ElementC* pile, char* a)
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

void printStackC(ElementC* pile)
{
  char start = 1;
  
  while(pile != NULL)
  {
    if(start)
    {
      printf("{%c}", pile->value);
      start = 0;
    }
    else
      printf(" -> {%c}", pile->value);

    pile = pile->next;
  }

  if(start)
    printf("The stack is empty.");

  printf("\n");
}

