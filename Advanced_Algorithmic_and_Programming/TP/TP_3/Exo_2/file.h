#ifndef FILEH
#define FILEH

#include <stdio.h>
#include <stdlib.h>

struct client
{
  int id, time, need;
  struct client *next;
};
typedef struct client Client;

typedef struct
{
  Client* head;
  Client* tail;
}Queue;

float average_wait_time(Queue* f);

Client* createClient(int id, int time, int need);
Client* findClient(Queue* f, int id);

Queue* cleanQueue(Queue* f);
Queue* createQueue();
Queue* popClient(Queue* f);
Queue* pushClient(Queue* f, int id, int time, int need);

void printQueue(Queue* f);

#endif

