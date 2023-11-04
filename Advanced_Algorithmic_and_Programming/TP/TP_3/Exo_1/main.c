#include "pile.h"
#include "PileC.h"

int main()
{
  printf("%s\n%s\n%.2f\n\n", "", convertir_infixe_postfixe(""), evaluer(convertir_infixe_postfixe("")));
  printf("%s\n%s\n%.2f\n\n", "5", convertir_infixe_postfixe("5"), evaluer(convertir_infixe_postfixe("5")));
  printf("%s\n%s\n%.2f\n\n", "(((3+4)*5)-6)", convertir_infixe_postfixe("(((3+4)*5)-6)"), evaluer(convertir_infixe_postfixe("(((3+4)*5)-6)")));
  printf("%s\n%s\n%.2f\n\n", "(3+(4*(5-6)))", convertir_infixe_postfixe("(3+(4*(5-6)))"), evaluer(convertir_infixe_postfixe("(3+(4*(5-6)))")));

  return EXIT_SUCCESS;
}

