using namespace std;
#include "element.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>


class Graph {

	public:
		vector<int> altitude;
		int tailleGraph;
		int nbCouche;

	Graph(int couche);
	~Graph();

	Graph* recherche(Graph* n, Element e);
	// void afficher( Noeud* n );
	vector<int> liaisonNoeud(int sommets);
	void afficher(Graph *n);
	void ChoixAltitude(int index, int altitudeValeur);
	void affichageAltitude();
	int Altitude(int index);
	Graph* rechercheChemin(int source, int destination);

};
