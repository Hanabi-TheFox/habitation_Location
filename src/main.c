//--------------------------------------------------
//---------- Propriété de Ethan et Renato ----------
//--------------------------------------------------

// Fichier Main
#include "fonction.h"

int main(){
    if (Bonus == 0){
        // Déclaration des variables
        int int_tailledata = tailledata("data/airbnb_donnees_propre.csv");
        if(int_tailledata == 0){
            printf("Erreur lors de la lecture du fichier airbnb_donnees_propre.csv\n");
            printf("il se peut que le fichier soit corrompu ou ne possède aucune données.\n");
            exit(0);
        }
        if(int_tailledata < k){
            printf("Le nombre de logement à comparer est supérieur au nombre de logement dans la base de donnée.\n");
            printf("Veuillez modifier la valeur de k dans le fichier struct.h\n");
            exit(0);
        }
        // Tableau contenant les données du fichier airbnb_donees_propre.csv
        Habitation *dataHabitation = malloc(int_tailledata * sizeof(Habitation));
        if (dataHabitation == NULL){
            printf("Erreur d'allocation mémoire");
            exit(1);
        }

        // Habitation candidat dont on cherche à déterminer le prix
        Habitation X;
        X.int_id = 5555; //on choisit le candidat (logement) d'indice 5555
        X.float_nbr_personnes_acceuillables = 4;
        X.float_nbr_chambre = 3;
        X.float_nbr_salle_de_bain = 2;
        X.float_nbr_lit = 3;
        //X.float_prix n'est pas connu.
        X.float_nuit_minimum = 1;
        X.float_nuit_maximum = 12;
        X.float_nombre_de_retour = 21;

        // Lecture du fichier airbnb_donees_propre.csv
        *dataHabitation = lecturedata(dataHabitation, "data/airbnb_donnees_propre.csv");
        
        // Calcul de la distance entre le candidat et les logements de la base de donnée
        *dataHabitation = calculdistance(dataHabitation, int_tailledata, &X); 

        // Permutation des données du tableau dataHabitation
        *dataHabitation = permutationAleatoire(dataHabitation, int_tailledata);

        // On trie le tableau dataHabitation
        *dataHabitation = triRapide(dataHabitation, int_tailledata);

        // Calcul du prix du logement
        int int_K = k;
        X.float_prix = calculPrix(dataHabitation, int_K);

        //affichage(dataHabitation, int_tailledata);
        
        // Affichage du prix du logement
        printf("En utilisant k = %d, le prix prédit du logement est de %f\n", int_K, X.float_prix);

        free(dataHabitation);
    }
    else if (Bonus == 1)
    {
     
        // BONUS
        printf("Partie Bonus : Evaluation de la performance du modèle de prédiction\n\n");
        // Déclaration des variables
        int int_tailledata = tailledata("data/airbnbEntrainement.csv");
        if(int_tailledata == 0){
            printf("Erreur lors de la lecture du fichier airbnbEntrainement.csv\n");
            printf("il se peut que le fichier soit corrompu ou ne possède aucune données.\n");
            exit(0);
        }
        // Tableau contenant les données du fichier airbnbEntrainement.csv
        Habitation *tabEntrainement = malloc(int_tailledata * sizeof(Habitation));
        if (tabEntrainement == NULL){
            printf("Erreur d'allocation mémoire");
            exit(1);
        }
        *tabEntrainement = lecturedata(tabEntrainement, "data/airbnbEntrainement.csv");
        //printf("Affichage tableau tabEntrainement\n \n");
        //affichage(tabEntrainement, int_tailledata);
        // On va calculer le MAE pour toutes les valeurs de K possible de 0 à K_max.
        int K_max = int_tailledata;
        int int_tailledataTabTest = tailledata("data/airbnbTest.csv");
        if(int_tailledataTabTest == 0){
            printf("Erreur lors de la lecture du fichier airbnbTest.csv\n");
            printf("il se peut que le fichier soit corrompu ou ne possède aucune données.\n");
            exit(0);
        }
        // Tableau contenant les données du fichier airbnbTest.csv
        Habitation *tabTest = malloc(int_tailledataTabTest * sizeof(Habitation));
        *tabTest = lecturedata(tabTest,"data/airbnbTest.csv");
        //printf("Affichage tableau tabTest\n \n");
        //affichage(tabTest, int_tailledata);
      
        // On créer un tableau de la même taille que le tableau de test qui contiendra les prix prédits
        float *tabPrediction = malloc(int_tailledataTabTest * sizeof(float));
        if (tabTest == NULL){
            printf("Erreur d'allocation mémoire pour tabTest");
            exit(1);
        }

        // QUESTION g) POUR LE CALCUL DES PRIX PREDIT EN DONNANT COMME RESULTAT
        //tabPrediction AYANT LES PRIX FRUITS DU RESULTAT DES PRIX MOYENS POUR CHAQUE   
        //LOGEMENT CANDIDAT X = tabTest[i] ET LES LOGEMENTS DANS tabEntrainement

        //X = tabTest[i] : on applique l'algorithme avec tous les tabEntrainement
        //pour ce dandidat et on stock dans tabPredit[i] 

      printf("Affichage tableau tabPrediction\n \n");
     
     for (int i=0;i<int_tailledataTabTest;i++) {
 
        *tabEntrainement = calculdistance(tabEntrainement, int_tailledata, &tabTest[i]); 

        // Permutation des données du tableau dataHabitation
        *tabEntrainement = permutationAleatoire(tabEntrainement, int_tailledata); //tailledata = taille de tabEntrainement

        // On trie le tableau dataHabitation
        *tabEntrainement = triRapide(tabEntrainement, int_tailledata);

        // Calcul du prix du logement
        int int_K = k; // k logements à comparer avec le logement X = tabTest[i]
        tabPrediction[i] = calculPrix(tabEntrainement,int_K);
        printf("tabPrediction[%d] = %f\n",i, tabPrediction[i]);
        }

        
    
        

        //PARTIE MAE
        // On créer le tableau qui contiendra les MAE pour chaque valeur de K
        // l'indice du tableau est la quantité de K, et sa valeur sera la valeur du MAE associée
        float *tabMAE = malloc(K_max * sizeof(float));

        printf("PARTIE BONUS : Question (h): calcul de la MAE pour le modele avec 3 categories\n");
        printf("Les categories sont les suviantes : \n \n");
        printf("1 - Nombre de personnes accueillables\n");
        printf("2 - Nombre de chambres \n");
        printf("3 - Nombre de lits\n");
        int int_K = k;
        printf("Nous ferons ce modele avec k = %d(constante dans fichier le struct.h)\n",int_K);
        printf("Ce 'k' = %d a été utilisée pour calculer les prix prédits dans la question (g)\n",int_K);

        //TabPrix contenant pour chaque case les valeur de prix réel et prix prédit
    
        Prix *tabPrix = malloc(int_tailledataTabTest * sizeof(Prix));

        for (int i=0;i<int_tailledataTabTest;i++) {
            tabPrix[i].float_prix_reel = tabTest[i].float_prix; //number_of_review a devenu prix à cause du decalage des attributs dans les fichiers airbnbEntrainement et airbnbTest
            tabPrix[i].float_prix_predit = tabPrediction[i];        
        }

        for (int i=0;i<int_tailledataTabTest;i++) {
            printf("TabPrix[%d] rééel = %f | TabPrix[%d] prédit = %f\n",i,tabPrix[i].float_prix_reel,i,tabPrix[i].float_prix_predit = tabPrediction[i]);
        }

        //CALCUL MAE MODELE 3 categories avec 'k' défini dans struct.h

        

        printf("FIN PROGRAMME");

        // TODO : - Calculer la distance euclienne du tableau tabEntrainement par rapport à chaque habitation de tabTest.
        // Mettre les prix prédits dans le tableau tabPrediction
        // Comparer les prix prédits avec les prix réels de tabTest
        // calculer le MAE du modèle en faisant varier k à chaque fois
        // Trouver la valeur de k qui donne le meilleur MAE (celle avec la MAE la plus faible)
        // --> On cherche le minimum du tableau
        
        // On libère la mémoire
        free(tabEntrainement);
        free(tabTest);
        free(tabPrediction);
        free(tabPrix);
        free(tabMAE);
    }
	return(0);

}