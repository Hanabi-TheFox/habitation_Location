//--------------------------------------------------
//---------- Propriété de Ethan et Renato ----------
//--------------------------------------------------

// Fichier Main
#include "fonction.h"

int main(){
    if (Bonus == 0){
        // Déclaration des variables
        int int_tailledata = tailledata("data/airbnb_donnees_propre.csv");
        if(int_tailledata == 0){
            printf("Erreur lors de la lecture du fichier airbnb_donnees_propre.csv\n");
            printf("il se peut que le fichier soit corrompu ou ne possède aucune données.\n");
            exit(0);
        }
        if(int_tailledata < k){
            printf("Le nombre de logement à comparer est supérieur au nombre de logement dans la base de donnée.\n");
            printf("Veuillez modifier la valeur de k dans le fichier struct.h\n");
            exit(0);
        }
        // Tableau contenant les données du fichier airbnb_donees_propre.csv
        Habitation *dataHabitation = malloc(int_tailledata * sizeof(Habitation));
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

        // Lecture du fichier airbnb_donees_propre.csv
        *dataHabitation = lecturedata(dataHabitation, "data/airbnb_donnees_propre.csv");
        
        // Calcul de la distance entre le candidat et les logements de la base de donnée
        *dataHabitation = calculdistance(dataHabitation, int_tailledata, &X); 

        // Permutation des données du tableau dataHabitation
        *dataHabitation = permutationAleatoire(dataHabitation, int_tailledata);

        // On trie le tableau dataHabitation
        *dataHabitation = triRapide(dataHabitation, int_tailledata);

        // Calcul du prix du logement
        int int_K = k;
        X.float_prix = calculPrix(dataHabitation, int_K);
        
        // Affichage du prix du logement
        printf("En utilisant k = %d, le prix prédit du logement est de %f\n", int_K, X.float_prix);

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