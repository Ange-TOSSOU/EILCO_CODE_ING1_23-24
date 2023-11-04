#include "file.h"

int main()
{
  Queue* f = createQueue();

  printQueue(f);

  f = pushElement(f, 6);
  f = pushElement(f, 2);
  f = pushElement(f, 3);
  printQueue(f);

  f = pushElement(f, 9);
  f = pushElement(f, 9);
  f = pushElement(f, 2);
  printQueue(f);

  f = cleanQueue(f);
  printQueue(f);

  f = pushElement(f, 2);
  f = pushElement(f, 3);
  f = pushElement(f, 7);
  printQueue(f);
  
  f = popElement(f, NULL);
  printQueue(f); 
  
  f = cleanQueue(f);
  printQueue(f);

  return EXIT_SUCCESS;
}

