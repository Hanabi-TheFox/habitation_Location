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
    return i;
}

Habitation lecturedata(Habitation *dataHabitation){
    // "Erreur : Segmentation fault (core dumped)" (Il y a un problème avec la fonction)
    FILE *fichier = NULL;
    fichier = fopen("data/airbnb_donnees_propre.csv", "r");
    // Vérification du fopen
    if (fichier == NULL){
        printf("Erreur lors de l'ouverture du fichier airbnb_donnees_propre.csv\n");
        exit(0);
    }
    char chaine[N] = "";
    int i = 0;
    // On anticipe la taille du token
    char *token = malloc(100 * sizeof(char));
    if (fichier != NULL){
        // On saute la première ligne
        fgets(chaine, N, fichier);
        while (fgets(chaine, N, fichier) != NULL){
            // Le gets fonctionne bien, j'ai pu faire un print de toutes les lignes du csv.
            // c'est la suite qui pose problème
            // On récupère le premier token
            token = strtok(chaine, ",");
            // On récupère les autres tokens
            while (token != NULL){
                // On récupère l'id
                if (i == 0){
                    dataHabitation[i].int_id = atoi(token);
                }
                // On récupère le nombre de personnes acceuillables
                if (i == 1){
                    dataHabitation[i].int_nbr_personnes_acceuillables = atoi(token);
                }
                // On récupère le nombre de chambre
                if (i == 2){
                    dataHabitation[i].float_nbr_chambre = atof(token);
                }
                // On récupère le nombre de salle de bain
                if (i == 3){
                    dataHabitation[i].float_nbr_salle_de_bain = atof(token);
                }
                // On récupère le nombre de lit
                if (i == 4){
                    dataHabitation[i].float_nbr_lit = atof(token);
                }
                // On récupère le prix
                if (i == 5){
                    dataHabitation[i].float_prix = atof(token);
                }
                // On récupère le nombre de nuit minimum
                if (i == 6){
                    dataHabitation[i].int_nuit_minimum = atoi(token);
                }
                // On récupère le nombre de nuit maximum
                if (i == 7){
                    dataHabitation[i].int_nuit_maximum = atoi(token);
                }
                // On récupère le nombre de retour
                if (i == 8){
                    dataHabitation[i].int_nombre_de_retour = atoi(token);
                }
                // On récupère la distance
                if (i == 9){
                    dataHabitation[i].float_distance = atof(token);
                }
                // On récupère le prochain token
                token = strtok(NULL, ",");
                i++;
            }
            i = 0;
        }
        fclose(fichier);
        // On libère la mémoire
        free(token);
        return *dataHabitation;
    }
    return *dataHabitation;
}