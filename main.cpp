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

	vector<int> test;
	test = g->liaisonNoeud(2);
	for(vector<int>::iterator i = test.begin(); i != test.end();++i){
		cout << *i;
	}
	cout<< endl;
	/*g->liaisonNoeud(5);
	g->liaisonNoeud(2);
	g->liaisonNoeud(9);
	g->liaisonNoeud(7);
	g->liaisonNoeud(1);*/

	g->ChoixAltitude(1,5);
	g->ChoixAltitude(10,2);

	g->affichageAltitude();

	return 0;
}
