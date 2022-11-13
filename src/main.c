//--------------------------------------------------
//---------- Propriété de Ethan et Renato ----------
//--------------------------------------------------

// Fichier Main
#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

int main(){
	// Tableau contenant les données du fichier airbnb_donees_propre.csv
	Habitation dataHabitation[data_Max_Value];
    // Habitation candidat dont on cherche à déterminer le prix
    Habitation X;
    // [ Données les informations du candidat (sauf le prix)]
	// Tableau qui contiendra K lignes aléatoire du fichier airbnb_donees_propre.csv
	Habitation dataHanitationRNG[k];
	int test;
	test = lecturedata(dataHabitation);
	// Reste à faire : - Calculer la distance euclienne du teableau dataHabitation par rapport à X.
	// - Trier le tableau de manière croissante par rapport à la variable "distance"
	// - Générer un autre tableau de taille K qui contiendra une permutation aléatoire des valeurs du tableau trié
	// - Lire les k premières valeurs des tableaus (trié et randomisé) afin de 
	// déterminer la moyenne des prix des deux tableaux
	// Tester le programme en faisant varier k
	// Faire d'autre modèle utilisant une autre variable pour le calcul de la distance.
	// -> changer le "float float_distance" en "float float_distance[3]"
	// Pour respectivement : nbr_personnes_aceuillable, nbr_chambres et nbr_lit
	return(0);

}