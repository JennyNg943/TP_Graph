using namespace std;
#include "element.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>


class Graph {

	public:
		int altitude;
		int nbSommets;


	Graph();
	Graph(Element e);
	~Graph();

	Graph* recherche(Graph* n, Element e);
	// void afficher( Noeud* n );
	void liaisonNoeud(int sommets);
	void afficher(Graph *n);

};