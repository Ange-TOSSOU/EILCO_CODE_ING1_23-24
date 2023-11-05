#ifndef FILEH
#define FILEH

#include <stdio.h>
#include <stdlib.h>

struct element
{
  int value;
  struct element *next;
};
typedef struct element Element;

typedef struct
{
  Element* head;
  Element* tail;
}Queue;

Element* createElement(int a);
Element* findElement(Queue* f, int a);

Queue* cleanQueue(Queue* f);
Queue* createQueue();
Queue* popElement(Queue* f, int* a);
Queue* pushElement(Queue* f, int a);

void printQueue(Queue* f);

#endif

