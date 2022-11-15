//--------------------------------------------------
//---------- Propriété de Ethan et Renato ----------
//--------------------------------------------------

// Fichier Main
#include "fonction.h"

int main(){
    int sizedata = tailledata();
    if(sizedata = 0){
        printf("Erreur lors de la lecture du fichier airbnb_donnees_propre.csv\n");
        printf("il se peut que le fichier soit corrompu ou ne possède aucune données.\n");
        exit(0);
    }
    if(sizedata < k){
        printf("Le nombre de logement à comparer est supérieur au nombre de logement dans la base de donnée.\n");
        printf("Veuillez modifier la valeur de k dans le fichier struct.h\n");
        exit(0);
    }
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