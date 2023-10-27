#ifndef ARBRE_BINAIRE_RECHERCHE
#define ARBRE_BINAIRE_RECHERCHE

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int key;
  struct node *left;
  struct node *right;
};
typedef struct node Node;

void parcoursPrefixeRecursive_AT(Node *arbre);
void parcoursInfixeRecursive_AT(Node *arbre);
void parcoursPostfixeRecursive_AT(Node *arbre);
void printRecursive_AT(Node *arbre, int type);

int hauteurRecursive_AT(Node *arbre);
int is_arbre_binaire_recherche(Node *arbre);
int max(int a, int b);
int minKeyRecursive_AT(Node *arbre);
int maxKeyRecursive_AT(Node *arbre);
int nombreFeuillesRecursive_AT(Node *arbre);
int tailleRecursive_AT(Node *arbre);

Node* create_AT(int key);
Node* pushIterative_AT(Node *arbre, int key);
Node* pushRecursive_AT(Node *arbre, Node *n);
Node* pop_AT(Node *arbre, int key);
Node* popNodeIntercaleAtMostOneSon(Node *arbre, Node *n);
Node* popNodeIntercaleTwoSon(Node *arbre, Node *n);
Node* fatherRecursive_AT(Node *arbre, int key);
Node* findRecursive_AT(Node *arbre, int key);

#endif
