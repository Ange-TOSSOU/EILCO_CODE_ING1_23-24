#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int a, b, c;
}CLI;

void print_CLI(CLI z)
{
  printf("%d %d %d\n", z.a, z.b, z.c);
}

int main()
{
  CLI x = {1, 2, 3}, y;

  print_CLI(x);
  print_CLI(y);
  if(x == y)
    printf("AMAZING\n");
  y = x;
  print_CLI(y);
  if(x == y)
    printf("AMAZING\n");

  return EXIT_SUCCESS;
}
