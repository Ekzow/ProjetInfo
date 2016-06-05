#include "graphe.h"

void afficher_sommet(SOMMET s) //Affiche les noms et ligne d'un sommet
{
	printf("Station : %s\n", s.nom);
	printf("Ligne : %s\n", s.ligne);
}

GRAPHE nouveau_graphe() //Création et initialisation d'un graphe
{
	GRAPHE g;
	g->Graphe=NULL;
	g->nX=0;
	g->nA=0;
	return g;
}

GRAPHE construire_graphe(char* NomFichier, GRAPHE g)  //Remplissage du graphe
{
	FILE* f;
	unsigned int nX; unsigned int nA; int i;
	char ignore[1024];
	unsigned int num; double lat; double lon; char lig[256]; char sta[512];
	SOMMET s;
	unsigned int depa; unsigned int arri; double pds;
	ARC a;
	
	
	f=fopen("graphe1.csv","r"); //A remplacer par nomfichier, je testais ici.
	fscanf (f, "%d %d", &nX, &nA);
	g=nouveau_graphe();
	SOMMET st[nX];	//création d'un tableau de nX sommet, le calloc me faisait de la merde
	
	g->nX=nX;
	printf("%d", nX);
	g->nA=nA;
	printf("%d", nA);
	g->Graphe=st; //initialisation

	fgets(ignore,sizeof(ignore),f);   //On ignore la ligne de texte inutile du .csv
	
	for(i=0;i<nX;i++)   //Boucle de remplissage du tableau des sommets
	{
		fscanf(f, "%d %lf %lf", &num, &lat, &lon);  //Indice, latitude, longitude
		fgets(lig,256,f); //nom de la ligne
		s.ind=num;
		s.X=lat;
		s.Y=lon;
		s.ligne=lig;
		fgets(sta,512,f);  //Nom de la station
		s.nom=sta;
		g->Graphe[i]=s;
	}
	fgets(ignore,sizeof(ignore),f);   //On ignore la ligne de texte inutile
	
	for(i=0;i<nA;i++)   //Boucle de remplissage du graphe
	{
		fscanf(f,"%d %d %lf", &depa, &arri, &pds); //Départ, arrivée, poids
		a.dep=depa;
		a.arr=arri;
		a.pds=pds;
		g->Graphe[depa].PremArc=ajout_tete(a,g->Graphe[depa].PremArc); //Ajout de l'ar a la liste du bon sommet
	}
	return g;
}

void afficher_graphe(GRAPHE g) //Petite fonction d'affichage, a optimiser selon la taille du fichier .csv
{
	int i;
	for (i=0;i<(g->nX);i++)
	{
		afficher_sommet(g->Graphe[i]);
		afficher_larc(g->Graphe[i].PremArc);
	}
}
