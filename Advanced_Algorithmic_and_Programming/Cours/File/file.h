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
}File;

Element* create_AT(int a);
Element* find_AT(File* f, int a);

File* clean_AT(File* f);
File* createQ_AT();
File* pop_AT(File* f);
File* push_AT(File* f, int a);

void print_AT(File* f);
