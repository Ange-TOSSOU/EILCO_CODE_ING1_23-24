#include "file.h"


Queue* cleanQueue(Queue* f)
{
  if(f != NULL)
  {
    while(f->head != NULL)
      f = popElement(f, NULL);
  }

  return f;
}

Element* createElement(int a)
{
  Element* e = (Element*)malloc(sizeof(Element));
  e->value = a;
  e->next = NULL;

  return e;
}

Queue* createQueue()
{
  Queue* f = (Queue*)malloc(sizeof(Queue));
  f->head = NULL;
  f->tail = NULL;

  return f;
}

Queue* pushElement(Queue* f, int a)
{
  Element *e = createElement(a);

  if(f == NULL)
    f = createQueue();

  if(f->head == NULL)
    f->head = f->tail = e;
  else
  {
    f->tail->next = e;
    f->tail = e;
  }

  return f;
}

Element* findElement(Queue* f, int a)
{
  Element* p = NULL;

  if(f != NULL)
  {
    p = f->head;
    while(p != NULL)
    {
      if(p->value == a)
        return p;

      p = p->next;
    }
  }

  return p;
}

Queue* popElement(Queue* f, int* a)
{
  Element *tmp;

  if(f == NULL || f->head == NULL)
    return f;

  tmp = f->head;
  f->head = f->head->next;
  if(a != NULL)
    *a = tmp->value;
  free(tmp);

  if(f->head == NULL)
    f->tail = NULL;

  return f;
}

void printQueue(Queue* f)
{
  int start = 1;
  Element* cur;
  
  if(f == NULL)
    printf("This queue doesn't exist.");
  else
  {
    cur = f->head;
    while(cur != NULL)
    {
      if(start)
      {
        printf("{%d}", cur->value);
        start = 0;
      }
      else
        printf(" -> {%d}", cur->value);

      cur = cur->next;
   }

   if(start)
     printf("The queue is empty.");
  }


  printf("\n");
}

