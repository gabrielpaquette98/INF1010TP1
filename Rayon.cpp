/**************************************************
* Nom: Rayon.cpp
* Auteurs: 1894061 et 1899088
* Date: 2 fevrier 2018
* Descripion: Impl�mentation de la classe Rayon
*************************************************/
#include "Rayon.h"
#include <iostream>

using namespace std;

static const int CONSTANTE_CAPACITE = 5;

/**
* Constructeur par param�tres (valeurs par d�faut d�finies dans notre fichier Rayon.h)
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
	if (tousProduits_ != nullptr)
	{
		delete[] tousProduits_;
		tousProduits_ = nullptr;
	}
}

/**
* Accesseur du nom de cath�gorie du rayon
* \return categorie_ {string} nom de cat�gorie du rayon
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
* Accesseur de la capacit� du rayon
* \return capaciteProduits_ {int} capacit� du rayon
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
* Mutateur du nom de cat�gorie du rayon
* \param \in cat {string} nom � donner a la cat�gorie du rayon
* \return void
*/
void Rayon::modifierCategorie(string cat)
{
	categorie_ = cat;
}

/**
* M�thode permettant d'ajouter un produit au rayon selon le nombre d�j� contenu
* \param \in prod {Produit*} Pointeur du produit � ajouter
* \return void
*/
void Rayon::ajouterProduit(Produit* produit)
{
	if (tousProduits_ == nullptr)
	{
		capaciteProduits_ = CONSTANTE_CAPACITE;
		tousProduits_ = new Produit*[capaciteProduits_];
	}	
	else
		if (capaciteProduits_ == nombreProduits_)
		{
			capaciteProduits_ += CONSTANTE_CAPACITE;
			Produit** nouveauRayon = new Produit*[capaciteProduits_];//on cr�e la nouvelle liste de produits
			for (int i = 0; i < nombreProduits_; i++)
				nouveauRayon[i] = tousProduits_[i];
			delete[] tousProduits_;
			tousProduits_ = nouveauRayon;
		}
	tousProduits_[nombreProduits_] = produit;
	nombreProduits_++;
}

/**
* M�thode permettant d'afficher un rayon dans la console
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