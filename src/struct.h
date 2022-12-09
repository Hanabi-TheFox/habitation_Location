//--------------------------------------------------
//---------- Propriété de Ethan et Renato ----------
//--------------------------------------------------

// Fichier dans lequel est définit la structure Habitation ainsi que des données numérique
// Importantes comme k ou data_Max_Value

#ifndef STRUCT_H
#define STRUCT_H
// Nombre de logement à comparer au candidat.
// (ne dois pas dépasser le nombre de lignes dans airbnb_donnees_propre.csv)
#define k 200
#define Bonus 0 // 0 = désactivé, 1 = activé
// Pour une meilleure lecture, il est préférable de garder le mode lent activé
#define intSleep 1 // 0 = désactivé, 1 = activé (Evitez de mettre d'autres valeurs)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
// Définition de la structure "Habitation"
typedef struct Habitation{
	int int_id; //indice [0] pas besoin d'etre en réel car l'id est toujours un entier dans les fichiers .csv
	float float_nbr_personnes_acceuillables; //indice [1]
	float float_nbr_chambre; //indice [2]
	float float_nbr_salle_de_bain; //indice [3]
	float float_nbr_lit; //indice [4]			//indices par rapport aux valeurs dans les fichiers csv
	float float_prix; //indice [5]			//qui peuvent changer d'ordre selon le fichier
	float float_nuit_minimum; //indice [6]
	float float_nuit_maximum; //indice [7]
	float float_nombre_de_retour; //indice [8]
	float float_distance[3]; //par rapport au candidat(logement) X
	float float_distance_final;
}Habitation;

typedef struct Prix{
	float float_prix_reel; //valeur de prix reel contenu dans tabTest
	float float_prix_predit; // valeur de prix prédit contenu dans tabPrediction

}Prix;

#endif