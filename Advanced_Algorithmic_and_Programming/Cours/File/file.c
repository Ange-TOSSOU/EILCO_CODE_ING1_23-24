#include "file.h"


File* clean_AT(File* f)
{
  if(f != NULL)
  {
    while(f->head != NULL)
      f = pop_AT(f, NULL);
  }

  return f;
}

Element* create_AT(int a)
{
  Element* e = (Element*)malloc(sizeof(Element));
  e->value = a;
  e->next = NULL;

  return e;
}

File* createQ_AT()
{
  File* f = (File*)malloc(sizeof(File));
  f->head = NULL;
  f->tail = NULL;

  return f;
}

File* push_AT(File* f, int a)
{
  Element *e = create_AT(a);

  if(f == NULL)
    f = createQ_AT();

  if(f->head == NULL)
    f->head = f->tail = e;
  else
  {
    f->tail->next = e;
    f->tail = e;
  }

  return f;
}

Element* find_AT(File* f, int a)
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

File* pop_AT(File* f, int* a)
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

void print_AT(File* f)
{
  int begin = 1;
  Element* cur;
  
  if(f == NULL)
    printf("This file doesn't exist.");
  else
  {
    cur = f->head;
    while(cur != NULL)
    {
      if(begin)
      {
        printf("{%d}", cur->value);
        begin = 0;
      }
      else
        printf(" -> {%d}", cur->value);

      cur = cur->next;
   }

   if(begin)
     printf("The file is empty.");
  }


  printf("\n");
}
