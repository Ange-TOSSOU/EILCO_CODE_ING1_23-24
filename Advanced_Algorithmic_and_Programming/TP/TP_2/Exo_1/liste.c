#include "liste.h"

float distance(Client* c1, Client* c2)
{
  float dist = 0.0;
  if( (c1 != NULL) && (c2 != NULL) )
    dist = pow(c1->x - c2->x, 2) + pow(c1->y - c2->y, 2);

  return sqrt(dist);
}

Client* clean_AT(Client* liste)
{
  Client* p = NULL;

  while(liste != NULL)
  {
    p = liste;
    liste = liste->next;
    free(p);
  }

  return NULL;
}

Client* creerClient(int id, float x, float y, int q)
{
  Client* e = (Client*)malloc(sizeof(Client));
  e->id = id;
  e->x = x;
  e->y = y;
  e->q = q;
  e->next = NULL;

  return e;
}

Client* pushFirst_AT(Client* liste, int a)
{
  Client* e = create_AT(a);

  e->next = liste;

  return e;
}

Client* pushLast_AT(Client* liste, int a)
{
  Client *e = create_AT(a), *tmp = liste;

  if(liste == NULL)
    liste = e;
  else
  {
    while( (tmp != NULL) && (tmp->next != NULL))
      tmp = tmp->next;

    tmp->next = e;
  }

  return liste;
}

Client* find_AT(Client* liste, int a)
{
  while(liste != NULL)
  {
    if(liste->value == a)
      return liste;

    liste = liste->next;
  }

  return NULL;
}

Client* pop_AT(Client* liste, int a)
{
  Client *previous, *cur = liste;

  if(cur == NULL)
    ;
  else if(cur->value == a)
  {
    liste = cur->next;
    free(cur);
  }
  else
  {
    cur = cur->next;
    while( (cur != NULL) && (cur->value != a) )
    {
      previous = cur;
      cur = cur->next;
    }
    if(cur != NULL)
    {
      previous->next = cur->next;
      free(cur);
    }
  }
  
  return liste;
}

int nbrDigit(int n)
{
  int cpt = 0;
  do
  {
    ++cpt;
    n /= 10;
  }while(n);

  return cpt;
}

void printNbrSpace(int n)
{
  while(n)
  {
    printf(" ");
    n--;
  }
}

void printHeaderTable()
{
  int int_s;
  int_s = nbrDigit(INT_MAX);

  printf(" ID");
  printNbrSpace(int_s - 2 + 1);
  printf("|");
  printf(" NEXT");
  printNbrSpace(int_s - 4 + 1);
  printf("|");
  printf(" Qte");
  printNbrSpace(int_s - 3 + 1);
  printf("|");
  printf(" (X , Y)\n");

  printNbrSpace(int_s + 2);
  printf("+");
  printNbrSpace(int_s + 2);
  printf("+");
  printNbrSpace(int_s + 2);
  printf("+\n");
}

void afficher(Client* liste)
{
  int int_s = nbrDigit(INT_MAX), cpt = 0;
  printHeaderTable();
  while(liste != NULL)
  {
    ++cpt;
    printf(" %d", liste->id);
    printNbrSpace(int_s - nbrDigit(liste->id) + 1);
    printf("|");
    if(liste->next != NULL)
    {
      printf(" %d", liste->next->id);
      printNbrSpace(int_s - nbrDigit(liste->next->id) + 1);
    }
    else
      printNbrSpace(int_s + 1);
    printf("|");
    printf(" %d", liste->q);
    printNbrSpace(int_s - nbrDigit(q) + 1);
    printf("|");
    printf(" (%.2f, %.2f)\n", liste->x, liste->y);

    liste = liste->next;
  }

  printf("\n(%d)rows\n\n", cpt);
}
