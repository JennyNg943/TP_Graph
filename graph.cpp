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
	cout << sizeof(altitude);
}

void Graph::liaisonNoeud(int sommets){
	if(sommets < pow(2,this->nbCouche)){
		int couche = log2(sommets) + 1;
		int predecesseur =  fmod(pow(2,couche) + (sommets-1), pow(2,couche));
		int successeur = pow(2,couche) + fmod(((sommets-pow(2,couche))+1), pow(2,couche));
		cout << "Le sommet " << sommets << " est lié à ";
		int i = 0;
		cout << "	";
		if (sommets/2 != 0){
			cout << sommets/2;
			i++;
		}
		cout << "	";
		if(2*sommets != 0){
			cout << 2*sommets;
			i++;
		}
		cout << "	";
		if(2*sommets+1 != 0){
			cout << 2*sommets+1 ;
			i++;
		}
		cout << "	";
		if (predecesseur != 0 && predecesseur != 2*sommets+1 && predecesseur != sommets/2 &&  predecesseur != 2*sommets){
			cout << predecesseur ;
			i++;
		}
		cout << "	";
		if(successeur != 0 && successeur != 2*sommets && successeur != 2*sommets+1 && successeur != sommets/2){
			cout << successeur;
			i++;
		}

		cout << " 		Possède donc " << i << " voisins."<< endl;
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

void Graph::affichageAltitude(){
	cout << sizeof(altitude) << endl;
	for(int i = 0; i < sizeof(altitude) ;i++){
		cout << "Sommet : " << i << " - Altitude : " << altitude[i] << endl;
	}
}

//Graph* Graph::rechercheChemin(int source, int destination, int altitude){

//}

void Graph::afficher(Graph *n){


}
