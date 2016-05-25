#include "stdio.h"
#include "stdlist.h"


typedef struct 
{
	SOMMET* dep;  //Adresse du sommet de départ dans le tableau des sommets
	SOMMET* arr;  //Adresse "    "    d'arrivée "     "    "     "     "
	double pds;  // Poids de l'arc
} ARC;

typedef struct 
{
	unsigned int ind; //valeur du sommet
	unsigned double X;	//Latitude du sommet
	unsigned double Y;  //Longitude du sommet
	char ligne;   //Ligne sur laquelle est le sommet
	char nom;   //Nom du sommet
	double pds;   //Poids du sommet
	LARC* PremArc;  //Premier arc partant de ce sommet
	unsigned int deg=0;   //Degré du sommet (0 par défault)
} SOMMET;

typedef struct 
{
	SOMMET* sommet;
	ARC* arcs;
	unsigned int nX;   //Nombre de sommet
	unsigned int nA;   // Nombre d'arcs
} *GRAPHE;

//graphe nouveau_graphe(unsigned int nX,unsigned int nA)

//void set_deg_nul(GRAPHE g)

//GRAPHE construire_graphe() 
