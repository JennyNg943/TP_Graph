#include "graph.h"
#include "element.h"
#include <iostream>
#include <cmath>
#include<vector>

using namespace std;

int main() {
	int choixCouche;
	cout << "Nombre de couche ?" << endl;
	cin >> choixCouche;
	cout << endl;

	Graph* g = new Graph(choixCouche);
	g->ChoixAltitude(1,5);
	g->ChoixAltitude(2,3);
	g->ChoixAltitude(3,5);
	g->ChoixAltitude(4,6);
	g->ChoixAltitude(5,7);
	g->ChoixAltitude(10,2);

	g->rechercheChemin(1,5);
	/*g->liaisonNoeud(5);
	g->liaisonNoeud(2);
	g->liaisonNoeud(9);
	g->liaisonNoeud(7);
	g->liaisonNoeud(1);*/



	g->affichageAltitude();

	return 0;
}
