#include "Bellman.h"

GRAPHE set_pds(GRAPHE g) //Sert a initialiser les poids
{
	int i;
	
	for (i=0;i<(g->nX);i++) //Parcours itératf des sommets
	{
		g->Graphe[i].pds=1000000000;
	}
	return g;
}

LARC Bellman(GRAPHE g, int dep, int arr, LARC chemin) //Fonction qui réalise l'algorithme non optimisé
{
	int i,j,k;
	ARC a;
	ARC b;
	b.pds=0.0;
	
	g=set_pds(g);
	g->Graphe[dep].pds=0; //initialisation des poids
	
	for(i=0;i<(g->nX);i++)//Boucle de l'algo
	{
		for(j=0;j<(g->nX);i++) //Pour tout les sommets
		{
			for (k=0;k<taille_larc(g->Graphe[j].PremArc);k++) //Pour chaque arc du sommet
			{
				a=renvoi_arc(g->Graphe[j].PremArc,k); //On sort l'arc au bon indice
				if((g->Graphe[a.dep].pds)+a.pds<(g->Graphe[a.arr].pds)) //Comparaison des poids
				{
					(g->Graphe[a.arr].pere)=&(g->Graphe[a.dep]); //Mise a jour du pere pour récupération du chemin
					(g->Graphe[a.arr].pds)=(g->Graphe[a.dep].pds)+a.pds; //Mise a jour du poids
				}
			}
		}
	}
	b.arr=arr; //Initialisation de la boucle des retours
	b.dep=(g->Graphe[b.arr].pere->ind);
	chemin=vide_larc(chemin);
	chemin=ajout_tete(b,chemin);
	while(b.dep!=dep) //Remplissage de la liste représentant le chemin
	{
		b.arr=b.dep;
		b.dep=(g->Graphe[b.arr].pere->ind);
		chemin=ajout_tete(b,chemin);
	}
	return chemin;
}

main()
{
	SOMMET s0, s1, s2, s3, s4, s5, s6, s7;
	ARC a01, a02, a03, a12, a14, a15, a23, a25, a45, a47, a65, a75;
	GRAPHE g;
	SOMMET tab[8];
	LARC chemin=creer_LARC();
	
	//Comme mon graphe marche pas, j'en fait un a la main ... Mais bellman marche pas non plus :'('	
	
	s0.ind=0;
	s1.ind=1;
	s2.ind=2;
	s3.ind=3;
	s4.ind=4;
	s5.ind=5;
	s6.ind=6;
	s7.ind=7;

	s0.ligne="LigneUnknown";
	s1.ligne="LigneUnknown";
	s2.ligne="LigneUnknown";
	s3.ligne="LigneUnknown";
	s4.ligne="LigneUnknown";
	s5.ligne="LigneUnknown";
	s6.ligne="LigneUnknown";
	s7.ligne="LigneUnknown";

	s0.nom="Aaa";
	s1.nom="Bbb";
	s2.nom="Ccc";
	s3.nom="Ddd";
	s4.nom="Eee";
	s5.nom="Fff";
	s6.nom="Ggg";
	s7.nom="Hhh";

	tab[0]=s0;
	tab[1]=s1;
	tab[2]=s2;
	tab[3]=s3;
	tab[4]=s4;
	tab[5]=s5;
	tab[6]=s6;
	tab[7]=s7;

	a01.dep=0;
	a02.dep=0;
	a03.dep=0;
	a12.dep=1;
	a14.dep=1;
	a15.dep=1;
	a23.dep=2;
	a25.dep=2;
	a45.dep=4;
	a47.dep=4;
	a65.dep=6;
	a75.dep=7;

	a01.arr=1;
	a02.arr=2;
	a03.arr=3;
	a12.arr=2;
	a14.arr=4;
	a15.arr=5;
	a23.arr=3;
	a25.arr=5;
	a45.arr=5;
	a47.arr=7;
	a65.arr=5;
	a75.arr=5;

	a01.pds=1698.13615485329456;
	a02.pds=2370.00799361148484;
	a03.pds=1047.62064402491569;
	a12.pds=1819.41076773129066;
	a14.pds=978.27968352398284;
	a15.pds=548.19610961142587;
	a23.pds=1678.66130075815408;
	a25.pds=2134.18470992812581;
	a45.pds=468.64873550138151;
	a47.pds=621.33775881193424;
	a65.pds=1498.82352940060559;
	a75.pds=913.62065377500778;

	tab[0].PremArc=creer_LARC();
	tab[0].PremArc=creer_LARC();
	tab[0].PremArc=creer_LARC();
	tab[1].PremArc=creer_LARC();
	tab[1].PremArc=creer_LARC();
	tab[1].PremArc=creer_LARC();
	tab[2].PremArc=creer_LARC();
	tab[2].PremArc=creer_LARC();
	tab[4].PremArc=creer_LARC();
	tab[4].PremArc=creer_LARC();
	tab[6].PremArc=creer_LARC();
	tab[7].PremArc=creer_LARC();

	tab[0].PremArc=ajout_tete(a01,tab[0].PremArc);
	tab[0].PremArc=ajout_tete(a02,tab[0].PremArc);
	tab[0].PremArc=ajout_tete(a03,tab[0].PremArc);
	tab[1].PremArc=ajout_tete(a12,tab[1].PremArc);
	tab[1].PremArc=ajout_tete(a14,tab[1].PremArc);
	tab[1].PremArc=ajout_tete(a15,tab[1].PremArc);
	tab[2].PremArc=ajout_tete(a23,tab[2].PremArc);
	tab[2].PremArc=ajout_tete(a25,tab[2].PremArc);
	tab[4].PremArc=ajout_tete(a45,tab[4].PremArc);
	tab[4].PremArc=ajout_tete(a47,tab[4].PremArc);
	tab[6].PremArc=ajout_tete(a65,tab[6].PremArc);
	tab[7].PremArc=ajout_tete(a75,tab[7].PremArc);

	chemin=Bellman(g,0,5,chemin);
	afficher_larc(chemin);
}
