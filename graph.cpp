#include "graph.h"
#include "element.h"
#include <iostream>
#include <cmath>
#include "math.h"

using namespace std;


Graph::Graph(int couche){
	nbCouche = couche;
}

void Graph::liaisonNoeud(int sommets){
	int couche = log2(sommets) + 1;
	int predecesseur =  fmod(pow(2,couche) + (sommets-1), pow(2,couche));
	int successeur = pow(2,couche) + fmod(((sommets-pow(2,couche))+1), pow(2,couche));
	cout << "Le sommet " << sommets << " est lié à ";
	int i = 0;
	if (sommets/2 != 0){
		cout << sommets/2 << " ";
		i++;
	}
	if(2*sommets != 0 ){
		cout << 2*sommets <<" ";
		i++;
	}
	if(2*sommets+1 != 0){
		cout << 2*sommets+1 << " ";
		i++;
	}
	if (predecesseur != 0){
		cout << predecesseur << " ";
		i++;
	}
	if(successeur != 0 && successeur != 2*sommets){
		cout << successeur;
		i++;
	}

	cout << " 		Possède donc " << i << " voisins."<< endl;

}

Graph::~Graph(){

}

Graph* Graph::recherche(Graph *n, Element e){

}

void Graph::afficher(Graph *n){


}

void GrapheCirculaire(int nbCouche){

}
