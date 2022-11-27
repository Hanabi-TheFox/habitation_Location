//--------------------------------------------------
//---------- Propriété de Ethan et Renato ----------
//--------------------------------------------------

// Fichier dans lequel seront écrits toutes les fonctions déclarés par fonction.h
#include "fonction.h"
#define N 80

int tailledata(char *char_NomFichier){
    FILE *fichier = NULL;
    fichier = fopen(char_NomFichier, "r");
    // Vérification du fopen
    if (fichier == NULL){
        printf("Erreur lors de l'ouverture du fichier airbnb_donnees_propre.csv\n");
        exit(0);
    }
    int i = 0;
    char chaine[N] = "";
    if (fichier != NULL){
        while (fgets(chaine, N, fichier) != NULL){
            i++;
        }
        fclose(fichier);
    }
    // On enlève 1 car la première ligne du fichier est le nom des colonnes
    return i-1;
}

Habitation lecturedata(Habitation *dataHabitation, char *char_NomFichier){
    FILE *fichier = NULL;
    fichier = fopen(char_NomFichier, "r");
    // Vérification du fopen
    if (fichier == NULL){
        printf("Erreur lors de l'ouverture du fichier airbnb_donnees_propre.csv\n");
        exit(0);
    }
    char chaine[N] = "";
    int i = 0;
    int j = 0;
    // On anticipe la taille du token
    char *token = malloc(100 * sizeof(char));
    if (fichier != NULL){
        // On saute la première ligne
        fgets(chaine, N, fichier);
        while (fgets(chaine, N, fichier) != NULL){
            // On récupère le premier token
            token = strtok(chaine, ",");
            // On récupère les autres tokens
            while (token != NULL){
                // On récupère l'id
                if (i == 0){
                    dataHabitation[j].int_id = atoi(token); //atoi pour convertir car token contient une chaine
                }
                // On récupère le nombre de personnes acceuillables
                if (i == 1){
                    dataHabitation[j].int_nbr_personnes_acceuillables = atoi(token);
                }
                // On récupère le nombre de chambre
                if (i == 2){
                    dataHabitation[j].float_nbr_chambre = atof(token);
                }
                // On récupère le nombre de salle de bain
                if (i == 3){
                    dataHabitation[j].float_nbr_salle_de_bain = atof(token);
                }
                // On récupère le nombre de lit
                if (i == 4){
                    dataHabitation[j].float_nbr_lit = atof(token);
                }
                // On récupère le prix
                if (i == 5){
                    dataHabitation[j].float_prix = atof(token);
                }
                // On récupère le nombre de nuit minimum
                if (i == 6){
                    dataHabitation[j].int_nuit_minimum = atoi(token);
                }
                // On récupère le nombre de nuit maximum
                if (i == 7){
                    dataHabitation[j].int_nuit_maximum = atoi(token);
                }
                // On récupère le nombre de retour
                if (i == 8){
                    dataHabitation[j].int_nombre_de_retour = atoi(token);
                }
                // On récupère le prochain token
                token = strtok(NULL, ","); 
                i++;
            }
            i = 0;
            j++;
        }
        fclose(fichier);
        // On libère la mémoire
        free(token);
        return *dataHabitation;
    }
    return *dataHabitation;
}

void affichage(Habitation *dataHabitation, int int_taille){
    for(int i = 0; i < int_taille; i++){
            //printf("%d, %d, %f, %f, %f, %f, %d, %d, %d, D = %f", dataHabitation[i].int_id, dataHabitation[i].int_nbr_personnes_acceuillables, dataHabitation[i].float_nbr_chambre, dataHabitation[i].float_nbr_salle_de_bain, dataHabitation[i].float_nbr_lit, dataHabitation[i].float_prix, dataHabitation[i].int_nuit_minimum, dataHabitation[i].int_nuit_maximum, dataHabitation[i].int_nombre_de_retour, dataHabitation[i].float_distance_final);
            // On affiche uniquement le prix et la distance.
            printf("Prix = %f, D = %f\n", dataHabitation[i].float_prix, dataHabitation[i].float_distance_final);
        }
}


