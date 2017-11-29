#include "arbre.h"
#include "element.h"
#include <iostream>
using namespace std;


Noeud::Noeud(){

	droit = NULL;
	gauche = NULL;
	couleur = 'N';
	parent = NULL;
}

Noeud::Noeud(Element e){
	valeur = e;
	droit = nullptr;
	gauche = nullptr;
	couleur = 'N';
	parent = NULL;
}

Noeud::~Noeud(){

}

void Noeud::insererUnElement(Noeud*& n, Element e,Noeud*& parent){
	if(n == nullptr){
		n = new Noeud(e);
		n->couleur = 'R';
		n->parent = parent;
	}else if(e < n->valeur){
		insererUnElement(n->gauche,e,n);
	}else{
		insererUnElement(n->droit,e,n);
	}
}

void Noeud::inserer(Noeud*& n, Element e){
		insererUnElement(n,e,n);
		ArbreOK(n);

}

void Noeud::ArbreOK(Noeud*& n){
	if(n->parent == NULL){
		if(n->couleur != 'N'){n->couleur = 'N';}
	}else if(n->parent->couleur == 'N' && n->couleur != 'R'){
		if( n->parent->parent->droit->valeur != n->parent->valeur){
			n->parent->parent->droit->couleur = 'N';
		}else{
			n->parent->parent->gauche->couleur = 'N';
		}
	}else if(n->parent->couleur == 'R' && n->couleur == 'R'){
		n->couleur = 'N';
	}
	if(n->droit != NULL){
		ArbreOK(n->droit);
	}
	if(n->gauche != NULL){
		ArbreOK(n->gauche);
	}


}

Noeud* Noeud::recherche(Noeud *n, Element e){
	if(n->valeur == e){
		return n;
	}else if(e < n->valeur){

		return recherche(n->gauche,e);
	}else{
		return recherche(n->droit,e);

	}
return nullptr;
}

void Noeud::supprimer(Noeud *n, Element e){
	Noeud* n2 = recherche(n,e);
	Noeud* nRech;
	Noeud* nPere;
	cout << n2->valeur << endl;
	if(n2->gauche != nullptr){
		nRech = n2->gauche;
		while(nRech->droit != nullptr){
			nPere = nRech;
			nRech = nRech->droit;
		}
		nPere->droit = nullptr;
	}else{
		nRech = n2->droit;
		while(nRech->gauche != nullptr){
			nPere = nRech;
			nRech = nRech->gauche;
		}
		nPere->gauche = nullptr;
	}

	n2->valeur = nRech->valeur;

}


// void Noeud::afficher(Noeud* n)
// {
    // if (n != nullptr)
    // {
        // cout << n->valeur << endl;
        // if (n->gauche != nullptr)
            // afficher(n->gauche);
        // if (n->droit != nullptr)
            // afficher(n->droit);
    // }
// }

void Noeud::afficher(Noeud *pN, int profondeur){
	if (pN == NULL){
		return;
	}
	afficher(pN->droit, profondeur+1);
	for (int i=0; i<profondeur; i++){
		cout << "        ";
	}
	cout << "(" << pN -> valeur;
	cout << pN->couleur ;
	/*if(pN->parent != NULL){
		cout  << " parent : "<< pN->parent->valeur
	}*/
	cout << ") " << " "  << "\n";
	afficher(pN->gauche, profondeur+1);
	if (profondeur == 0){
		cout << endl;
	}

}
