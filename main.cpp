#include "graph.h"
#include "element.h"
#include <iostream>
#include <cmath>
#include<vector>

using namespace std;

int main() {
	int choixCouche;
	cout << "Nombre de couches ?" << endl;
	cin >> choixCouche;
	cout << endl;
	Graph* g = new Graph(choixCouche);
	int choix;

	do
    {
        cout << "  Menu Graphe\n";
        cout << "  ====================================\n";
        cout << "  1.  Changer l\'altitude d'un sommet\n";
        cout << "  2.  Changer le nombre de couches du graphe\n";
        cout << "  3.  Recherche du chemin le plus court\n";
        cout << "  4.  Afficher les altitudes\n";
        cout << "\n";
        cout << "  0.  Quitter\n";
        cout << "  ====================================\n";
        cout << "  Entrez votre choix: ";
        cin >> choix;
        cout << endl;

        switch (choix)
        {
            case 1: {
								int sommet;
								int altitude;
                cout << "Entrez le sommet dont vous voulez changer l\'altitude : ";
                cin >> sommet;
								cout << endl;
								cout << "Entrez sa nouvelle altitude : ";
								cin >> altitude;
								cout << endl;
								g->ChoixAltitude(sommet,altitude);
                break;
							}

            case 2:
								int couches;
								cout << "Cette option remet le tableau d\'altitude a zero"<< endl;
								cout << "Entrez le nombre de couches que vous souaitez : ";
								cin >> couches;
								cout << endl;
								g = new Graph(couches);
                break;

            case 3:
								int source;
								int dest;
								cout << "Entrez le sommet de depart : ";
								cin >> source;
								cout << endl;
								cout << "Entrez le sommet de destination : ";
								cin >> dest;
								cout << endl;
								g->rechercheChemin(source,dest);
                break;

            case 4:
                g->affichageAltitude();
                break;

						case 0:
								cout << "Au revoir\n";
								break;

            default: cout << choix << " n\'est pas un choix possible.\n";

                cout << endl;
        }

    }while (choix != 0 );




	/*
	g->rechercheChemin(1,4);
	g->liaisonNoeud(5);
	g->liaisonNoeud(2);
	g->liaisonNoeud(9);
	g->liaisonNoeud(7);
	g->liaisonNoeud(1);



	g->rechercheChemin(1,3);
	g->affichageAltitude();*/

	return 0;
}
