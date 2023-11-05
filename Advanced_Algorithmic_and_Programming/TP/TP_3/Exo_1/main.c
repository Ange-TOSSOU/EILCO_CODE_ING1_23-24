#include "pile.h"
#include "PileC.h"

int main()
{
  printf("%s\n%s\n%.2f\n\n", "", convertir_infixe_postfixe(""), evaluer(convertir_infixe_postfixe("")));
  printf("%s\n%s\n%.2f\n\n", "5", convertir_infixe_postfixe("5"), evaluer(convertir_infixe_postfixe("5")));
  printf("%s\n%s\n%.2f\n\n", "(((3+4)*5)-6)", convertir_infixe_postfixe("(((3+4)*5)-6)"), evaluer(convertir_infixe_postfixe("(((3+4)*5)-6)")));
  printf("%s\n%s\n%.2f\n\n", "(3+(4*(5-6)))", convertir_infixe_postfixe("(3+(4*(5-6)))"), evaluer(convertir_infixe_postfixe("(3+(4*(5-6)))")));

  printf("%s\n%s\n%.2f\n\n", "5*((9+8)+(4*6)+7)", convertir_infixe_postfixe_generalisee("5*((9+8)+(4*6)+7)"), evaluer(convertir_infixe_postfixe_generalisee("5*((9+8)+(4*6)+7)")));
  printf("%s\n%s\n%.2f\n\n", "3*2+4", convertir_infixe_postfixe_generalisee("3*2+4"), evaluer(convertir_infixe_postfixe_generalisee("3*2+4")));
  printf("%s\n%s\n%.2f\n\n", "3+2*4", convertir_infixe_postfixe_generalisee("3+2*4"), evaluer(convertir_infixe_postfixe_generalisee("3+2*4")));
  printf("%s\n%s\n%.2f\n\n", "5*2+3+1+7*8", convertir_infixe_postfixe_generalisee("5*2+3+1+7*8"), evaluer(convertir_infixe_postfixe_generalisee("5*2+3+1+7*8")));
  printf("%s\n%s\n%.2f\n\n", "5*((1+2*3+1+5)+6)", convertir_infixe_postfixe_generalisee("5*((1+2*3+1+5)+6)"), evaluer(convertir_infixe_postfixe_generalisee("5*((1+2*3+1+5)+6)")));

  return EXIT_SUCCESS;
}

