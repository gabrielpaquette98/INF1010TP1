/**************************************************
* Nom: Produit.cpp
* Auteurs: 1894061 et 1899088
* Descripion: Implémentation de la classe Produit
*************************************************/
#include "Produit.h"
#include <iostream>

using namespace std;

/**
* Constructeur par paramètres (valeurs par défaut définies dans notre fichier Produit.h)
*
*/
Produit::Produit(string nom, int reference, double prix) 
	: nom_(nom)
	, reference_(reference)
	, prix_(prix)
{}

/**
* Accesseur du nom du produit
* \return nom_ {string} nom du produit
*/
string Produit::obtenirNom() const
{
	return nom_;
}
/**
* Accesseur du numéro de référence du produit
* \return reference_ {int} numéro de référence du produit
*/
int Produit::obtenirReference() const
{
	return reference_;
}
/**
* Accesseur du prix du produit
* \return prix_ {double} prix du produit
*/
double Produit::obtenirPrix() const
{
	return prix_;
}

/**
* Mutateur du nom du produit
* \param \in nom {string} nom à donner au produit
* \return void
*/
void Produit::modifierNom(string nom)
{
	nom_ = nom;
}
/**
* Mutateur de la référence du produit
* \param \in reference {int} numéro de référence à donner au produit
* \return void
*/
void Produit::modifierReference(int reference)
{
	reference_ = reference;
}
/**
* Mutateur de la référence du prix
* \param \in prix {double} prix à donner au produit
* \return void
*/
void Produit::modifierPrix(double prix)
{
	prix_ = prix;
}

/**
* Méthode permettant d'afficher un produit dans la console
* \param void
* \return void
*/
void Produit::afficher()
{
	cout << "Le produit numero: " << reference_ << " se nomme: " + nom_ + " et se vend au prix: " << prix_ << "$." << endl;
}