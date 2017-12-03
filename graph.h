using namespace std;
#include "element.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>


class Graph {

	public:
		int altitude[1];
		int tailleGraph;
		int nbCouche;

	Graph(int couche);
	~Graph();

	Graph* recherche(Graph* n, Element e);
	// void afficher( Noeud* n );
	void liaisonNoeud(int sommets);
	void afficher(Graph *n);
	void ChoixAltitude(int index, int altitudeValeur);
	void affichageAltitude();

};
