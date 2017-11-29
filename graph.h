using namespace std;
#include "element.h"

class Noeud {

	public:
		Element valeur;
		Noeud* gauche;
		Noeud* droit;
		Noeud* parent;
		char couleur;

	Noeud();
	Noeud(Element e);
	~Noeud();

	void supprimer(Noeud* n, Element e);
	Noeud* recherche(Noeud* n, Element e);
	void inserer(Noeud*& n, Element e);
	void insererUnElement(Noeud*& n, Element e,Noeud*& parent);
	void ArbreOK(Noeud*& n);
	// void afficher( Noeud* n );
	void afficher(Noeud *pN, int profondeur = 0);


};
