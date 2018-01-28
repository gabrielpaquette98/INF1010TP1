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
	delete[] contenuPanier_;
}

/**
* Accesseur du contenu du panier
* \return contenuPanier_ {Produit**} contenu du panier
*/
Produit** Panier::obtenirContenuPanier() const
{
    return contenuPanier_;
}

/**
* Accesseur du nombre d'items dans le panier
* \return nombreContenu_ {int} nombre d'éléments du panier
*/
int Panier::obtenirNombreContenu() const
{
    return nombreContenu_;
}

/**
* Accesseur du montant total à payer
* \return totalAPayer_ {double} total à payer du panier
*/
double Panier::obtenirTotalApayer() const
{
    return totalAPayer_;
}

/**
* Méthode permettant d'ajouter un produit au panier
* \param \in prod {Produit*} Pointeur du produit à ajouter
* \return void
*/
void Panier::ajouter(Produit* prod)
{
	contenuPanier_[nombreContenu_] = prod;
	nombreContenu_++;
	totalAPayer_ += prod->obtenirPrix();
	if (nombreContenu_ == capaciteContenu_)
	{
		capaciteContenu_ *= 2;
		for (int i = nombreContenu_; i < capaciteContenu_; i++)
			contenuPanier_[i] = new Produit;
	}
}

/**
* Méthode permettant de livrer le panier
* \param void
* \return void
*/
void Panier::livrer()
{
	for (int i = 0; i < capaciteContenu_; i++)
	{
		delete contenuPanier_[i];
	}
	nombreContenu_ = 0;
	totalAPayer_ = 0.0;
}

/**
* Méthode permettant d'afficher l'état du panier dans la console
* \param void
* \return void
*/
void Panier::afficher()
{
	cout << "--------------------Etat du panier--------------------" << endl
		<< "| Nombre d'articles: " << nombreContenu_ << endl
		<< "| Capacite du panier: " << capaciteContenu_ << endl
		<< "| Total a payer: " << totalAPayer_ << endl;
	
}