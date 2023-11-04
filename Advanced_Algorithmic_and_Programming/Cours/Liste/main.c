#include "liste.h"

int main()
{
  Element* list = NULL;

  printList(list);

  list = pushElementStartOfList(list, 6);
  list = pushElementStartOfList(list, 2);
  list = pushElementStartOfList(list, 3);
  printList(list);

  list = pushElementEndOfList(list, 9);
  list = pushElementEndOfList(list, 9);
  list = pushElementEndOfList(list, 2);
  printList(list);

  list = cleanList(list);
  printList(list);

  list = pushElementStartOfList(list, 2);
  list = pushElementStartOfList(list, 3);
  list = pushElementStartOfList(list, 7);
  printList(list);
  
  list = popElement(list, 7);
  printList(list); 
  
  list = cleanList(list);
  printList(list); 

  return EXIT_SUCCESS;
}
