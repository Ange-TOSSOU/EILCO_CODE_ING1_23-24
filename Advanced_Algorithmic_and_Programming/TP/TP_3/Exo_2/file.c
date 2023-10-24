#include "file.h"

int is_equal_Client(Client c1, Client c2)
{
  return ( (c1.id == c2.id) && (c1.time == c2.time) && (c1.need == c2.need) );
}

float average_wait_time(File* f)
{
  int wtt = 0, endt, n = 0;
  float avg_time = 0.0;
  Element* p = NULL;

  if(f != NULL)
  {
    p = f->head;
    endt = 0;
    while(p != NULL)
    {
      ++n;
      if( endt >= (p->client).time )
      {
        wtt += ( endt - (p->client).time );
        endt += (p->client).need;
      }
      else
        endt += (p->client).time + (p->client).need;
      p = p->next;
    }
    if(n != 0)
      avg_time = wtt/(float)n;
  }

  return avg_time;
}

File* clean_AT(File* f)
{
  if(f != NULL)
  {
    while(f->head != NULL)
      f = pop_AT(f, NULL);
  }

  return f;
}

Element* create_AT(Client c)
{
  Element* e = (Element*)malloc(sizeof(Element));
  e->client = c;
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

File* push_AT(File* f, Client c)
{
  Element *e = create_AT(c);

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

Element* find_AT(File* f, Client c)
{
  Element* p = NULL;

  if(f != NULL)
  {
    p = f->head;
    while(p != NULL)
    {
      if(is_equal_Client(p->client, c))
        return p;

      p = p->next;
    }
  }

  return p;
}

File* pop_AT(File* f, Client* c)
{
  Element *tmp;

  if(f == NULL || f->head == NULL)
    return f;

  tmp = f->head;
  f->head = f->head->next;
  if(c != NULL)
    *c = tmp->client;
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
        printf("{%d, %d, %d}", (cur->client).id, (cur->client).time, (cur->client).need);
        begin = 0;
      }
      else
        printf(" -> {%d, %d, %d}", (cur->client).id, (cur->client).time, (cur->client).need);

      cur = cur->next;
   }

   if(begin)
     printf("The file is empty.");
  }


  printf("\n");
}
