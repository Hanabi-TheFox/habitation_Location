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
		X.int_id = 5555;
		X.float_nbr_personnes_acceuillables = 4;
		X.float_nbr_chambre = 3;
		X.float_nbr_salle_de_bain = 2;
		X.float_nbr_lit = 3;
		//X.float_prix n'est pas connu.
		X.float_nuit_minimum = 1;
		X.float_nuit_maximum = 12;
		X.float_nombre_de_retour = 0; // Forcément 0 car le logement n'a pas encore été loué

		// Lecture du fichier airbnb_donees_propre.csv
		*dataHabitation = lecturedata(dataHabitation, "data/airbnb_donnees_propre.csv");
		
		// QUESTION A
		//Calcul de la distance entre le candidat et les logements de la base de donnée
		*dataHabitation = calculdistance(dataHabitation, int_tailledata, &X); 

		// QUESTION B
		// Permutation des données du tableau dataHabitation
		*dataHabitation = permutationAleatoire(dataHabitation, int_tailledata);
		// On trie le tableau dataHabitation
		*dataHabitation = triRapide(dataHabitation, int_tailledata);

		// QUESTION C
		// Calcul du prix du logement
		int int_K = k;
		X.float_prix = calculPrix(dataHabitation, int_K);

		//affichage(dataHabitation, int_tailledata);
		
		printf("Voici les données du logement candidat:\n");
		sleep(intSleep);
		printf("id = %d\n", X.int_id);
		sleep(intSleep);
		printf("nombre de personnes acceuillables = %.2f\n", X.float_nbr_personnes_acceuillables);
		sleep(intSleep);
		printf("nombre de chambre = %.2f\n", X.float_nbr_chambre);
		sleep(intSleep);
		printf("nombre de salle de bain = %.2f\n", X.float_nbr_salle_de_bain);
		sleep(intSleep);
		printf("nombre de lit = %.2f\n", X.float_nbr_lit);
		sleep(intSleep);
		printf("prix = à déterminer\n");
		sleep(intSleep);
		printf("nuit minimum = %.2f\n", X.float_nuit_minimum);
		sleep(intSleep);
		printf("nuit maximum = %.2f\n\n", X.float_nuit_maximum);
		sleep(intSleep*3);
		printf("On va maintenant prédir le prix du logement candidat\n");
		printf("En comparant les %d logements les plus similaire d'après notre modèle\n\n", int_K);
		sleep(intSleep*5);
		printf("Calcul en cours...\n\n");
		sleep(intSleep*2);
		// Affichage du prix du logement
		printf("Le prix prédit du logement est de %.2f €\n\n", X.float_prix);
		sleep(intSleep*4);

		//QUESTION D SUJET 1:
		int_K = 0;
		printf("On calcule maintenant pour 3 modeles differents avec le même candidat X\n");
		sleep(intSleep*2);
		printf("Modele 1 -> 1 Categorie\n");
		sleep(intSleep*2);
		printf("Modele 2 -> 2 Categories\n");
		sleep(intSleep*2);
		printf("Modele 3 -> 3 Categories\n\n");
		sleep(intSleep*3);

		for (int j=1;j<=3;j++) { // j correspond au modele

			printf("\tCalcul pour le Modele %d\n",j);
			sleep(intSleep*2);
			// Lecture du fichier airbnb_donees_propre.csv
			*dataHabitation = lecturedata(dataHabitation, "data/airbnb_donnees_propre.csv");
			
			// Calcul de la distance entre le candidat et les logements de la base de donnée
			*dataHabitation = calculdistanceBonus(dataHabitation, int_tailledata, &X,j); 

			// Permutation des données du tableau dataHabitation
			*dataHabitation = permutationAleatoire(dataHabitation, int_tailledata);

			// On trie le tableau dataHabitation
			*dataHabitation = triRapide(dataHabitation, int_tailledata);

			// Calcul du prix du logement
			int_K = 5;

			for (int i=1;i<4;i++) {
				X.float_prix = calculPrix(dataHabitation, int_K*i);
				printf("Pour k = %d, le prix prédit est de %.2f €\n\n",int_K,X.float_prix);
				sleep(intSleep*2);
			}
			//affichage(dataHabitation, int_tailledata);
			// Affichage du prix du logement
		}
		printf("FIN SUJET 1\n");
		free(dataHabitation);
	}
	else if (Bonus == 1)
	{
	 
		// BONUS
		printf("\nPartie Bonus : Evaluation de la performance du modèle de prédiction\n");
		sleep(intSleep*2);
		printf("Question h):\ncalcul de la MAE pour le modele utilisant 3 categories :\n");
		sleep(intSleep*2);
		printf("1 - Nombre de personnes accueillables\n");
		sleep(intSleep*2);
		printf("2 - Nombre de chambres\n");
		sleep(intSleep*2);
		printf("3 - Nombre de lits\n\n");
		sleep(intSleep*2);
		printf("Nous ferons ce modele avec k = %d\n\n",k);
		sleep(intSleep*2);
		printf("Cette étape peur prendre du temps, merci de patienter...\n\n");
		// Déclaration des variables
		int int_tailledata = tailledata("data/airbnbEntrainement.csv");
		if(int_tailledata == 0){
			printf("Erreur lors de la lecture du fichier airbnbEntrainement.csv\n");
			printf("il se peut que le fichier soit corrompu ou ne possède aucune données.\n");
			exit(0);
		}
        if(k > int_tailledata){
            printf("Erreur, k est plus grand que la taille du tableau\n");
            printf("veuillez modifier la valeur de k dans struct.h\n");
            exit(0);
        }
		// QUESTION E
		// Tableau contenant les données du fichier airbnbEntrainement.csv
		Habitation *tabEntrainement = malloc(int_tailledata * sizeof(Habitation));
		if (tabEntrainement == NULL){
			printf("Erreur d'allocation mémoire");
			exit(1);
		}
		*tabEntrainement = lecturedata(tabEntrainement, "data/airbnbEntrainement.csv");
		//printf("Affichage tableau tabEntrainement\n \n");
		//affichage(tabEntrainement, int_tailledata);
		int int_tailledataTabTest = tailledata("data/airbnbTest.csv");
		if(int_tailledataTabTest == 0){
			printf("Erreur lors de la lecture du fichier airbnbTest.csv\n");
			printf("il se peut que le fichier soit corrompu ou ne possède aucune données.\n");
			exit(0);
		}
		// QUESTION F
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

		// QUESTION F) POUR LE CALCUL DES PRIX PREDIT EN DONNANT COMME RESULTAT
		//tabPrediction AYANT LES PRIX FRUITS DU RESULTAT DES PRIX MOYENS POUR CHAQUE   
		//LOGEMENT CANDIDAT X = tabTest[i] ET LES LOGEMENTS DANS tabEntrainement

		//X = tabTest[i] : on applique l'algorithme avec tous les tabEntrainement
		//pour ce dandidat et on stock dans tabPredit[i] 
		for (int i=0;i<int_tailledataTabTest;i++) {
 
			*tabEntrainement = calculdistance(tabEntrainement, int_tailledata, &tabTest[i]); 

			// Permutation des données du tableau dataHabitation
			*tabEntrainement = permutationAleatoire(tabEntrainement, int_tailledata); //tailledata = taille de tabEntrainement

			// On trie le tableau dataHabitation
			*tabEntrainement = triRapide(tabEntrainement, int_tailledata);

			// Calcul du prix du logement
			tabPrediction[i] = calculPrix(tabEntrainement,k);
			//printf("tabPrediction[%d] = %f\n",i, tabPrediction[i]);
		}

		// PARTIE MAE
		// QUESTION H
		// TabPrix contenant pour chaque case les valeur de prix réel et prix prédit
		Prix *tabPrix = malloc(int_tailledataTabTest * sizeof(Prix));

		for (int i=0;i<int_tailledataTabTest;i++) {
			tabPrix[i].float_prix_reel = tabTest[i].float_prix; //number_of_review a devenu prix à cause du decalage des attributs dans les fichiers airbnbEntrainement et airbnbTest
			tabPrix[i].float_prix_predit = tabPrediction[i];        
		}

		/*for (int i=0;i<int_tailledataTabTest;i++) {
			printf("TabPrix[%d] rééel = %f | TabPrix[%d] prédit = %f\n",i,tabPrix[i].float_prix_reel,i,tabPrix[i].float_prix_predit = tabPrediction[i]);
		}*/

		//CALCUL MAE MODELE 3 categories avec 'k' défini dans struct.h
		//https://en.wikipedia.org/wiki/Mean_absolute_error
		float float_MAE = calculMAE(tabPrix,int_tailledataTabTest);
		printf("Notre MAE pour le modele 3 categories et k = %d vaut MAE = %f\n\n",k,float_MAE);
		sleep(intSleep*3);

		//--------------------------------------------------------------
		// QUESTION I
		printf("Question i)\n");
		sleep(intSleep*2);
		printf("Nous allons maintenant calculer les MAE pour les modeles suivants:\n\n");
		sleep(intSleep*2);
		printf("MODELE 1 : 1 categorie\n");
		sleep(intSleep*2);
		printf("MODELE 2 : 2 categories\n");
		sleep(intSleep*2);
		printf("MODELE 3 : 3 categories\n\n");
		sleep(intSleep*2);
		printf("Et ce, avec k = 5, k = 10 et k = 15\n\n");
		sleep(intSleep*3);
		int int_K;
		for (int j=1;j<=3;j++){
			printf("MODELE %d\n",j);
			printf("Calcul en cours...\n");
			printf("Cette opération peut prendre plus d'1 minute, merci de patienter...\n\n");
			for (int i=0;i<int_tailledataTabTest;i++) {
				//on passe les parametres pour le calcul distance dans la partie bonus
				//on doit passer le tabEntrainement, sa taille, les candidats dans tabTest et le modele choisi (1,2 ou 3);
				*tabEntrainement = calculdistanceBonus(tabEntrainement, int_tailledata, &tabTest[i],j); 
				
				// Permutation des données du tableau On trie le tableau tabEntrainement
				*tabEntrainement = permutationAleatoire(tabEntrainement, int_tailledata); //tailledata = taille de tabEntrainement

				// On trie le tableau tabEntrainement
				*tabEntrainement = triRapide(tabEntrainement, int_tailledata);
			}

			//on calcule le MAE pour chaque 'k' different
			float float_MAE[3];
			for(int_K=1;int_K<=3;int_K++){
				printf("Pour k = %d :\n",int_K*5);
			
				// Calcul du prix du logement
				for (int l=0;l<int_tailledataTabTest;l++)
					tabPrediction[l] = calculPrix(tabEntrainement,int_K*5);
				// printf("tabPrediction[%d] = %f\n",i, tabPrediction[i]);
				for (int l=0;l<int_tailledataTabTest;l++) {
					tabPrix[l].float_prix_reel = tabTest[l].float_prix;
					tabPrix[l].float_prix_predit = tabPrediction[l];        
				}
				float_MAE[int_K-1] = calculMAE(tabPrix,int_tailledataTabTest);
				printf("MAE = %f\n\n",float_MAE[int_K-1]);
				sleep(intSleep*2);
			}
			// QUESTION J
			// On cherche le meilleur k, donc le plus petit MAE
			float float_MAE_petit = float_MAE[0];
			int int_indice_petit = 0;
			for (int i = 1; i < 3; i++) {
				if (float_MAE[i] < float_MAE_petit) {
					float_MAE_petit = float_MAE[i];
					int_indice_petit = i;
				}
			}
			int_indice_petit++; // on ajoute 1 car on a commencé à 1
			printf("Le meilleur k pour le modele %d est k = %d",j,int_indice_petit*5);
			sleep(intSleep*2);
			printf("\n\n");
		}
		printf("Fin de la partie Bonus\n");
		
		// On libère la mémoire
		free(tabEntrainement);
		free(tabTest);
		free(tabPrediction);
		free(tabPrix);
		//free(tabMAE);
	}
	return(0);
}