#include "LARC.h"

typedef struct SOMMET SOMMET;

struct SOMMET
{
	unsigned int ind; //valeur du sommet
	SOMMET* pere; //pere du sommet
	double X;	//Latitude du sommet
	double Y;  //Longitude du sommet
	char* ligne;   //Ligne sur laquelle est le sommet
	char* nom;   //Nom du sommet
	double pds;   //Poids du sommet
	LARC PremArc;  //Premier arc partant de ce sommet
	//unsigned int deg;   //Degré du sommet (0 par défault)
};

typedef struct 
{
	SOMMET* Graphe;
	unsigned int nX;   //Nombre de sommet
	unsigned int nA;   // Nombre d'arcs
}GRA;

typedef GRA* GRAPHE;

//FONCTION SUR LES GRAPHES
void afficher_sommet(SOMMET s);
GRAPHE nouveau_graphe();
GRAPHE construire_graphe(char* NomFichier, GRAPHE g);
void afficher_graphe(GRAPHE g);
