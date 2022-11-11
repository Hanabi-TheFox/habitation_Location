// Fichier dans lequel seront écrits toutes les fonctions déclarés par fonction.h

#include <stdio.h>
#include "fonction.h"
#define N 80

int lecturedata(){
    FILE * fp;
    // Lecture du fichier airbnb_donnees_propre.csv
    fp = fopen("./data/airbnb_donnees_propre.csv", "r");
    if (fp == NULL){
        printf("Erreur fopen\n");
        return 1;
    }
    int i = 0;
    char ligne[N];
    Habitation dataHabitation[7918];
    // ligne contient la keme ligne de airbnb_donnees_propre.csv
    while(fgets(ligne, N, fp) != NULL)
    {
        printf("\n Ligne %d", i);
        // Reste à faire : On veut spliter la "ligne" par données séparé par des ","
        i++;
        printf("%s", ligne);
        //dataHabitation[i].float_nbr_chambre = 
    }
    return 0;
}