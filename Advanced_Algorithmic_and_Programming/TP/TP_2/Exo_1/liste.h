#ifndef LISTEH
#define LISTEH

#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>
#include <math.h>

struct client
{
  int id;
  float x, y;
  int q;
  struct client *next;
};
typedef struct client Client;

void afficher(Client* liste);
//void printHeaderTable();
//void printNbrChar(int n, char c);

//int nbrDigit(int n);
int meilleurePosition(Client* liste, Client* c);

float distance(Client* c1, Client* c2);
float distanceDepot(Client* c);
float distanceTotale(Client* liste);

Client* creerClient(int id, float x, float y, int q);
Client* insertionClient(Client* liste, Client* c, int pos);
Client* suppressionClient(Client* liste, int pos);
Client* cleanAllClients(Client* liste);

#endif

