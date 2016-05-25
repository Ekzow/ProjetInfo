#include "graphe.h"

LARC creer_LARC()
{
	LARC L;
	
	L=NULL;
	return L;
}

int est_vide(LARC L)
{
	return !L;
}

LARC ajout_tete(MaillonARC m, LARC L)
{
	m.suivant=L;
	L=&m;
	return L;
}

LARC supprimer_tete(LARC L)
{
	LARC p;
	
	p=L;
	L=p->suivant;
	free(p);
	return L;
}

ARC renvoie_tete(LARC L)
{
	return L->arc;
}

ARC pop_tete(LARC L)
{
	LARC p;
	ARC a;
	
	p=L;
	L=p->suivant;
	
	a=p->arc;
	free(p);
	return a;
}

ARC renvoi_arc(LARC L, int id)
{
	int i;
	LARC m=L;
	
	for (i=0;i<id;i++)
	{
		m=(m->suivant);
	}
	return m->arc;
}

void supprimer_arc(LARC L, int id)
{
	int i;
	LARC m=L;
	
	for (i=0;i<id;i++)
	{
		m=(m->suivant);
	}
	
}

void affiche_arc (ARC a)
{
	printf("Sommet de départ : %d\n", (a.dep));
	printf("Sommer d'arrivée : %d\n", (a.arr));
	printf("Poids de l'arc : %lf\n", a.pds);
}

void afficher_larc(LARC L)
{
	LARC m=L;
	int i=1;	
	if (!(est_vide(L)))
	{
		while (m->suivant!=NULL)
		{
			printf("Arc n°%d (indice %d)\n", i, i-1);
			affiche_arc(m->arc);
			m=m->suivant;
			i+=1;
		}
		printf("Arc n°%d (indice %d)\n", i, i-1);
		printf("Fin de la liste\n");		
	}
	if (est_vide(L))
	{
		printf("Fin de la liste\n");
	}
}

main()
{
	ARC a1, a2, a3, a4;
	LARC L;	
	
	a1.dep=0;
	a2.dep=1;
	a3.dep=2;
	a4.dep=3;
	
	a1.arr=1;
	a2.arr=2;
	a3.arr=3;
	a4.arr=4;
	
	a1.pds=1.0;
	a2.pds=2.0;
	a3.pds=3.0;
	a4.pds=4.0;

	L=creer_LARC();
	ajout_tete(a1,L);

	afficher_larc(L);

}
