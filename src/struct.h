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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
// Définition de la structure "Habitation"
typedef struct Habitation{
	int int_id; //pas besoin d'etre en entier car l'id est toujours un entier dans les fichiers .csv
	float float_nbr_personnes_acceuillables;
	float float_nbr_chambre;
	float float_nbr_salle_de_bain;
	float float_nbr_lit;
	float float_prix;
	float float_nuit_minimum;
	float float_nuit_maximum;
	float float_nombre_de_retour;
    float float_distance[3]; //par rapport au candidat(logement) X
	float float_distance_final;
}Habitation;

#endif