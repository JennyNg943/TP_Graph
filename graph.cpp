#include "graph.h"
#include "element.h"
#include <iostream>
#include <cmath>
#include "math.h"

using namespace std;


Graph::Graph(int couche)
{
	nbCouche = couche;
	tailleGraph = pow(2,nbCouche)-1;
	altitude.resize(tailleGraph,0);
	cout << altitude.size() <<endl;
}

vector<int> Graph::liaisonNoeud(int sommets){
	if(sommets < pow(2,this->nbCouche)){
		vector<int> voisins;
		int couche = log2(sommets) + 1;
		int predecesseur =  fmod(pow(2,couche) + (sommets-1), pow(2,couche));
		int successeur = pow(2,couche) + fmod(((sommets-pow(2,couche))+1), pow(2,couche));
		cout << "Le sommet " << sommets << " est lié à ";
		int i = 0;
		cout << "	";
		if (sommets/2 != 0){
			cout << sommets/2;
			voisins.push_back(sommets/2);
			i++;
		}
		cout << "	";
		if(2*sommets != 0){
			cout << 2*sommets;
			voisins.push_back(sommets*2);
			i++;
		}
		cout << "	";
		if(2*sommets+1 != 0){
			cout << 2*sommets+1 ;
			voisins.push_back(2*sommets+1);
			i++;
		}
		cout << "	";
		if (predecesseur != 0 && predecesseur != 2*sommets+1 && predecesseur != sommets/2 &&  predecesseur != 2*sommets){
			cout << predecesseur ;
			voisins.push_back(predecesseur);
			i++;
		}
		cout << "	";
		if(successeur != 0 && successeur != 2*sommets && successeur != 2*sommets+1 && successeur != sommets/2){
			cout << successeur;
			voisins.push_back(successeur);
			i++;
		}
		cout << " 		Possède donc " << i << " voisins."<< endl;
		return voisins;
	}else{
		cout << "Ce sommet n'est pas disponible dans un graphe à " << this->nbCouche << " couche(s)." << endl;

	}


}

Graph::~Graph(){

}

void Graph::ChoixAltitude(int index, int altitudeValeur){
	if(index < tailleGraph){
		altitude[index] = altitudeValeur;
		cout << "Altitude changée !" << index << " " << altitudeValeur << endl;
	}else{
		cout << "Ce sommet n'existe pas !" << endl;
	}

}

int Graph::Altitude(int index){
	return altitude[index];
}

void Graph::affichageAltitude(){
	cout << altitude.size() << endl;
	for(int i = 1; i <= altitude.size() ;i++){
		cout << "Sommet : " << i<< " - Altitude : " << altitude[i] << endl;
	}
}

Graph* Graph::rechercheChemin(int source, int destination){
	vector<int> voisins;
	voisins = liaisonNoeud(source);
	for(vector<int>::iterator i = voisins.begin(); i != voisins.end();++i){//ça affiche que les voisions du noeud source
		cout << *i;
	}

}

void Graph::afficher(Graph *n){


}
