#include "tas.h"

void echanger(int Tas[], int i, int j)
{
  int tmp = Tas[i];
  Tas[i] = Tas[j];
  Tas[j] = tmp;
}

int minimumIndice(int Tas[], int i, int j)
{
  if(Tas[i] < Tas[j])
    return i;
  return j;
}

int inserer(int Tas[], int n, int v)
{
  int i;
  Tas[n+1] = v;
  i = ++n;

  while( (i>1) && (Tas[i/2]>Tas[i]) )
  {
    echanger(Tas, i, i/2);
    i = i/2;
  }

  return n;
}

int supprimerMinimum(int Tas[], int n)
{
  int i = 1, stop = 0, imin;
  Tas[1] = Tas[n];
  --n;
  while( (!stop) && (i<=n/2) )
  {
    imin = minimumIndice(Tas, 2*i, 2*i+1);
    if(Tas[i] > Tas[imin])
    {
      echanger(Tas, i, imin);
      i = imin;
    }
    else
      stop = 1;
  }

  return n;
}

void triParTas(int Tab[], int n)
{
  int *Tas = malloc((n+1)*sizeof(int)), i, taille_tas = 0;

  for(i = 0; i < n; ++i)
    taille_tas = inserer(Tas, taille_tas, Tab[i]);

  for(i = 0; i < n; ++i)
    Tab[i] = Tas[i+1];
}
