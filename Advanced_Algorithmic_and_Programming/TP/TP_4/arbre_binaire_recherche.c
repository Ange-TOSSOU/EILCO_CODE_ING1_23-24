#include "arbre_binaire_recherche.h"

Node* create_AT(int key)
{
  Node *n = malloc(sizeof(Node));
  if(n != NULL)
  {
    n->key = key;
    n->left = n->right = NULL;
  }

  return n;
}

Node* pushIterative_AT(Node *arbre, int key)
{
  Node *n = create_AT(key);

  if(arbre == NULL)
    return n;

  Node *p = arbre;
  Node *father = NULL;
  while(p != NULL)
  {
    father = p;

    if(n->key == p->key)
    {
      free(n);
      return arbre;
    }

    if(n->key < p->key)
      p = p->left;
    else
      p = p->right;
  }

  if(n->key < father->key)
    father->left = n;
  else
    father->right = n;

  return arbre;
}

Node* pushRecursive_AT(Node *arbre, Node *n)
{
  if(arbre == NULL)
    return n;

  if(n->key == arbre->key)
    free(n);
  else if(n->key < arbre->key)
    arbre->left = pushRecursive_AT(arbre->left, n);
  else
    arbre->right = pushRecursive_AT(arbre->right, n);

  return arbre;
}

Node* fatherRecursive_AT(Node *arbre, int key)
{
  if(arbre == NULL || arbre->key == key)
    return NULL;

  if(arbre->left != NULL && arbre->left->key == key)
    return arbre;
  if(arbre->right != NULL && arbre->right->key == key)
    return arbre;

  if(key < arbre->key)
    return fatherRecursive_AT(arbre->left, key);
  else
    return fatherRecursive_AT(arbre->right, key);
}

Node* popNodeIntercaleAtMostOneSon(Node *arbre, Node *n)
{
  Node *father = fatherRecursive_AT(arbre, n->key);
  Node *tmp = NULL;

  if(n->left != NULL)
    tmp = n->left;
  else if(n->right != NULL)
    tmp = n->right;

  if(father != NULL)
  {
    if(father->left == n)
      father->left = tmp;
    else
      father->right = tmp;
  }

  if(arbre == n)
    arbre = tmp;

  free(n);

  return arbre;
}

Node* popNodeIntercaleTwoSon(Node *arbre, Node *n)
{
  int kreplace = maxKeyRecursive_AT(n->left);

  popNodeIntercaleAtMostOneSon(arbre, findRecursive_AT(n->left, kreplace));
  n->key = kreplace;
 
  return arbre;
}

Node* pop_AT(Node *arbre, int key)
{
  Node *cur = findRecursive_AT(arbre, key);

  if(cur == NULL)
    return arbre;

  if( (cur->left == NULL && cur->right == NULL) || (cur->left != NULL && cur->right == NULL) || (cur->left == NULL && cur->right != NULL) )
    return popNodeIntercaleAtMostOneSon(arbre, cur);
  else
    return popNodeIntercaleTwoSon(arbre, cur);
}

Node* findRecursive_AT(Node *arbre, int key)
{
  if(arbre == NULL)
    return NULL;

  if(arbre->key == key)
    return arbre;
  else if(key < arbre->key)
    return findRecursive_AT(arbre->left, key);
  else
    return findRecursive_AT(arbre->right, key);
}

int minKeyRecursive_AT(Node *arbre)
{
  if(arbre == NULL)
    return 0;

  if(arbre->left == NULL)
    return arbre->key;

  return minKeyRecursive_AT(arbre->left);
}

int maxKeyRecursive_AT(Node *arbre)
{
  if(arbre == NULL)
    return 0;

  if(arbre->right == NULL)
    return arbre->key;

  return maxKeyRecursive_AT(arbre->right);
}

int tailleRecursive_AT(Node *arbre)
{
  if(arbre == NULL)
    return 0;

  return 1 + tailleRecursive_AT(arbre->left) + tailleRecursive_AT(arbre->right);
}

int max(int a, int b)
{
  if(a > b)
    return a;
  else
    return b;
}

int hauteurRecursive_AT(Node *arbre)
{
  if(arbre == NULL)
    return 0;

  return 1 + max(hauteurRecursive_AT(arbre->left), hauteurRecursive_AT(arbre->right));
}

int nombreFeuillesRecursive_AT(Node *arbre)
{
  if(arbre == NULL)
    return 0;

  if(arbre->left == NULL && arbre->right == NULL)
    return 1;
  
  return nombreFeuillesRecursive_AT(arbre->left) + nombreFeuillesRecursive_AT(arbre->right);
}

int is_arbre_binaire_recherche(Node *arbre)
{
  if(arbre == NULL)
    return 1;

  if(arbre->left != NULL && arbre->left->key > arbre->key)
    return 0;

  if(arbre->right != NULL && arbre->right->key < arbre->key)
    return 0;

  return 1 * is_arbre_binaire_recherche(arbre->left) * is_arbre_binaire_recherche(arbre->right);
}

void parcoursPrefixeRecursive_AT(Node *arbre)
{
  if(arbre != NULL)
  {
    printf("{%d} ",arbre->key);
    parcoursPrefixeRecursive_AT(arbre->left);
    parcoursPrefixeRecursive_AT(arbre->right);
  }
}

void parcoursInfixeRecursive_AT(Node *arbre)
{
  if(arbre != NULL)
  {
    parcoursInfixeRecursive_AT(arbre->left);
    printf("{%d} ",arbre->key);
    parcoursInfixeRecursive_AT(arbre->right);
  }
}

void parcoursPostfixeRecursive_AT(Node *arbre)
{
  if(arbre != NULL)
  {
    parcoursPostfixeRecursive_AT(arbre->left);
    parcoursPostfixeRecursive_AT(arbre->right);
    printf("{%d} ",arbre->key);
  }
}

void printRecursive_AT(Node *arbre, int type)
{
  if(type == 1)
    parcoursPrefixeRecursive_AT(arbre);
  else if(type == 2)
    parcoursPostfixeRecursive_AT(arbre);
  else
    parcoursInfixeRecursive_AT(arbre);
}
