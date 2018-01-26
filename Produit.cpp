#include "Produit.h"
#include <iostream>

using namespace std;

// Constructeurs par defaut et par parametres

Produit::Produit(string nom, int reference, double prix) 
	: nom_(nom)
	, reference_(reference)
	, prix_(prix)
{
}

//méthodes d'accès
string Produit::obtenirNom() const
{
	return nom_;
}
int Produit::obtenirReference() const
{
	return reference_;
}
double Produit::obtenirPrix() const
{
	return prix_;
}

// Methodes de modification
void Produit::modifierNom(string nom)
{
	nom_ = nom;
}
void Produit::modifierReference(int reference)
{
	reference_ = reference;
}
void Produit::modifierPrix(double prix)
{
	prix_ = prix;
}

//méthode d'affichage
void Produit::afficher()
{
	cout << "Le produit numero: " << reference_ << " se nomme: " + nom_ + " et se vend au prix: " << prix_ << "$." << endl;
}