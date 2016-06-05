#include "LARC.h"

LARC creer_LARC() //création d'une Liste vide
{
	LARC L;
	
	L=NULL;
	return L;
}

int est_vide(LARC L) //Test si la liste est vide
{
	return !L;
}

LARC ajout_tete(ARC a, LARC L) //ajouter un élément en tete
{
	LARC m=calloc(1,sizeof(*m));	//allocation mémoire

	m->arc=a; //remplissage
	m->suivant=L; //lien
	return m;
}

LARC supprimer_tete(LARC L) //supprime le premier élément
{
	LARC p;
	
	p=L;
	L=p->suivant; //Nouvelle tete de liste
	free(p); //Libération mémoire
	return L;
}

ARC renvoie_tete(LARC L) //récupération valeur de tete
{
	return L->arc;
}

ARC pop_tete(LARC* L) //récuperation et suppression valeur de tete
{
	ARC a;
	
	a=(*L)->arc;
	*L=supprimer_tete(*L);

	return a;
}

ARC renvoi_arc(LARC L, int id) //Récupération de l'arc a l'indice id
{
	int i;
	LARC m=L;
	ARC a;
	
	for (i=0;i<id;i++) //Parcours itératif
	{
		m=(m->suivant);
	}
	a=m->arc;
	return a;
}

int test_egalite(ARC a,ARC b) //Test de l'agalité de deux arcs
{
	if(a.dep==b.dep && a.arr==b.arr)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


LARC recherche_arc(LARC L, ARC a) //recherche d'un arc dans une liste, renvoie de son adresse
{
	LARC m=L;
		
	if (!(est_vide(L))) //si la liste n'est pas vide
	{
		while ((m->suivant)!=NULL) //Parcours
		{
			if (test_egalite(m->arc,a)){return m;} //test
			m=m->suivant;
			
		}
		if (test_egalite(m->arc,a)){return m;}	//test final (le do-while faisait planter, je sais que c'est pas super élégant mais bon ...	
	}
	return NULL; //Si rien a été trouvé adresse vide
}


void supprimer_arc(LARC* L, ARC a) //suppression d'un arc donné 
{
	LARC m=*L,s;
	ARC b;
	
	if (!(est_vide(*L))) //si la liste n'est pas vide
	{
		if(test_egalite(m->arc,a)) //si on le trouve en tete
		{
			*L=supprimer_tete(*L);
		}		
		else {while ((m->suivant)->suivant!=NULL) //tant que l'élément suivant de l'élément suivant n'est pas la fin de liste (utile car on a besoin de conserver l'élément précédent celui qu'on veux supprimer
		{
			if (test_egalite((m->suivant)->arc,a)) //Si on le trouve
			{
				s=m->suivant;
				m->suivant=s->suivant; //On refait le lien
				free(s); //on libère
			}
			else
			{
			m=m->suivant; //sinon on avance
			}
		}
		if (test_egalite((m->suivant)->arc,a)) //test final
		{
				s=m->suivant;
				m->suivant=s->suivant;
				free(s);
		}
	}}	
}


int taille_larc(LARC L) //Calcul de la taille d'une liste
{
	LARC m=L;
	int i=0;	
	if (!(est_vide(L)))
	{
		while ((m->suivant)!=NULL)
		{
			m=m->suivant;
			i+=1;
		}
		i+=1;
	}
	return i;
}


void supprimer_indice(LARC* L, int id) //Meme principe que la précédente mais par indice
{
	int i;
	LARC m=*L,s;
	
	if(id>(taille_larc(*L)-1))
	{
		printf("ERREUR : INDICE TROP GRAND");
	}	
	else{if (id==0)
	{
		*L=supprimer_tete(*L);
	}
	else
	{
		for (i=0;i<id-1;i++)
		{
			m=(m->suivant);
		}
		s=m->suivant;
		m->suivant=s->suivant;
		free(s);
	}}
}

LARC vide_larc(LARC L) //Libération de la mémoire
{
	if (!(est_vide(L)))
	{
		while ((L->suivant)!=NULL)
		{
			L=supprimer_tete(L);
		}
		L=supprimer_tete(L);
	}
	return L;
}

void afficher_arc (ARC a) //Affichage d'un arc
{
	printf("Sommet de départ : %d\n", (a.dep));
	printf("Sommer d'arrivée : %d\n", (a.arr));
	printf("Poids de l'arc : %lf\n", a.pds);
}

void afficher_larc(LARC L) //Affichage d'une liste d'arc
{
	LARC m=L;
	int i=1;	
	if (!(est_vide(L)))
	{
		while ((m->suivant)!=NULL)
		{
			printf("Arc n°%d (indice %d)\n", i, i-1);
			afficher_arc(m->arc);
			m=m->suivant;
			i+=1;
		}
		printf("Arc n°%d (indice %d)\n", i, i-1);
		afficher_arc(m->arc);
		printf("Fin de la liste\n");		
	}
	if (est_vide(L))
	{
		printf("Fin de la liste\n");
	}
}

main()
{
	//TESTS POUR TOUTE LES FONCTIONS

	/*ARC a1, a2, a3, a4, a;
	LARC L,T;	
	int i,j;
	
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
	//printf ("L est vide ? %d", est_vide(L));
	
	L=ajout_tete(a1,L);
	L=ajout_tete(a2,L);
	L=ajout_tete(a3,L);
	L=ajout_tete(a4,L);
	
	//L=supprimer_tete(L);
	
	//afficher_arc(pop_tete(&L));

	//afficher_arc(L->arc);	
	
	//a=(renvoi_arc(L,2));
	//afficher_arc(a);
	
	//i=test_egalite(a1,a2);
	//j=test_egalite(a1,a1);
	//printf("a1 et a2 égaux ? %d\n", i);
	//printf("a1 et a1 égaux ? %d\n", j);
	
	//printf("SWAG");
	//T=recherche_arc(L,a1);
	//printf("FISH");

	//afficher_larc(T);

	
	//supprimer_arc(&L,a1);

	//supprimer_indice(&L,4);

	//printf("taille liste L : %d", taille_larc(L));

	//L=vide_larc(L);
	
	printf("\n\n\n\n");
	afficher_larc(L);*/

}
