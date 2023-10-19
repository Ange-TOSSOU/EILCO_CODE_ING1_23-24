#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elementC
{
  char value;
  struct elementC *next;
};
typedef struct elementC ElementC;

char* convertir_infixe_postfixe(char expI[]);

ElementC* cleanC_AT(ElementC* pile);
ElementC* createC_AT(char a);
ElementC* pushC_AT(ElementC* pile, char a);
ElementC* findC_AT(ElementC* pile, char a);
ElementC* popC_AT(ElementC* pile, char* a);

void printC_AT(ElementC* pile);
