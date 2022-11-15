//--------------------------------------------------
//---------- Propriété de Ethan et Renato ----------
//--------------------------------------------------

// Fichier Main
#include "fonction.h"

int main(){
    int sizedata = tailledata();
	// Tableau contenant les données du fichier airbnb_donees_propre.csv
    Habitation *dataHabitation = malloc(sizedata * sizeof(Habitation));
    if (dataHabitation == NULL){
        printf("Erreur d'allocation mémoire");
        exit(1);
    }
    // Habitation candidat dont on cherche à déterminer le prix
    //Habitation X;
    // [ Données les informations du candidat (sauf le prix)]
	// Tableau qui contiendra K lignes aléatoire du fichier airbnb_donees_propre.csv
	//Habitation dataHabitationRNG[k];
	*dataHabitation = lecturedata(dataHabitation);
    // on affiche les données du tableau
    printf("id;nbr_personnes_acceuillables;nbr_chambre;distance;similarite;prix;\n");
    for (int i = 0; i < sizedata; i++){
        printf("%d;%d;%f;%f;%f;%f;%d;%d\n", dataHabitation[i].int_id, dataHabitation[i].int_nbr_personnes_acceuillables, dataHabitation[i].float_nbr_chambre, dataHabitation[i].float_nbr_salle_de_bain, dataHabitation[i].float_nbr_lit, dataHabitation[i].float_prix, dataHabitation[i].int_nuit_minimum, dataHabitation[i].int_nuit_maximum);
    }

	// TODO : - Calculer la distance euclienne du teableau dataHabitation par rapport à X.
	// - Générer un autre tableau de taille K qui contiendra une permutation aléatoire des valeurs du tableau trié
	// - Trier le tableau de manière croissante par rapport à la variable "distance"
	// - Lire les k premières valeurs des tableaus (trié et randomisé) afin de 
	// déterminer la moyenne des prix des deux tableaux
	// Tester le programme en faisant varier k
	// Faire d'autre modèle utilisant une autre variable pour le calcul de la distance.
	// -> changer le "float float_distance" en "float float_distance[3]"
	// Pour respectivement : nbr_personnes_aceuillable, nbr_chambres et nbr_lit

    // Faire la partie bonus ?

    // On libère la mémoire
    free(dataHabitation);
	return(0);

}