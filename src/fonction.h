//--------------------------------------------------
//---------- Propriété de Ethan et Renato ----------
//--------------------------------------------------

// Fichier dans lequel seront définis toutes les fonctions utilisés par main.c

#include "struct.h"

// fonction retournant le nombre de ligne du fichier airbnb_donnees_propre.csv
int tailledata(char *char_NomFichier); // FONCTIONNE
// Fonction créant le tableau qui contiendra toutes les habitations 
// du fichier airbnb_donnees_propre.csv
Habitation lecturedata(Habitation *dataHabitation, char *char_NomFichier); // FONCTIONNE
// Fonction renvoyant le tableau avec la distance finale entre chaque habitation et le candidat
Habitation calculdistance(Habitation *dataHabitation, int int_tailledata, Habitation *X);
// Fonction renvoyant la distance entre deux habitations
float distance(float float_X, float float_Y);
// Fonction permutant aléatoirement les données du tableau dataHabitation
Habitation permutationAleatoire(Habitation *dataHabitation, int int_tailleData); // FONCTIONNE
// Fonction triant le tableau dataHabitation de façon croissant selon 
// la variable float_distance
//methodes et fonctions pour faire le tri rapide du tableau dataHabitation
void permuter(Habitation *a,Habitation *b);
void triRapide(Habitation *tab, int length);
void triRapideRecursive(Habitation *tab, int low, int hight);
int partition(Habitation *tab,int low, int hight);
Habitation triDistance(Habitation *dataHabitation, int int_tailleData);
// Fonction calculant le prix moyen des deux tableaux afin de donner 
// le prix prédit du logement X.
float calculPrix(Habitation *dataHabitation, int int_K); // A TESTER