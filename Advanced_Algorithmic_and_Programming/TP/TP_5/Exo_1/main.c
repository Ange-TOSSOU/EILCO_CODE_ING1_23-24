#include "main.h"

void printTab(int* Tab, int n)
{
  int i;
  for(i = 0; i < n; ++i)
  {
    if(i != 0)
      printf(" - ");
    printf("%d", Tab[i]);
  }
  printf("\n");
}

int main()
{
  int Tab[N] = {40, 10, 30, 20, 50, 70};

  printf("Avant tri : ");
  printTab(Tab, N);

  triParTas(Tab, N);

  printf("Apres tri : ");
  printTab(Tab, N);

  return EXIT_SUCCESS;
}
