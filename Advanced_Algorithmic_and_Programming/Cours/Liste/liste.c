#include "liste.h"


Element* clean_AT(Element* list)
{
  Element* p = NULL;

  while(list != NULL)
  {
    p = list;
    list = list->next;
    free(p);
  }

  return NULL;
}

Element* create_AT(int a)
{
  Element* e = (Element*)malloc(sizeof(Element));
  e->value = a;
  e->next = NULL;

  return e;
}

Element* pushFirst_AT(Element* list, int a)
{
  Element* e = create_AT(a);

  e->next = list;

  return e;
}

Element* pushLast_AT(Element* list, int a)
{
  Element *e = create_AT(a), *tmp = list;

  if(list == NULL)
    list = e;
  else
  {
    while( (tmp != NULL) && (tmp->next != NULL))
      tmp = tmp->next;

    tmp->next = e;
  }

  return list;
}

Element* find_AT(Element* list, int a)
{
  while(list != NULL)
  {
    if(list->value == a)
      return list;

    list = list->next;
  }

  return NULL;
}

Element* pop_AT(Element* list, int a)
{
  Element *previous, *cur = list;

  if(cur == NULL)
    ;
  else if(cur->value == a)
  {
    list = cur->next;
    free(cur);
  }
  else
  {
    while( (cur != NULL) && (cur->value != a) )
    {
      previous = cur;
      cur = cur->next;
    }
    if(cur != NULL)
    {
      previous->next = cur->next;
      free(cur);
    }
  }
  
  return list;
}

void print_AT(Element* list)
{
  int begin = 1;
  
  while(list != NULL)
  {
    if(begin)
    {
      printf("{%d}", list->value);
      begin = 0;
    }
    else
      printf(" -> {%d}", list->value);

    list = list->next;
  }

  if(begin)
    printf("The list is empty.");

  printf("\n");
}
