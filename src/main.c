#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

int main(){
    Habitation test;
    test.float_nbr_chambre = 2;
    test.float_nbr_lit = 3;
    test.int_nbr_personnes_acceuillables = 3;
    printf("Le main à été compilé\n");
    printf("L'habitation à %f nombre de chambres !", test.float_nbr_chambre);
    int test2;
    test2 = lecturedata();
    return(0);

}