/*
 * tableH.c
 *
 *  Created on: 16 nov. 2017
 *      Author: guibadj
 */


#include "tableH.h"


int hash(char * mot)
{
	int i_hash = 0, i;

	for(i = 0; mot[i]; ++i)
		i_hash += mot[i];

	i_hash %= LONGTABLE;

	return i_hash;
}

void initialiserTable(MOT * tableH[] )
{
	int  i;
	for(i = 0; i < LONGTABLE; ++i)
		tableH[i] = NULL;

}

void insererMot(MOT * tableH [], char * mot)
{
	int indice = hash(mot);
	MOT *e = (MOT*)malloc(sizeof(MOT));
	if(e != NULL)
	{
		strcpy(e->texte, mot);
		e->suivant = tableH[indice];
		tableH[indice] = e;
	}
}

int existMot(MOT * tableH [], char * mot)
{
	int indice = hash(mot);
	MOT *liste = tableH[indice];

	while(liste != NULL)
	{
		if(strcmp(liste->texte, mot) == 0)
			return 1;
		liste = liste->suivant;
	}

	return 0;
}


void insererFichier(MOT * tableH[] ,  char *nomFichier)
{
	FILE *f;
	char s[30];
	f=fopen(nomFichier,"r");
	while (fscanf(f,"%s",s)!=EOF){
	insererMot(tableH,s);
	}
	fclose(f);
}


void afficher(MOT * tableH[])
{


	int i = 0;

	for(i=0;i<LONGTABLE;i++)
	{

		if(tableH[i])
		{
			MOT * liste = tableH[i];
			printf("\n");
			while(liste)
			{
				printf("%s -->" , liste->texte );
				liste = liste->suivant;
			}

		}else printf("\n NULL");
	}




}
