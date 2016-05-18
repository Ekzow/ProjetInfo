typedef struct 
{
	SOMMET* dep  //Adresse du sommet de départ dans le tableau des sommets
	SOMMET* arr  //Adresse "    "    d'arrivée "     "    "     "     "
	double pds   // Poids de l'arc
} ARC

typedef struct 
{
	unsigned int val //valeur du sommet
	unsigned double X	//Latitude du sommet
	unsigned double Y  //Longitude du sommet
	char ligne   //Ligne sur laquelle est le sommet
	char nom   //Nom du sommet
	double pds   //Poids du sommet
	unsigned int deg=0   //Degré du sommet (0 par défault)
} SOMMET

typedef struct 
{
	unsigned int nX   //Nombre de sommets
	SOMMET * S   //Tableau des sommets
	unsigned int nA   // Nombre d'arcs
	ARC	**nC   //Graphe
} *GRAPHE

graphe nouveau_graphe(unsigned int nX,unsigned int nA)
{
	GRAPHE g;
	ARC **p;
	g->nX=nX;
	g->nA=nA;
	g->nC=calloc(nX,sizeof(*p));   //Première partie de notre allocation dynamique
	g->S=calloc(nX,sizeof(SOMMET));
	return g;
}

void set_deg_nul(GRAPHE g)
{
	int i;
	
	for(i=0;i<(g->nX);i++)   //Pour tout les sommets
	{
		if ((g->S[i])->deg)==0)   // Si leur degré est nul après construction
		{
			(g->nC[i])=NULL;   //Réinitialisation de l'adresse
		}
	}
}

void construire_graphe(GRAPHE p) 
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
		fscanf(f, "%d %lf %lf %s", &num, &lat, &lon, &lig)
		s->val=num;
		s->X=lat;
		s->Y=lon;
		s->ligne=nom;
		fgets(sta,512,f);
		s->nom=sta;
		g->S[i]=s;
	}
		
	fgets(ignore,sizeof(ignore),f);   //On ignore la ligne de texte inutile
	*g->nC=calloc(nA,sizeof(ARC));   //Deuxième partie de l'allocation dynamique
	
	for(i=0,i<nA,i++)   //Boucle de remplissage du graphe
	{
		fscanf(f,"%d %d %lf", &dep, &arr, &pds)
		if(dep==N)   //On gère l'affectation dynamique
		{
			a->dep=g->S+depa;
			a->arr=g->S+arri;
			a->pds=pds;
			*(g->nC)[i]=a;
			(g->S+dépa)->deg+=1;
		}
		else
		{
			do
			{
				N+=1;   //Si il n'y a pas d'autres arcs qui partent du sommet, on passe au suivant dans le premier tableau(Rq: le while sert si le sommet suivant a un degré nul)
				(g->nC)[N]=&(*(g->nC)[i]);
			}
			while(N!=dep)
			a->dep=g->S+depa;   //Et on répete le processus du if.
			a->arr=g->S+arri;
			a->pds=pds;
			*(g->nC)[i]=a;
			(g->S+dépa)->deg+=1;
		}
		
	}
set_deg_nul(g);   //On reset les adresses des degrés nul.
}

void affiche_graphe(GRAPHE g)
{
	
}

	
	