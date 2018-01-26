/**************************************************
 * Nom: panier.cpp
 * Auteurs: 1894061 et 1899088
 * Descripion: Implémentation de la classe Panier
 *************************************************/

#include "./panier.h"

/**
* Constructeur par paramètres
* 
*/
Panier::Panier(int capacite)
	:contenuPanier_(new Produit*[capacite])
	, capaciteContenu_(capacite)
	, nombreContenu_(0)
	, totalAPayer_(0.0)
{}

/**
* Destructeur
*/
Panier::~Panier()
{
	for (int i = 0; i < capaciteContenu_; i++)
		delete contenuPanier_[i];
	delete[] contenuPanier_;
}

Produit** Panier::obtenirContenuPanier() const
{
    return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
    return nombreContenu_;
}

double Panier::obtenirTotalApayer() const
{
    return totalAPayer_;
}

void Panier::ajouter(Produit* prod)
{
	contenuPanier_[nombreContenu_] = prod;
	totalAPayer_ += prod->obtenirPrix();
	if (nombreContenu_ == capaciteContenu_)
	{
		capaciteContenu_ *= 2;
		for (int i = nombreContenu_; i < capaciteContenu_; i++)
			contenuPanier_[i] = new Produit;
	}
}

void Panier::livrer()
{
	for (int i = 0; i < capaciteContenu_; i++)
	{
		delete contenuPanier_[i];
	}
	nombreContenu_ = 0;
	totalAPayer_ = 0.0;
}

void Panier::afficher()
{
	cout << "--------------------Etat du panier--------------------" << endl
		<< "| Nombre d'articles: " << nombreContenu_ << endl
		<< "| Capacite du panier: " << capaciteContenu_ << endl
		<< "| Total a payer: " << totalAPayer_ << endl;
	
}