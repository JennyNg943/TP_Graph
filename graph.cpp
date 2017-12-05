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
	//cout << altitude.size() <<endl;
}

vector<int> Graph::liaisonNoeud(int sommets){
	if(sommets < pow(2,this->nbCouche)){
		vector<int> voisins;
		int couche = log2(sommets) + 1;
		int predecesseur =  fmod(pow(2,couche) + (sommets-1), pow(2,couche));
		int successeur = pow(2,couche) + fmod(((sommets-pow(2,couche))+1), pow(2,couche));
		int i = 0;
		if (sommets/2 != 0){
			voisins.push_back(sommets/2);
			i++;
		}
		if(2*sommets != 0){
			voisins.push_back(sommets*2);
			i++;
		}
		if(2*sommets+1 != 0){
			voisins.push_back(2*sommets+1);
			i++;
		}
		if (predecesseur != 0 && predecesseur != 2*sommets+1 && predecesseur != sommets/2 &&  predecesseur != 2*sommets){
			voisins.push_back(predecesseur);
			i++;
		}
		if(successeur != 0 && successeur != 2*sommets && successeur != 2*sommets+1 && successeur != sommets/2){
			voisins.push_back(successeur);
			i++;
		}
		return voisins;
	}else{
		cout << "Ce sommet n'est pas disponible dans un graphe à " << this->nbCouche << " couche(s)." << endl;
	}


}

int Graph::nombreVoisins(int sommet){
	vector<int> liaison;
	liaison = liaisonNoeud(sommet);
	return liaison.size();
}

Graph::~Graph(){

}

void Graph::ChoixAltitude(int index, int altitudeValeur){
	if(index <= tailleGraph){
		altitude[index] = altitudeValeur;
		cout << "Altitude changée ! Index : " << index << " - Altitude : " << altitudeValeur << endl;
	}else{
		cout << "Ce sommet n'existe pas !" << endl;
	}

}

int Graph::Altitude(int index){
	return altitude[index];
}

void Graph::affichageAltitude(){
	//cout << altitude.size() << endl;
	for(int i = 1; i <= altitude.size() ;i++){
		cout << "Sommet : " << i<< " - Altitude : " << altitude[i] << endl;
	}
}

Graph* Graph::rechercheChemin(int source, int destination){
	if(destination <= altitude.size() && destination > 0 && source <= altitude.size() && source > 0){
		vector<int> voisins;
		int altitudeCheminPlusCourt = 0,tmp;
		vector<int> cheminPlusCourt;
		vector<int> voisinControle;
		int predecesseur = 0;
		vector<char> chemin(altitude.size(),'B');

		int suivant = source;
		chemin[suivant] = 'G';

		while(suivant != destination){
			cheminPlusCourt.push_back(suivant);
			voisins = liaisonNoeud(suivant);

			for(vector<int>::iterator i = voisins.begin(); i != voisins.end();++i){
				if(chemin[*i] != 'N'){
					chemin[*i] = 'G';
				}
			}
			chemin[suivant] = 'N';

			int altitudePlusPetite = 0;
			for(int j = 0; j <= chemin.size(); j++){
				if(chemin[j] == 'G'){
					chemin[j] = 'B';
					if(altitudePlusPetite == 0){
						altitudePlusPetite = j;
					}else if(j == destination){
						altitudePlusPetite = j;
					}else if(altitude[altitudePlusPetite] > altitude[j]){
						altitudePlusPetite = j;
					}
					if(predecesseur != 0 && predecesseur != source){
						voisins = liaisonNoeud(predecesseur);
						for(vector<int>::iterator i = voisins.begin(); i != voisins.end();++i){
							if(j == *i){
								int tmpAltitude = altitude[predecesseur] + altitude[j];
								if(tmpAltitude > altitude[j]){
									cheminPlusCourt.pop_back();
									altitudeCheminPlusCourt -= altitude[predecesseur];
								}
								altitudePlusPetite = j;
							}
						}
					}
				}

				}
				predecesseur = suivant;
				suivant = altitudePlusPetite;
				altitudeCheminPlusCourt += altitude[suivant];
			}

			cout << "Le chemin le plus court trouvé est : " ;

			for(vector<int>::iterator i = cheminPlusCourt.begin(); i != cheminPlusCourt.end();++i){
				if(*i == source){
					cout << *i << "(0) -> ";
				}else{
					cout << *i << "(" << altitude[*i] << ") -> ";
				}
			}
			cout << destination << "(" << altitude[destination] << ") "<< endl;
			cout << "D'altitude totale : " << altitudeCheminPlusCourt << endl;
		}else{
			cout << "Votre source ou votre destination ne sont pas compris dans un graphe à " << nbCouche << " couche(s)." << endl;
		}
}



void Graph::afficher(){
	int puissance = 2;
	for(int i=1;i<=tailleGraph;i++){
		if(i>=puissance){
			cout << endl;
			puissance =puissance*2;
		}
		cout << i << "(" << Altitude(i) << ")";
	}
}
