#include "graph.h"
#include "element.h"
#include <iostream>
#include <cmath>
#include "math.h"

using namespace std;


Graph::Graph(){
	nbSommets = NULL;
}

Graph::Graph(int nbSo){
	nbSommets = nbSo;
}

void Graph::liaisonNoeud(int sommets){
	int couche = log2(sommets) + 1;
	int predecesseur =  fmod(pow(2,couche) + (sommets-1), pow(2,couche));
	int successeur = pow(2,couche) + fmod(((sommets-pow(2,couche))+1), pow(2,couche));
	cout << "Le sommet " << sommets << " est lié à ";
	if (sommets/2 != 0){
		cout << sommets/2 << " ";
	}
	if(2*sommets != 0){
		cout << 2*sommets <<" ";
	}
	if(2*sommets+1 != 0){
		cout << 2*sommets+1 << " ";
	}
	if (predecesseur != 0){
		cout << predecesseur << " ";
	}
	if(successeur != 0){
		cout << successeur;
	}

	cout << endl;

}

Graph::~Graph(){

}

Graph* Graph::recherche(Graph *n, Element e){

}

void Graph::afficher(Graph *n){


}
