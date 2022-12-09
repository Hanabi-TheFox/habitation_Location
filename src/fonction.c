//--------------------------------------------------
//---------- Propriété de Ethan et Renato ----------
//--------------------------------------------------

// Fichier dans lequel seront écrits toutes les fonctions déclarés par fonction.h
#include "fonction.h"
#define N 200

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
		printf("Erreur lors de l'ouverture du fichier %s\n", char_NomFichier);
		exit(0);
	}
	// On saute la première ligne
	char chaine[N] = "";
	fgets(chaine, N, fichier);
	int i = 0;
	// Une ligne est écrit selon le format :
	// id,accommodates,bedrooms,bathrooms,beds,price,minimum_nights,maximum_nights,number_of_reviews
	// On peut donc récupérer les données avec un fscanf
	if( !(Bonus) ){
		while(
			fscanf(fichier, "%d,%f,%f,%f,%f,%f,%f,%f,%f", 
			&dataHabitation[i].int_id, 
			&dataHabitation[i].float_nbr_personnes_acceuillables,
			&dataHabitation[i].float_nbr_chambre,
			&dataHabitation[i].float_nbr_salle_de_bain,
			&dataHabitation[i].float_nbr_lit,
			&dataHabitation[i].float_prix,
			&dataHabitation[i].float_nuit_minimum,
			&dataHabitation[i].float_nuit_maximum,
			&dataHabitation[i].float_nombre_de_retour) != EOF)
			{i++;}
	} else { // Le prix n'est plus la 6ème colonne mais la 9ème
		while(
			fscanf(fichier, "%d,%f,%f,%f,%f,%f,%f,%f,%f", 
			&dataHabitation[i].int_id, 
			&dataHabitation[i].float_nbr_personnes_acceuillables,
			&dataHabitation[i].float_nbr_chambre,
			&dataHabitation[i].float_nbr_salle_de_bain,
			&dataHabitation[i].float_nbr_lit,
			&dataHabitation[i].float_nuit_minimum,
			&dataHabitation[i].float_nuit_maximum,
			&dataHabitation[i].float_nombre_de_retour,
			&dataHabitation[i].float_prix) != EOF)
			{i++;}

	}
	fclose(fichier);
	return *dataHabitation;
}

void affichage(Habitation *dataHabitation, int int_taille){
	for(int i = 0; i < int_taille; i++){
		printf("%d, %f %f, %f, %f, %f, %f, %f, %f, D = %f\n", dataHabitation[i].int_id, dataHabitation[i].float_nbr_personnes_acceuillables, dataHabitation[i].float_nbr_chambre, dataHabitation[i].float_nbr_salle_de_bain, dataHabitation[i].float_nbr_lit, dataHabitation[i].float_prix, dataHabitation[i].float_nuit_minimum, dataHabitation[i].float_nuit_maximum, dataHabitation[i].float_nombre_de_retour, dataHabitation[i].float_distance_final);
	}
}

Habitation calculdistance(Habitation *dataHabitation, int int_tailleData, Habitation *X){

	for (int i = 0; i < int_tailleData; i++){ //pour chaque logement, on calcula sa distance avec x selon 3 attributs
		// On calcule la distance par rapport à nbr_personnes_acceuillables
		dataHabitation[i].float_distance[0] = distance((float)X->float_nbr_personnes_acceuillables, (float)dataHabitation[i].float_nbr_personnes_acceuillables);
		// On calcule la distance par rapport à nbr_chambre
		dataHabitation[i].float_distance[1] = distance(X->float_nbr_chambre, dataHabitation[i].float_nbr_chambre);
		// On calcule la distance par rapport à nbr_lit
		dataHabitation[i].float_distance[2] = distance(X->float_nbr_lit, dataHabitation[i].float_nbr_lit);
		// On calcule la distance_final qui est la racine carré de la somme des carrés des distances
		dataHabitation[i].float_distance_final = ((dataHabitation[i].float_distance[0]+dataHabitation[i].float_distance[1]+dataHabitation[i].float_distance[2]));
		dataHabitation[i].float_distance_final = sqrt(dataHabitation[i].float_distance_final);
	}

	return *dataHabitation;
}

