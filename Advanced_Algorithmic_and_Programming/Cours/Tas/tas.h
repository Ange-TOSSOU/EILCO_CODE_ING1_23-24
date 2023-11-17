#ifndef tasASH
#define tasASH

#include <stdio.h>
#include <stdlib.h>

void echanger(int *tas, int i, int j)
{
  int tmp = tas[i];
  tas[i] = tas[j];
  tas[j] = tmp;
}

int inserer(int *tas, int n, int val)
{
  tas[n+1] = val;
  ++n;
  int i = n, tmp;
  while( (i>1) && (tas[i/2]>tas[i]) )
  {
    echanger(tas, i, i/2);
    i = i/2;
  }

  return n;
}

int supprimerMin(int *tas, int n)
{
  tas[1] = tas[n];
  --n;
  int i = 1, tmp;
  while( (!stop) && (i<=n/2) )
  {
    if(tas[2*i] <  tas[2*i+1])
      min = 2*i;
    else
      min = 2*i+1;
    if(tas[i] > tas[min])
    {
      echanger(i, min);
      i = min;
    }
    else
      stop = 1;
  }
}

#endif

