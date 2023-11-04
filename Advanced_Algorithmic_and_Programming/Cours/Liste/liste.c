#include "liste.h"


Element* cleanList(Element* list)
{
  Element *previous = NULL, *cur = list;

  while(cur != NULL)
  {
    previous = cur;
    cur = cur->next;
    free(previous);
  }

  return cur;
}

Element* createElement(int a)
{
  Element* e = (Element*)malloc(sizeof(Element));
  e->value = a;
  e->next = NULL;

  return e;
}

Element* pushElementStartOfList(Element* list, int a)
{
  Element* e = createElement(a);

  e->next = list;

  return e;
}

Element* pushElementEndOfList(Element* list, int a)
{
  Element *e = createElement(a), *tmp = list;

  if(list == NULL)
    list = e;
  else
  {
    while( (tmp != NULL) && (tmp->next != NULL) )
      tmp = tmp->next;

    tmp->next = e;
  }

  return list;
}

Element* findElement(Element* list, int a)
{
  while(list != NULL)
  {
    if(list->value == a)
      return list;

    list = list->next;
  }

  return NULL;
}

Element* popElement(Element* list, int a)
{
  Element *previous = NULL, *cur = list;

  if(cur != NULL)
  {
    if(cur->value == a)
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
  }
  
  return list;
}

void printList(Element* list)
{
  int start = 1;
  
  while(list != NULL)
  {
    if(start)
    {
      printf("{%d}", list->value);
      start = 0;
    }
    else
      printf(" -> {%d}", list->value);

    list = list->next;
  }

  if(start)
    printf("The list is empty.");

  printf("\n");
}

