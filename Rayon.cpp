#include "Rayon.h"
#include <iostream>

using namespace std;

static const int CONSTANTE_CAPACITE = 5;
// Constructeurs par defaut et par parametres
Rayon::Rayon()
{
	categorie_ = "inconnu";
	tousProduits_ = nullptr;
	capaciteProduits_ = 0;
	nombreProduits_ = 0;
}
Rayon::Rayon(string cat)
{
	categorie_ = cat;
	tousProduits_ = nullptr;
	capaciteProduits_ = 0;
	nombreProduits_ = 0;
}

//méthodes d'accès
string Rayon::obtenirCategorie() const
{
	return categorie_;
}
Produit** Rayon::obtenirTousProduits()
{
	return tousProduits_;// renvoyer la liste? sans encapsulation ou copie??
}
int Rayon::obtenirCapaciteProduits() const
{
	return capaciteProduits_;
}
int Rayon::obtenirNombreProduits() const
{
	return nombreProduits_;
}

//méthodes de modification
void Rayon::modifierCategorie(string cat)
{
	categorie_ = cat;
}

// autres methodes
void Rayon::ajouterProduit(Produit* produit)
{
	if (tousProduits_ == nullptr) //si le tableau est null, on l'initialise. il y aura de la place pour le premier produit
	{
		//initialiser le tableau de produits à 5; mettre la capacité à 5;
		tousProduits_ = new Produit*[CONSTANTE_CAPACITE];
	}
	else //le tableau est non null. y a-t-il de la place restante pour notre nouveau produit?
	{
		if (capaciteProduits_ == nombreProduits_) //si on a atteint la capacité (pu de place), on veut augmenter la capacité du tableau de 5
		{
			Produit** nouveauRayon = new Produit*[capaciteProduits_ + CONSTANTE_CAPACITE];//on crée la nouvelle liste de produits
			for (int i = 0; i < nombreProduits_; i++)
			{
				nouveauRayon[i] = tousProduits_[i];//on copie tout les pointeurs vers le nouveau tableau
			}
			delete[] tousProduits_; //on delete l'ancien tableau
			tousProduits_ = nouveauRayon;// on copie l'adresse du nouveau rayon sur le tableau du rayon
		}
		//else on a de la place dans le rayon
	}

	//on s'est assuré que notre tableau a de la place. Nous pouvons ajouter le produit au rayon.
	tousProduits_[nombreProduits_] = produit;
	nombreProduits_++; //on a ajouté un produit
}
void Rayon::afficher()
{
	cout << "Le Rayon de categorie: " + categorie_ + " a une capacite de: " << capaciteProduits_ << " et contient " << nombreProduits_ << " produits suivants:" << endl;
	for (int i = 0; i < nombreProduits_; i++)
	{
		tousProduits_[i]->afficher();
	}
}