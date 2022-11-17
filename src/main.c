//--------------------------------------------------
//---------- Propriété de Ethan et Renato ----------
//--------------------------------------------------

// Fichier Main
#include "fonction.h"

int main(){
    if (Bonus == 0){
        // Déclaration des variables
        int sizedata = tailledata("data/airbnb_donnees_propre.csv");
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
        Habitation X;
        X.int_id = 5555;
        X.int_nbr_personnes_acceuillables = 2;
        X.float_nbr_chambre = 1;
        X.float_nbr_salle_de_bain = 1;
        X.float_nbr_lit = 1;
        //X.float_prix n'est pas connu.
        X.int_nuit_minimum = 1;
        X.int_nuit_maximum = 12;
        X.int_nombre_de_retour = 21;

        // Tableau qui contiendra K lignes aléatoire du fichier airbnb_donees_propre.csv
        Habitation dataHabitationRNG[k];

        // Lecture du fichier airbnb_donees_propre.csv
        *dataHabitation = lecturedata(dataHabitation, "data/airbnb_donnees_propre.csv");

        // TODO : - Calculer la distance euclienne du teableau dataHabitation par rapport à X.
        // - Générer un autre tableau de taille K qui contiendra une permutation aléatoire des valeurs du tableau trié
        // - Trier le tableau de manière croissante par rapport à la variable "distance"
        // - Lire les k premières valeurs des tableaus (trié et randomisé) afin de 
        // déterminer la moyenne des prix des deux tableaux
        // Tester le programme en faisant varier k
        // Faire d'autre modèle utilisant une autre variable pour le calcul de la distance.
        // -> changer le "float float_distance" en "float float_distance[3]"
        // Pour respectivement : nbr_personnes_aceuillable, nbr_chambres et nbr_lit

        // On libère la mémoire
        free(dataHabitation);
    }
    else if (Bonus == 1)
    {
        /* (On va laisser la partie bonus en commentaire tant que la partie de base n'est pas fini)
        // BONUS
        printf("Partie Bonus : Evaluation de la performance du modèle de prédiction\n\n");
        // Déclaration des variables
        int sizedata = tailledata("data/airbnbEntrainement.csv");
        if(sizedata = 0){
            printf("Erreur lors de la lecture du fichier airbnbEntrainement.csv\n");
            printf("il se peut que le fichier soit corrompu ou ne possède aucune données.\n");
            exit(0);
        }
        // Tableau contenant les données du fichier airbnbEntrainement.csv
        Habitation *tabEntrainement = malloc(sizedata * sizeof(Habitation));
        if (tabEntrainement == NULL){
            printf("Erreur d'allocation mémoire");
            exit(1);
        }
        // On va calculer le MAE pour toutes les valeurs de K possible de 0 à K_max.
        int K_max = sizedata;
        int sizedata = tailledata("data/airbnbTest.csv");
        if(sizedata = 0){
            printf("Erreur lors de la lecture du fichier airbnbTest.csv\n");
            printf("il se peut que le fichier soit corrompu ou ne possède aucune données.\n");
            exit(0);
        }
        // Tableau contenant les données du fichier airbnbTest.csv
        Habitation *tabTest = malloc(sizedata * sizeof(Habitation));
        // On créer un tableau de la même taille que le tableau de test qui contiendra les prix prédits
        float *tabPrediction = malloc(sizedata * sizeof(float));
        if (tabTest == NULL){
            printf("Erreur d'allocation mémoire");
            exit(1);
        }
        // On créer le tableau qui contiendra les MAE pour chaque valeur de K
        // l'indice du tableau est la quantité de K, et sa valeur sera la valeur du MAE associée
        float *tabMAE = malloc(K_max * sizeof(float));

        // TODO : - Calculer la distance euclienne du tableau tabEntrainement par rapport à chaque habitation de tabTest.
        // Mettre les prix prédits dans le tableau tabPrediction
        // Comparer les prix prédits avec les prix réels de tabTest
        // calculer le MAE du modèle en faisant varier k à chaque fois
        // Trouver la valeur de k qui donne le meilleur MAE (celle avec la MAE la plus faible)
        // --> On cherche le minimum du tableau
        
        // On libère la mémoire
        free(tabEntrainement);
        free(tabTest);
        free(tabPrediction);
        free(tabMAE);
        */
    }
	return(0);

}