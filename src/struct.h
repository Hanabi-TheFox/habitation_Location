//--------------------------------------------------
//---------- Propriété de Ethan et Renato ----------
//--------------------------------------------------

// Fichier dans lequel est définit la structure Habitation ainsi que des données numérique
// Importantes comme k ou data_Max_Value

#ifndef STRUCT_H
#define STRUCT_H
#define k 50 // Nombre de logement à comparer au candidat. Max : data_Max_Value (défaut : 7918)
#define data_Max_Value 7918 // A changer si le nombre de données du fichier data est différent.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
// Définition de la structure "Habitation"
// Les variables sont tous en float car on ne peut pas utiliser 
// des entiers pour calculer la distance euclidienne.
typedef struct Habitation{
	int int_id;
	int int_nbr_personnes_acceuillables;
	float float_nbr_chambre;
	float float_nbr_salle_de_bain;
	float float_nbr_lit;
	float float_prix;
	int int_nuit_minimum;
	int int_nuit_maximum;
	int int_nombre_de_retour;
	float float_distance;
}Habitation;

#endif