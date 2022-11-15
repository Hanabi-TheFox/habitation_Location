//--------------------------------------------------
//---------- Propriété de Ethan et Renato ----------
//--------------------------------------------------

// Fichier dans lequel seront écrits toutes les fonctions déclarés par fonction.h
#include "fonction.h"
#define N 80

int tailledata(void){
    FILE *fichier = NULL;
    fichier = fopen("data/airbnb_donnees_propre.csv", "r");
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

Habitation lecturedata(Habitation *dataHabitation){
    FILE *fichier = NULL;
    fichier = fopen("data/airbnb_donnees_propre.csv", "r");
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
                    dataHabitation[j].int_id = atoi(token);
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
                // On récupère la distance
                if (i == 9){
                    dataHabitation[j].float_distance = atof(token);
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

Habitation calculDistanceSimilarite(Habitation *dataHabitation, Habitation *X){
    // Faire le calcul pour les nbr_personnes_acceuillables
    // ( /!\ Penser à convertir les entiers en float car les fonctions math.h ne lise pas d'entiers)
    // Une fois que tout fonctionne, il faudra aussi le faire pour nbr_chambre et nbr_lit et donc
    // changer la variable distance dans la structure Habitation pour en faire un tableau de taille 3
    // Le return doit être le tableau dataHabitation avec les distances calculées
}

Habitation triDistance(Habitation *dataHabitation){
    // Surement faire un quicksort ?
    // Le return doit être le tableau dataHabitation trié selon les distances
}

Habitation generationTabRNG(Habitation *dataHabitation, Habitation *dataHabitationRNG){
    // Générer k nombre aléatoire et lire la k-ième ligne du tableau dataHabitation
    // pour le mettre dans la i-ème ligne du tableau dataHabitationRNG
    // Le return doit être le tableau dataHabitationRNG généré

    srand ( time(NULL) );
    int tailleDataHabitation = tailledata();
    for (int i=0;i<k;i++) {
        int swap_index = rand() % tailleDataHabitation; //on prend un index
                                    //aleatoire entr 0..taille du tab des habitations

        //la valeur contenue dans dataHabitationRNG[i] = dataHabitation[swap_index]
        *(dataHabitationRNG+i) = *(dataHabitation+swap_index);
        
    }

    return *dataHabitationRNG;
}

float moyennePrix(Habitation *dataHabitation, Habitation *dataHanitationRNG){
    // Sommer les prix des k lignes du tableau dataHabitation et dataHabitationRNG
    // Renvoyer la moyenne qui sera le prix du candidat.
    //dataHabitation deja trié

    float float_prix_dataHabitation;
    float float_prix_dataHabitationRNG;

    for (int i = 0;i<k;i++) {
        float_prix_dataHabitation = float_prix_dataHabitation + *(dataHabitation+i)->float_prix;
    }
}