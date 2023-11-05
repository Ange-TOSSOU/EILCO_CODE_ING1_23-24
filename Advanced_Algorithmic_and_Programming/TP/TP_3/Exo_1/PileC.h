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
char* convertir_infixe_postfixe_generalisee(char expI[]);

ElementC* cleanStackC(ElementC* pile);
ElementC* createElementC(char a);
ElementC* pushElementC(ElementC* pile, char a);
ElementC* findElementC(ElementC* pile, char a);
ElementC* popElementC(ElementC* pile, char* a);

void printStackC(ElementC* pile);

