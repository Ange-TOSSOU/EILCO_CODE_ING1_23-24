#include "liste.h"

int meilleurePosition(Client* liste, Client* c)
{
  int pos = 0, i = 0, delta, tmp;
  Client *previous, *cur = liste;

  if(liste != NULL)
  {
    delta = distanceDepot(c) + distance(c, cur) - distanceDepot(cur);
    while(cur->next != NULL)
    {
      previous = cur;
      cur = cur->next;
      ++i;
      tmp = distance(previous, c) + distance(c, cur) - distance(previous, cur);
      if(tmp < delta)
      {
        delta = tmp;
	pos = i;
      }
    }

    if(liste->next != NULL)
    {
      ++i;
      tmp = distance(cur, c) + distanceDepot(c) - distanceDepot(cur);
      if(tmp < delta)
      {
        delta = tmp;
	pos = i;
      }
    }
  }

  return pos;
}

float distance(Client* c1, Client* c2)
{
  float dist = 0.0;

  if( (c1 != NULL) && (c2 != NULL) )
    dist = pow(c1->x - c2->x, 2) + pow(c1->y - c2->y, 2);

  return sqrt(dist);
}

float distanceDepot(Client* c)
{
  float dist = 0.0;

  if(c != NULL)
    dist = pow(c->x, 2) + pow(c->y, 2);

  return sqrt(dist);
}

float distanceTotale(Client* liste)
{
  float dist = 0.0;
  Client *previous, *cur = liste;

  if(cur == NULL)
    ;
  else
  {
    dist += distanceDepot(cur);
    while(cur->next != NULL)
    {
      previous = cur;
      cur = cur->next;
      dist += distance(previous, cur);
    }
    dist += distanceDepot(cur);
  }
  
  return dist;
}

Client* cleanAllClients(Client* liste)
{
  while(liste != NULL)
    liste = suppressionClient(liste, 0);

  return liste;
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

Client* insertionClient(Client* liste, Client* c, int pos)
{
  Client *previous, *cur = liste;

  if(liste == NULL)
    liste = c;
  else
  {
    if(pos == 0)
    {
      c->next = liste;
      liste = c;
    }
    else
    {
      for(int i=0; (cur != NULL) && (i < pos); ++i)
      {
        previous = cur;
        cur = cur->next;
      }
      c->next = previous->next;
      previous->next = c;
    }
  }

  return liste;
}

Client* suppressionClient(Client* liste, int pos)
{
  Client *previous, *cur = liste;

  if(cur == NULL)
    ;
  else if(pos == 0)
  {
    liste = cur->next;
    free(cur);
  }
  else
  {
    for(int i=0; (cur != NULL) && (i < pos); ++i)
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

void printNbrChar(int n, char c)
{
  while(n)
  {
    printf("%c", c);
    n--;
  }
}

void printHeaderTable()
{
  int int_s;
  int_s = nbrDigit(INT_MAX);

  printf(" ID");
  printNbrChar(int_s - 2 + 1, ' ');
  printf("|");
  printf(" NEXT");
  printNbrChar(int_s - 4 + 1, ' ');
  printf("|");
  printf(" Qte");
  printNbrChar(int_s - 3 + 1, ' ');
  printf("|");
  printf(" (X , Y)\n");

  printNbrChar(int_s + 2, '-');
  printf("+");
  printNbrChar(int_s + 2, '-');
  printf("+");
  printNbrChar(int_s + 2, '-');
  printf("+");
  printNbrChar(9, '-');
  printf("\n");
}

void afficher(Client* liste)
{
  int int_s = nbrDigit(INT_MAX), cpt = 0;
  printHeaderTable();
  while(liste != NULL)
  {
    ++cpt;
    printf(" %d", liste->id);
    printNbrChar(int_s - nbrDigit(liste->id) + 1, ' ');
    printf("|");
    if(liste->next != NULL)
    {
      printf(" %d", liste->next->id);
      printNbrChar(int_s - nbrDigit(liste->next->id) + 1, ' ');
    }
    else
      printNbrChar(1 + int_s + 1, ' ');
    printf("|");
    printf(" %d", liste->q);
    printNbrChar(int_s - nbrDigit(liste->q) + 1, ' ');
    printf("|");
    printf(" (%.2f, %.2f)\n", liste->x, liste->y);

    liste = liste->next;
  }

  printf("\n(%d)rows\n", cpt);
}
