/*
 * tableH.h
 *
 *  Created on: 16 nov. 2017
 *      Author: guibadj
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef TABLEH_H_
#define  TABLEH_H_


#define LONGTABLE 10 // longueur de la table de hachage

typedef struct mot{
char texte[30];
struct mot *  suivant;
}MOT;



void insererFichier(MOT * tableH [],  char *nomFichier);
void initialiserTable(MOT * tableH []);
void insererMot(MOT * tableH [] , char * mot);
int existMot(MOT * tableH [] , char * mot);
int hash(char * mot);
void afficher(MOT * tableH []);

#endif /* TABLEH_H_ */
