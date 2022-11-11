#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main(){
    Habitation test;
    test.int_nbr_chambres = 2;
    test.int_nbr_lit = 3;
    test.int_nbr_personnes_acceuillables = 3;
    printf("Le main à été compilé\n");
    printf("L'habitation à %d nombre de chambres !", test.int_nbr_chambres);
    return(0);
}