#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int id, time, need;
}Client;

struct element
{
  Client client;
  struct element *next;
};
typedef struct element Element;

typedef struct
{
  Element* head;
  Element* tail;
}File;

int is_equal_Client(Client c1, Client c2);

float average_wait_time(File* f);

Element* create_AT(Client c);
Element* find_AT(File* f, Client c);

File* clean_AT(File* f);
File* createQ_AT();
File* pop_AT(File* f, Client* c);
File* push_AT(File* f, Client c);

void print_AT(File* f);
