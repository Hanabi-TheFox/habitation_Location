//--------------------------------------------------
//---------- Propriété de Ethan et Renato ----------
//--------------------------------------------------

// Fichier dans lequel est définit la structure Habitation ainsi que des données numérique
// Importantes comme k ou data_Max_Value

#define k 50 // Nombre de logement à comparer au candidat. Max : 7918
#define data_Max_Value 7918 // A changer si le nombre de données du fichier data est différent.
// Définition de la structure "Habitation"
// Les variables sont tous en float car on ne peut pas utiliser 
// des entiers pour calculer la distance euclidienne.
typedef struct Habitation{
	float float_id;
	float float_nbr_personnes_acceuillables;
	float float_nbr_chambre;
	float float_nbr_salle_de_bain;
	float float_nbr_lit;
	float float_prix;
	float float_nuit_minimum;
	float float_nuit_maximum;
	float float_nombre_de_retour;
	float float_distance;
}Habitation;