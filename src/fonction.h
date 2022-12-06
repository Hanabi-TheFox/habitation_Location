//--------------------------------------------------
//---------- Propriété de Ethan et Renato ----------
//--------------------------------------------------

// Fichier dans lequel seront définis toutes les fonctions utilisés par main.c

#include "struct.h"

// fonction retournant le nombre de ligne du fichier airbnb_donnees_propre.csv
int tailledata(char *char_NomFichier);
// Fonction créant le tableau qui contiendra toutes les habitations 
// du fichier airbnb_donnees_propre.csv
Habitation lecturedata(Habitation *dataHabitation, char *char_NomFichier); 
// Fonction qui affiche les données d'un tableau de type Habitation
void affichage(Habitation *dataHabitation, int int_taille);
// Fonction renvoyant le tableau avec la distance finale entre chaque habitation et le candidat
Habitation calculdistance(Habitation *dataHabitation, int int_tailledata, Habitation *X);
//Fontion CalculDistance pour la partie bonus (question (j))
Habitation calculdistanceBonus(Habitation *dataHabitation, int int_tailleData, Habitation *X,int int_numero_modele);
////renvoyant le MAE du modele choisi (entre 1..3 et 'k' entre 5,10 et 15)
float calculMAE(Habitation *tabEntrainement,int int_tailleTabEntrainement, Habitation *tabTest,int int_tailleTabTest, float *tabPrediction,Prix *tabPrix,int modele,int a);
// Fonction renvoyant la distance entre deux habitations
float distance(float float_X, float float_Y);
// Fonction permutant aléatoirement les données du tableau dataHabitation
Habitation permutationAleatoire(Habitation *dataHabitation, int int_tailleData);
// Fonction de tri rapide selon la distance finale
Habitation triRapide(Habitation *dataHabitation, int int_tailleData);
void triRapideRecursif(Habitation *dataHabitation, int int_debut, int int_fin);
int triRapidePartition(Habitation *dataHabitation, int int_debut, int int_fin);
// Fonction calculant le prix moyen des deux tableaux afin de donner 
// le prix prédit du logement X.
float calculPrix(Habitation *dataHabitation, int int_K);