#include "file.h"
#include "module_supp.h"

int main()
{
  int tmp_id, tmp_time, tmp_need;
  Queue* file_clients = createQueue();

  srand(time(NULL));
  for(int i=0; i < Nb_Clients; ++i)
  {
    tmp_id = i+1;
    tmp_time = i;
    tmp_need = (rand() % (Need_MAX - Need_MIN + 1)) + Need_MIN;
    file_clients = pushClient(file_clients, tmp_id, tmp_time, tmp_need);
  }

  printQueue(file_clients);
  printf("Le temps d'attente moyen est de : %.2f\n", average_wait_time(file_clients));

  file_clients = cleanQueue(file_clients);

  return EXIT_SUCCESS;
}

