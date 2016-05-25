#include "stdio.h"
#include "stdlib.h"


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


typedef struct 
{
	unsigned int ind; //valeur du sommet
	double X;	//Latitude du sommet
	double Y;  //Longitude du sommet
	char ligne;   //Ligne sur laquelle est le sommet
	char nom;   //Nom du sommet
	double pds;   //Poids du sommet
	LARC PremArc;  //Premier arc partant de ce sommet
	unsigned int deg;   //Degré du sommet (0 par défault)
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
