#include "file.h"
#include "module_sup.h"

int main()
{
  File* file_clients = createQ_AT();
  Client tmp;

  srand(time(NULL));
  for(int i=0; i < Nb_Clients; ++i)
  {
    tmp.id = i+1;
    tmp.time = i;
    tmp.need = (rand() % (Need_MAX - Need_MIN + 1)) + Need_MIN;
    file_clients = push_AT(file_clients, tmp);
  }

  print_AT(file_clients);
  printf("Le temps d'attente moyen est de : %.2f\n", average_wait_time(file_clients));

  file_clients = clean_AT(file_clients);

  return EXIT_SUCCESS;
}
