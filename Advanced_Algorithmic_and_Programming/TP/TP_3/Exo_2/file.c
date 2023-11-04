#include "file.h"

float average_wait_time(Queue* f)
{
  int wtt = 0, endt, n = 0;
  float avg_time = 0.0;
  Client* p = NULL;

  if(f != NULL)
  {
    p = f->head;
    endt = 0;
    while(p != NULL)
    {
      ++n;
      if( endt >= p->time )
      {
        wtt += ( endt - p->time );
        endt += p->need;
      }
      else
        endt += p->time + p->need;
      p = p->next;
    }
    if(n != 0)
      avg_time = wtt/(float)n;
  }

  return avg_time;
}

Queue* cleanQueue(Queue* f)
{
  if(f != NULL)
  {
    while(f->head != NULL)
      f = popClient(f);
  }

  return f;
}

Client* createClient(int id, int time, int need)
{
  Client* e = (Client*)malloc(sizeof(Client));
  e->id = id;
  e->time = time;
  e->need = need;
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

Queue* pushClient(Queue* f, int id, int time, int need)
{
  Client *e = createClient(id, time, need);

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

Client* findClient(Queue* f, int id)
{
  Client* p = NULL;

  if(f != NULL)
  {
    p = f->head;
    while(p != NULL)
    {
      if(p->id == id)
        return p;

      p = p->next;
    }
  }

  return p;
}

Queue* popClient(Queue* f)
{
  Client *tmp;

  if(f == NULL || f->head == NULL)
    return f;

  tmp = f->head;
  f->head = f->head->next;
  free(tmp);

  if(f->head == NULL)
    f->tail = NULL;

  return f;
}

void printQueue(Queue* f)
{
  int start = 1;
  Client* cur;
  
  if(f == NULL)
    printf("This queue doesn't exist.");
  else
  {
    cur = f->head;
    while(cur != NULL)
    {
      if(start)
      {
        printf("{id:%d, time:%d, need:%d}", cur->id, cur->time, cur->need);
        start = 0;
      }
      else
        printf(" -> {id:%d, time:%d, need:%d}", cur->id, cur->time, cur->need);

      cur = cur->next;
   }

   if(start)
     printf("The queue is empty.");
  }


  printf("\n");
}

