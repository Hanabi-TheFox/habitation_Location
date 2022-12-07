//--------------------------------------------------
//---------- Propriété de Ethan et Renato ----------
//--------------------------------------------------

## Habitation_Location
Prédire le prix d’une habitation qu’on veut mettre en location dans la plateforme Airbnb

Auteurs
@Hanabi-TheFox
@RDNATOS
Contextualisation

Ce Projet à été réalisé par Ethan Pinto et Renato Nascimento Ardiles

Il fut donné par Madame ndeye arame DIAGO pour le Projet de programmation procedurale à rendre le 10 / 12 / 2022

Le but de ce projet est de trouver des prix prédit pour chaque logement
sur differents modeles avec 1,2 ou 3 categories et en faisant varier k.

K represente les k premiers logements pour calculer le prix prédit lorsqu'on
trie les tableaux contenant les logements.

En se fiant aux consignes de ce projet, notre équipe à decidée de diviser cette partie en 2.
Dans le fichier struct.h, la constante 'Bonus' fait éxecuter la premiere ou deuxieme partie du
programme. si 'Bonus' = 0, la premiere partie est executée. Si 'Bonus' = 1, deuxieme partie est executée.
Executer le projet
make : compile le programme

make run : compile et lance le programme

make clean : supprime les fichiers .o

make clean_all : supprime les fichiers .o et l'exectuable

make help : affiche ce message

## Consignes

Sujet 1 : Pour pouvoir bien louer son logement, le propriétaire a besoin de calculer un prix qui soit cohérent avec l’ensemble des prix des autres logements autour de lui. Dans cette perspective, on met en place dans ce sujet, le calcul des n-premiers voisins permettant de calculer un prix prédit d’un logement (qu’on appellera candidat X) par rapport à tous les autres logements dans la base de données. Cette métrique des n-premiers voisins demande de calculer la distance de similitude entre le logement candidat X et le les autres logements. Cette distance est donnée par :

$$ Distance = {\sqrt{\sum_{i=1}^n (Xi - Yi)²}} $$

Les étapes pour le calcul de cette distance sont demandées lors des questions suivantes:

(a)  Le calcul de cette distance entre le logement X et tous les logements contenus dans le fichier airbnb_donnees_propores.csv. 

(b) On passe à la randomisation du de ce tableau et ensuite on trie en appliquant l’algorithme Tri Rapide.

(c)  On prend k = 200 et on calcule le prix prédit pour un modèle ayant 3 catégories.

(d) Pour la suite, on prend 3 Modèles, chacun ayant 1 catégorie, 2 catégories et 3 catégories.

—-------------------------------------------------

## Sujet 1 Bonus: Maintenant, on applique le même algorithme, en calculant cette même distance, mais cette fois- ci pour tous les logements dans le fichier “airtbnbTest.csv”. Ensuite, on calcule le MAE pour chaque logement.

https://en.wikipedia.org/wiki/Mean_absolute_error

e) On charge le fichier “airbnbEntrainement.csv” et on stock dans un tableau appelée tabEntrainement. Il contient 80 % de la taille du fichier “airbnb_donnees_propres”.

f) On charge le fichier “airbnbTest.csv” et on stock dans le tableau appelée tabTest. Il contient 20 % de la taille du fichier  “airbnb_donnees_propres”.
g) On applique l'algorithme utilisé dans la partie précédente pour trouver le prix prédit pour chaque logement candidat stocké dans tabTest.

h) On calcule le MAE pour un modèle ayant 3 catégories et k = 200. 

i) On fait la même chose que précédemment avec 3 modèles ayant 1 catégorie, 2 catégories et 3 catégories. Ensuite, pour chaque modèle, on calcule le prix prédit avec k = 5, k = 10 et k= 15.

j) Pour chaque ‘k’ de chaque modèle, on compare les valeurs des MAE et on prend le plus petit. Le Modèle avec le ‘k’ correspondant avec le MAE le plus petit, a le meilleur k.

## Contenu

Le projet contient les fichiers suivants :

**bin**

L'ensemble des fichiers .o du projet

    fonction.o
    main.o

**data**

Le fichier data nécessaire à l'execution du projet

    airbnbEntrainement.csv
    airbnbTest.csv
    airbnb_donnees_propre.csv

**doc**

Le readme du projet ainsi que le pdf contenant les consignes

    Readme.md
    TP NOTÉ algoprocING1.pdf

**src**

L'ensemble des fichiers .h et .c du projet

    fonction.c
    fonction.h
    main.c
    struct.h

**makefile**

permettant l'execution et la compilation du projet

**habitation_Location**

