/*
 * main.c
 *
 *  Created on: 16 nov. 2017
 *      Author: guibadj
 */



#include "tableH.h"

MOT* Table[LONGTABLE];

int main()
{
	insererFichier(Table, "dictionnaire.txt");
	afficher(Table);

	printf("\n");
	printf("Exist(bca) = %d\n", existMot(Table, "bca"));
	printf("Exist(abc) = %d\n", existMot(Table, "abc"));
	printf("Exist(def) = %d\n", existMot(Table, "def"));
	printf("Exist(dee) = %d\n", existMot(Table, "dee"));

	return 0;
}
