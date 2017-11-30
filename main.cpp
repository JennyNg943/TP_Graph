#include "graph.h"
#include "element.h"
#include <iostream>
#include<vector>

using namespace std;

int main() {

	Graph* g = new Graph(15);
	g->liaisonNoeud(5);
	g->liaisonNoeud(2);
	g->liaisonNoeud(9);
	g->liaisonNoeud(7);
	g->liaisonNoeud(1);
	/*vector<Noeud> noeuds;

	Noeud* n = new Noeud(1,0);
	Noeud* n2 = new Noeud(2,1);
	Noeud* n3 = new Noeud(3,1);
	Noeud* n4 = new Noeud(4,2);
	Noeud* n5 = new Noeud(5,2);
	Noeud* n6 = new Noeud(6,2);
	Noeud* n7 = new Noeud(7,2);
	Noeud* n8 = new Noeud(8,3);
	Noeud* n9 = new Noeud(9,3);
	Noeud* n10 = new Noeud(10,3);
	Noeud* n11 = new Noeud(11,3);
	Noeud* n12 = new Noeud(12,3);
	Noeud* n13 = new Noeud(13,3);
	Noeud* n14 = new Noeud(14,3);
	Noeud* n15 = new Noeud(15,3);

	noeuds.push_back(n);
	noeuds.push_back(n2);
	noeuds.push_back(n3);
	noeuds.push_back(n4);
	noeuds.push_back(n5);
	noeuds.push_back(n6);
	noeuds.push_back(n7);
	noeuds.push_back(n8);
	noeuds.push_back(n9);
	noeuds.push_back(n10);
	noeuds.push_back(n11);
	noeuds.push_back(n12);
	noeuds.push_back(n13);
	noeuds.push_back(n14);
	noeuds.push_back(n15);

	n->lierNoeud(noeuds);*/

	return 0;
}
