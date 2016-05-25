#include "LARC.h"

LARC creer_LARC()
{
	MaillonLARC* p;
	
	p=NULL;
	return p;
}

int est_vide(LARC L)
{
	return !L;
}

LARC ajout_tete(MaillonLARC m, LARC L)
{
	m->suivant=L
	L=&m;
	return L;
}

LARC supprimer_tete(LARC L)
{
	MaillonLARC* p;
	
	p=L;
	L=p->suivant;
	free(p);
	return L;
}

ARC renvoie_tete(LARC L)
{
	return (*L)->arc;
}

ARC pop_tete(LARC L)
{
	MaillonLARC* p;
	ARC a;
	
	p=L;
	L=L->suivant;
	
	a=p->arc;
	free(p);
	return a;
}

ARC renvoi_arc(LARC L, int id)
{
	int i;
	MaillonLARC* m=L;
	
	for (i=0,i<id,i++)
	{
		m=(m->suivant)
	}
	return m->arc;
}

void supprimer_arc(LARC L, int id)
{
	int i;
	MaillonLARC* m=L;
	
	for (i=0,i<id,i++)
	{
		m=(m->suivant);
	}
	
}

void afficher_larc(LARC L)
{
	MaillonLARC* m=L;
	while (m->suivant!=NULL)
	{
		affiche_arc(m->arc);
	}
}

void affiche_arc (ARC a)
{
	printf("Sommet de départ : %d\n", (a->dep)->ind);
	printf("Sommer d'arrivée : %d\n", (a->arr)->ind);
	printf("Poids de l'arc : %lf\n", a->pds);
}

main()
{
	SOMMET tab[5];
	ARC a1, a2, a3, a4;
	
	tab[0]->ind=0;
	tab[1]->ind=1;
	tab[2]->ind=2;
	tab[3]->ind=3;
	tab[4]->ind=4;
	
	a1->dep=tab;
	a2->dep=tab+1;
	a3->dep=tab+2;
	a3->dep=tab+3;
	
	a1->arr=tab+1;
	a2->arr=tab+2;
	a3->arr=tab+3;
	a3->arr=tab+4;
	
	a1->pds=1.;
	a2->pds=2.;
	a3->pds=3.;
	a3->pds=4.;
	
	affiche_arc(a1);
	affiche_arc(a2);
	affiche_arc(a3);
	affiche_arc(a4);
}