Habitation calculdistance(Habitation *dataHabitation, int int_tailleData, Habitation *X){
    for (int i = 0; i < int_tailleData; i++){ //pour chaque logement, on calcula sa distance avec x selon 3 attributs
        // On calcule la distance par rapport à nbr_personnes_acceuillables
        dataHabitation[i].float_distance[0] = distance((float)X->int_nbr_personnes_acceuillables, (float)dataHabitation[i].int_nbr_personnes_acceuillables);
        // On calcule la distance par rapport à nbr_chambre
        dataHabitation[i].float_distance[1] = distance(X->float_nbr_chambre, dataHabitation[i].float_nbr_chambre);
        // On calcule la distance par rapport à nbr_lit
        dataHabitation[i].float_distance[2] = distance(X->float_nbr_lit, dataHabitation[i].float_nbr_lit);
        // On calcule la distance_final qui est la racine carré de la somme des carrés des distances
        dataHabitation[i].float_distance_final = ((dataHabitation[i].float_distance[0]+dataHabitation[i].float_distance[1]+dataHabitation[i].float_distance[2]));
        dataHabitation[i].float_distance_final = sqrt(dataHabitation[i].float_distance_final);
    }

    return *dataHabitation;
}

float distance(float float_X, float float_Y){
    float distance;
    // On calcule la distance entre float_x et float_y

    distance = pow(float_X - float_Y,2) ; //(x - y)²
    return distance;
}

Habitation permutationAleatoire(Habitation *dataHabitation, int int_tailleData){
    // Initialisation de rand
    srand ( time(NULL) );
    for(int i = 0; i < int_tailleData; i++){
        int j = rand() % int_tailleData;
        // On permute les données
        Habitation temp = dataHabitation[i];
        dataHabitation[i] = dataHabitation[j];
        dataHabitation[j] = temp;
    }
    return *dataHabitation;
}

// On trie les données par distance en utilisant le tri rapide
Habitation triRapide(Habitation *dataHabitation, int int_tailleData){
    // On trie les données
    triRapideRecursif(dataHabitation, 0, int_tailleData-1);
    return *dataHabitation;
}

void triRapideRecursif(Habitation *dataHabitation, int int_debut, int int_fin){
    if (int_debut < int_fin){
        int int_pivot = triRapidePartition(dataHabitation, int_debut, int_fin);
        triRapideRecursif(dataHabitation, int_debut, int_pivot-1);
        triRapideRecursif(dataHabitation, int_pivot+1, int_fin);
    }
}

int triRapidePartition(Habitation *dataHabitation, int int_debut, int int_fin){
    float float_pivot = dataHabitation[int_fin].float_distance_final;
    int int_i = int_debut-1;
    for (int int_j = int_debut; int_j < int_fin; int_j++){
        if (dataHabitation[int_j].float_distance_final <= float_pivot){
            int_i++;
            Habitation temp = dataHabitation[int_i];
            dataHabitation[int_i] = dataHabitation[int_j];
            dataHabitation[int_j] = temp;
        }
    }
    Habitation temp = dataHabitation[int_i+1];
    dataHabitation[int_i+1] = dataHabitation[int_fin];
    dataHabitation[int_fin] = temp;
    return int_i+1;
}


float calculPrix(Habitation *dataHabitation, int int_K){
    // Sommer les prix des k lignes du tableau dataHabitation et dataHabitationRNG
    // Renvoyer la moyenne qui sera le prix du candidat.

    float float_prix_dataHabitation;
    float moyenne_prix;

    for (int i = 0;i<int_K;i++) {
        float_prix_dataHabitation += dataHabitation[i].float_prix;
    }

    moyenne_prix = float_prix_dataHabitation/int_K;

    return moyenne_prix;

}
