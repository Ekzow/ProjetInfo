#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct 
{
	unsigned int dep;  //Adresse du sommet de départ dans le tableau des sommets
	unsigned int arr;  //Adresse "    "    d'arrivée "     "    "     "     "
	double pds;  // Poids de l'arc
} ARC;

typedef struct MaillonLARC MaillonLARC;

typedef MaillonLARC* LARC;

struct MaillonLARC
{
	ARC arc;
	MaillonLARC* suivant;
};

//FONCTIONS SUR LES LISTES
LARC creer_LARC();
int est_vide(LARC L);
LARC ajout_tete(ARC a, LARC L);
LARC supprimer_tete(LARC L);
ARC renvoie_tete(LARC L);
ARC pop_tete(LARC* L);
ARC renvoi_arc(LARC L, int id);
int test_egalite(ARC a,ARC b);
LARC recherche_arc(LARC L, ARC a);
void supprimer_arc(LARC* L, ARC a);
int taille_larc(LARC L);
void supprimer_indice(LARC* L, int id);
LARC vide_larc(LARC L);
void afficher_arc (ARC a);
void afficher_larc(LARC L);
