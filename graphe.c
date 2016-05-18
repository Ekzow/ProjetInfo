#inculde "graphe.h"


void set_deg_nul(GRAPHE g)
{
	int i;
	
	for(i=0;i<(g.nX);i++)   //Pour tout les sommets
	{
		if (*(g.sommet+i)->deg)==0)   // Si leur degré est nul après construction
		{
			(*(g.sommet+i)->PremArc)=NULL;   //Réinitialisation de l'adresse
		}
	}
}

GRAPHE construire_graphe() 
{
	FILE* f;
	unsigned int nX; unsigned int nA; int i
	GRAPHE g;
	char ignore[1024];
	unsigned int num; double lat; double lon; char[256] lig; char[512] sta;
	SOMMET s;
	int N=0; unsigned int depa; unsigned int arri; double pds;
	ARC a;
	
	
	f=fopen("graphe1.csv","r+");
	fscanf (f, "%d %d", &nX, &nA);
	g=nouveau_graphe(nX,nA);   //Allocation mémoire initiale et création des variables
	
	fgets(ignore,sizeof(ignore),f);   //On ignore la ligne de texte inutile du .csv
	
	for(i=0,i<nX,i++)   //Boucle de remplissage du tableau des sommets
	{
		fscanf(f, "%d %lf %lf %s", &num, &lat, &lon, &lig)  //Indice, latitude, longitude, ligne
		s.ind=num;
		s.X=lat;
		s.Y=lon;
		s.ligne=nom;
		fgets(sta,512,f);  //Nom de la station
		s.nom=sta;
		*(g.sommet+i)=s;
	}
		
	fgets(ignore,sizeof(ignore),f);   //On ignore la ligne de texte inutile
	
	*(g.sommet)->PremSom=g.arcs  //Initialisation du lien sommet-arc
	
	for(i=0,i<nA,i++)   //Boucle de remplissage du graphe
	{
		fscanf(f,"%d %d %lf", &depa, &arri, &pds)
		if(dep==N)   //On gère l'affectation des adresse des sommets
		{
			a.dep=(g.sommet+depa);
			a->arr=(g.sommet+arri);
			a->pds=pds;
			*(g.arcs+i)=a
			*(g.sommet+depa)->deg+=1;
		}
		else
		{
			do
			{
				N+=1;   //Si il n'y a pas d'autres arcs qui partent du sommet, on passe au suivant dans le premier tableau(Rq: le while sert si le sommet suivant a un degré nul)
				*(g.sommet+N)->PremArc=g.arcs+i
			}
			while(N!=dep)  
			
			a.dep=(g.sommet+depa);  //Et on répete le processus du if.
			a->arr=(g.sommet+arri);
			a->pds=pds;
			*(g.arcs+i)=a
			*(g.sommet+depa)->deg+=1;
		
	}
set_deg_nul(g);   //On reset les adresses des degrés nul.

return g
}

void affiche_graphe(GRAPHE g)
{
	
}

	
	