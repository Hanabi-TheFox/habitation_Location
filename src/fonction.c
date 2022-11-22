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

Habitation calculdistance(Habitation *dataHabitation, int int_tailleData, Habitation *X){
    // Faire le calcul pour les nbr_personnes_acceuillables
    // ( /!\ Penser à convertir les entiers en float car les fonctions math.h ne lise pas d'entiers)
    // Une fois que tout fonctionne, il faudra aussi le faire pour nbr_chambre et nbr_lit et donc
    // changer la variable distance dans la structure Habitation pour en faire un tableau de taille 3
    // Le return doit être le tableau dataHabitation avec les distances calculées
    for (int i = 0; i < int_tailleData; i++){ //pour chaque logement, on calcula sa distance avec x selon 3 attributs
        // On calcule la distance par rapport à nbr_personnes_acceuillables
        dataHabitation[i].float_distance_acceuillables = distance((float)X->int_nbr_personnes_acceuillables, (float)dataHabitation[i].int_nbr_personnes_acceuillables); //juste pour tester avec 1 distance
        dataHabitation[i].float_distance[0] = distance((float)X->int_nbr_personnes_acceuillables, (float)dataHabitation[i].int_nbr_personnes_acceuillables);
        // On calcule la distance par rapport à nbr_chambre
        dataHabitation[i].float_distance[1] = distance(X->float_nbr_chambre, dataHabitation[i].float_nbr_chambre);
        // On calcule la distance par rapport à nbr_lit
        dataHabitation[i].float_distance[2] = distance(X->float_nbr_lit, dataHabitation[i].float_nbr_lit);
        // On calcule la distance_final
        dataHabitation[i].float_distance_final = sqrt((dataHabitation[i].float_distance[0]+dataHabitation[i].float_distance[1]+dataHabitation[i].float_distance[2]));
    }

    return *dataHabitation;
}

float distance(float float_X, float float_Y){
    float distance;
    // On calcule la distance entre float_x et float_y

    distance = pow(float_X - float_Y,2) ; //(x - y)²
    distance = sqrt(distance); 
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

/* On passe en commentaire le temps de tester les autres fonctions
Habitation triDistance(Habitation *dataHabitation, int int_tailleData){
    triRapide(dataHabitation,int_tailleData); //trie recursivement dataHabitation selon les distances de similarité
    return(*dataHabitation);
}

void permuter(Habitation *a,Habitation *b) {
    Habitation tmp = *a; //la valeur de la variable qui pointe a est affecté à 'tmp'
    *a = *b;
    *b = tmp;  //permutation simple entre 'a' et 'b'
}

void triRapide(Habitation *tab, int length) {

    srand( time(NULL) );
    triRapideRecursive(tab,0,length-1); //appel de la fonction recursive

}

void triRapideRecursive(Habitation *tab, int low, int hight){

    if (low < hight) { //si l'élement de gauche est encore plus petit que l'élement de droite
        //on arrete quand low > hight
    int pivot_index = partition(tab,low,hight);
    triRapideRecursive(tab,low,pivot_index-1);
    triRapideRecursive(tab,pivot_index+1,hight);
    }
}

int partition(Habitation *tab,int low, int hight) {

    int pivot_index = low + ( rand() % (hight-low)); //on prend un index pour le pivot aleatoire

    if (pivot_index != hight) { //si l'index n'est pas deja le dernier
        swap(&tab[pivot_index],&tab[hight]); //on permute le pivot avec le dernier élement
                                        //le pivot est maintenant place à la fin
    }

    float pivot_value = tab[hight].float_distance; // tab[hight] est le pivot

    int i = low; //pour prendre l'index d'un élement plus grand que le pivot pour permuter
                        //avec une valeur plus petite que le pivot

    for (int j = low; j < hight;j++) {
            
            if ( tab[j].float_distance <= pivot_value ) {
                permuter(&tab[i],&tab[j]); // on permute la valeur
                i++;
            }

    }
    swap(&tab[i],&tab[hight]); //tab[i] marque l'élement qui partitionne le tableau
                                //donc on permute avec le pivot à la fin
                                //tab[i] est au final le pivot
    return i; //on retoune la position du pivot
}
*/

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
