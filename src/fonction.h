//--------------------------------------------------
//---------- Propriété de Ethan et Renato ----------
//--------------------------------------------------

// Fichier dans lequel seront définis toutes les fonctions utilisés par main.c

#include "struct.h"

// fonction retournant le nombre de ligne du fichier airbnb_donnees_propre.csv
int tailledata(void);
// Fonction créant le tableau qui contiendra toutes les habitations 
// du fichier airbnb_donnees_propre.csv
Habitation lecturedata(Habitation *dataHabitation);
// Fonction calculant la distance euclidienne de chaque paramètre entre
// les Data et l'habitation X
void calculDistanceSimilarite(Habitation *dataHabitation, Habitation *X); // Pas commencé
// Fonction triant le tableau dataHabitation de façon croissant selon 
// la variable float_distance
void triDistance(Habitation *dataHabitation); // Pas commencé
// Fonction générant le tableau de taille k contenant une permutation
// aléatoire du fichier airbnb_donnees_propre.csv
void generationTabRNG(Habitation *dataHabitation, Habitation *dataHanitationRNG); // Pas commencé //faire 0.. data_Max_Value
// Fonction calculant le prix moyen des deux tableaux afin de donner 
// le prix prédit du logement X.
float moyennePrix(Habitation *dataHabitation, Habitation *dataHanitationRNG); // Pas commencé //FAIRE