/**************************************************
* Nom: Rayon.cpp
* Auteurs: 1894061 et 1899088
* Descripion: Implémentation de la classe Rayon
*************************************************/
#include "Rayon.h"
#include <iostream>

using namespace std;

static const int CONSTANTE_CAPACITE = 5;

/**
* Constructeur par paramètres (valeurs par défaut définies dans notre fichier Rayon.h)
*
*/
Rayon::Rayon(string cat) 
	: categorie_(cat)
	, tousProduits_(nullptr)
	, capaciteProduits_(0)
	, nombreProduits_(0)
{}

/**
* Destructeur
*/
Rayon::~Rayon()
{
	delete[] tousProduits_;
	tousProduits_ = nullptr;
}

/**
* Accesseur du nom de cathégorie du rayon
* \return categorie_ {string} nom de catégorie du rayon
*/
string Rayon::obtenirCategorie() const
{
	return categorie_;
}
/**
* Accesseur du contenu du rayon
* \return tousProduits_ {Produit**} contenu du rayon
*/
Produit** Rayon::obtenirTousProduits()
{
	return tousProduits_;
}
/**
* Accesseur de la capacité du rayon
* \return capaciteProduits_ {int} capacité du rayon
*/
int Rayon::obtenirCapaciteProduits() const
{
	return capaciteProduits_;
}
/**
* Accesseur du nombre de produits dans le rayon
* \return nombreProduits_ {int} nombre de produits dans le rayon
*/
int Rayon::obtenirNombreProduits() const
{
	return nombreProduits_;
}

/**
* Mutateur du nom de catégorie du rayon
* \param \in cat {string} nom à donner a la catégorie du rayon
* \return void
*/
void Rayon::modifierCategorie(string cat)
{
	categorie_ = cat;
}

/**
* Méthode permettant d'ajouter un produit au rayon selon le nombre déjà contenu
* \param \in prod {Produit*} Pointeur du produit à ajouter
* \return void
*/
void Rayon::ajouterProduit(Produit* produit)
{
	if (tousProduits_ == nullptr)
		tousProduits_ = new Produit*[CONSTANTE_CAPACITE];
	else
		if (capaciteProduits_ == nombreProduits_)
		{
			Produit** nouveauRayon = new Produit*[capaciteProduits_ + CONSTANTE_CAPACITE];//on crée la nouvelle liste de produits
			for (int i = 0; i < nombreProduits_; i++)
				nouveauRayon[i] = tousProduits_[i];
			delete[] tousProduits_;
			tousProduits_ = nouveauRayon;
		}
	tousProduits_[nombreProduits_] = produit;
	nombreProduits_++;
}

/**
* Méthode permettant d'afficher un rayon dans la console
* \param void
* \return void
*/
void Rayon::afficher()
{
	cout << "--------------------Etat du rayon--------------------" << endl
		<< "| Nom de la categorie: " << categorie_ << endl
		<< "| Nombre d'articles: " << nombreProduits_ << endl
		<< "| Capacite du rayon: " << capaciteProduits_ << endl;
		
	cout << "Le rayon contient les produits suivants: " << endl;
	for (int i = 0; i < nombreProduits_; i++)
	{
		tousProduits_[i]->afficher();
	}
}