Habitation calculdistanceBonus(Habitation *dataHabitation, int int_tailleData, Habitation *X,int int_numero_modele){
	// On calcule distance pour le modele 1
		if ( int_numero_modele == 1) {
			for (int i = 0; i < int_tailleData; i++){ //pour chaque logement, on calcula sa distance avec x selon 3 attributs
				// On calcule la distance par rapport à nbr_personnes_acceuillables
				dataHabitation[i].float_distance[0] = distance((float)X->float_nbr_personnes_acceuillables, (float)dataHabitation[i].float_nbr_personnes_acceuillables);
				// On calcule la distance par rapport à nbr_chambre
				dataHabitation[i].float_distance[1] = 0; // on ne calcule pas pour une categorie
				// On calcule la distance par rapport à nbr_lit
				dataHabitation[i].float_distance[2] = 0; // on ne calcule pas pour une categorie
				// On calcule la distance_final qui est la racine carré de la somme des carrés des distances
				dataHabitation[i].float_distance_final = ((dataHabitation[i].float_distance[0]+dataHabitation[i].float_distance[1]+dataHabitation[i].float_distance[2]));
				dataHabitation[i].float_distance_final = sqrt(dataHabitation[i].float_distance_final);
			}
		return *dataHabitation;
		}

	//on calcule la distace pour le modele 2
	if (int_numero_modele == 2) {
		for (int i = 0; i < int_tailleData; i++){ //pour chaque logement, on calcula sa distance avec x selon 3 attributs
			// On calcule la distance par rapport à nbr_personnes_acceuillables
			dataHabitation[i].float_distance[0] = distance((float)X->float_nbr_personnes_acceuillables, (float)dataHabitation[i].float_nbr_personnes_acceuillables);
			// On calcule la distance par rapport à nbr_chambre
			dataHabitation[i].float_distance[1] = distance(X->float_nbr_chambre, dataHabitation[i].float_nbr_chambre);
			// On calcule la distance par rapport à nbr_lit
			dataHabitation[i].float_distance[2] = 0; // on ne calcule pas pour deux categorie
			// On calcule la distance_final qui est la racine carré de la somme des carrés des distances
			dataHabitation[i].float_distance_final = ((dataHabitation[i].float_distance[0]+dataHabitation[i].float_distance[1]+dataHabitation[i].float_distance[2]));
			dataHabitation[i].float_distance_final = sqrt(dataHabitation[i].float_distance_final);
		}
		return *dataHabitation;
	}
	// On calcule distance pour le modele 3
	if (int_numero_modele == 3) {
		for (int i = 0; i < int_tailleData; i++){ //pour chaque logement, on calcula sa distance avec x selon 3 attributs
			// On calcule la distance par rapport à nbr_personnes_acceuillables
			dataHabitation[i].float_distance[0] = distance((float)X->float_nbr_personnes_acceuillables, (float)dataHabitation[i].float_nbr_personnes_acceuillables);
			// On calcule la distance par rapport à nbr_chambre
			dataHabitation[i].float_distance[1] = distance(X->float_nbr_chambre, dataHabitation[i].float_nbr_chambre);
			// On calcule la distance par rapport à nbr_lit
			dataHabitation[i].float_distance[2] = distance(X->float_nbr_lit, dataHabitation[i].float_nbr_lit);
			// On calcule la distance_final qui est la racine carré de la somme des carrés des distances
			dataHabitation[i].float_distance_final = ((dataHabitation[i].float_distance[0]+dataHabitation[i].float_distance[1]+dataHabitation[i].float_distance[2]));
			dataHabitation[i].float_distance_final = sqrt(dataHabitation[i].float_distance_final);
		}
	return *dataHabitation;
	} else {
		//un soucis c'est passée
		printf("Probleme avec la fonction CalculDistanceBonus \nMessage ERRNO ; %s",strerror(errno));
	}
	return *dataHabitation;

}

float calculMAE(Prix *tabPrix,int int_tailleTabTest) {
	//PARTIE MAE
	// On crée le tableau qui contiendra les MAE pour chaque valeur de K
	// l'indice du tableau est la quantité de K, et sa valeur sera la valeur du MAE associée
	//float *tabMAE = malloc(K_max * sizeof(float));

	float float_MAE;
	for (int i=0;i<int_tailleTabTest;i++) {
		float tmp = tabPrix[i].float_prix_predit - tabPrix[i].float_prix_reel;
		tmp = fabs(tmp); // on prend la valeur absolue
		float_MAE += tmp;
	}

	float_MAE = float_MAE / int_tailleTabTest;

	return float_MAE;
}

float distance(float float_X, float float_Y){
	float distance;
	// On calcule la distance entre float_x et float_y

	distance = pow(float_X - float_Y,2) ; //(x - y)²
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

// On trie les données par distance en utilisant le tri rapide
Habitation triRapide(Habitation *dataHabitation, int int_tailleData){
	// On trie les données
	triRapideRecursif(dataHabitation, 0, int_tailleData-1);
	return *dataHabitation;
}

void triRapideRecursif(Habitation *dataHabitation, int int_debut, int int_fin){
	if (int_debut < int_fin){
		int int_pivot = triRapidePartition(dataHabitation, int_debut, int_fin);
		triRapideRecursif(dataHabitation, int_debut, int_pivot-1);
		triRapideRecursif(dataHabitation, int_pivot+1, int_fin);
	}
}

int triRapidePartition(Habitation *dataHabitation, int int_debut, int int_fin){
	float float_pivot = dataHabitation[int_fin].float_distance_final;
	int int_i = int_debut-1;
	for (int int_j = int_debut; int_j < int_fin; int_j++){
		if (dataHabitation[int_j].float_distance_final <= float_pivot){
			int_i++;
			Habitation temp = dataHabitation[int_i];
			dataHabitation[int_i] = dataHabitation[int_j];
			dataHabitation[int_j] = temp;
		}
	}
	Habitation temp = dataHabitation[int_i+1];
	dataHabitation[int_i+1] = dataHabitation[int_fin];
	dataHabitation[int_fin] = temp;
	return int_i+1;
}


float calculPrix(Habitation *dataHabitation, int int_K){
	// Sommer les prix des k lignes du tableau dataHabitation et dataHabitationRNG
	// Renvoyer la moyenne qui sera le prix du candidat.

	float float_prix_dataHabitation = 0;
	float moyenne_prix;

	for (int i = 0;i<int_K;i++) {
		float_prix_dataHabitation += dataHabitation[i].float_prix;
	}

	moyenne_prix = float_prix_dataHabitation/int_K;

	return moyenne_prix;

}