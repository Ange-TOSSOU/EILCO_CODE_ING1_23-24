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
	return 0;
}
