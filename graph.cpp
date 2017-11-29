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
	int predecesseur = fmod(pow(2,couche+1) - (pow(2,couche+1)-(sommets-1)), pow(2,couche));
	int successeur = fmod(pow(2,couche) - ((sommets-pow(2,couche))+1), pow(2,couche));
	cout << "Le sommet " << sommets << " est lié à "<< sommets/2 << "," << 2*sommets <<","<<2*sommets+1<< ",";
	cout << predecesseur << ","<<successeur << endl;
}

Graph::~Graph(){

}

Graph* Graph::recherche(Graph *n, Element e){

}

void Graph::afficher(Graph *n){


}
