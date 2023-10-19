#include "module_supp.h"

int is_digit(char c)
{
  return ('0'<=c && c<='9');
}

int is_operator(char c)
{
  return (c=='+' || c=='-' || c=='*' || c=='/');
}
