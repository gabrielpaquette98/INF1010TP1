/**************************************************
* Nom: client.cpp
* Auteurs: 1894061 et 1899088
* Descripion: Implémentation de la classe Panier
*************************************************/

#include "./client.h"


/**
 * Constructeur par paramètres
 * 
 */
Client::Client(string  nom, string prenom, int identifiant, string codePostal, long date)
	:nom_(nom)
	, prenom_(prenom)
	, identifiant_(identifiant)
	, codePostal_(codePostal)
	, dateNaissance_(date)
{}

/**
 * Destructeur
 */
Client::~Client()
{
	for (int i = 0; i < monPanier_->obtenirNombreContenu; i++)
		delete monPanier_->obtenirContenuPanier[i];
	delete[] monPanier_->obtenirContenuPanier;
	delete monPanier_;
}

/**
 * Accesseur du nom du client
 * \return nom_ {string} nom du client
 */
string Client::obtenirNom() const
{
	return nom_;
}

/**
* Accesseur du prénom du client
* \return prenom_ {string} prénom du client
*/
string Client::obtenirPrenom() const
{
	return prenom_;
}

/**
* Accesseur de l'identifiant du client
* \return identifiant_ {int} identifiant du client
*/
int Client::obtenirIdentifiant() const
{
	return identifiant_;
}

/**
* Accesseur du code postal du client
* \return codePostal_ {string} code postal du client
*/
string Client::obtenirCodePostal() const
{
	return codePostal_;
}

/**
* Accesseur de la date de naissance du client
* \return codePostal_ {long} date de naissance du client
*/
long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}


/**
 * Mutateur du nom du client
 * \param \in nom {string} nom à donner au client
 * \return void
 */
void Client::modifierNom(string nom)
{
	nom_ = nom;
}

/**
* Mutateur du prénom du client
* \param \in prenom {string} prénom à donner au client
* \return void
*/
void Client::modifierPrenom(string prenom)
{
	prenom_ = prenom;
}

/**
* Mutateur de l'identifiant du client
* \param \in identifiant {int} identifiant à donner au client
* \return void
*/
void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

/**
* Mutateur du code postal du client
* \param \in codePostal {string} code postal à donner au client
* \return void
*/
void Client::modifierCodePostal(string codePostal)
{
	codePostal_ = codePostal;
}

/**
* Mutateur de la date de naissance du client
* \param \in date {ling} date de naissance à donner au client
* \return void
*/
void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

/**
* Méthode permettant à un client d'acheter un produit
* et de l'ajouter à son panier
* \param \in prod {Produit*} produit à acheter
* \return void
*/
void Client::acheter(Produit * prod)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier(4);
	monPanier_->ajouter(prod);
}

/**
* Méthode permettant d'afficher le contenu du panier d'un client
* \param void
* \return void
*/
void Client::afficherPanier()
{
	if (monPanier_ != nullptr || monPanier_->obtenirNombreContenu() >= 0)
	{
		cout << "Votre Panier:" << endl;
		for (int i = 0; i < monPanier_->obtenirNombreContenu(); i++)
			cout << "Item #" << i + 1 << ": " << monPanier_->obtenirContenuPanier[i] << endl;
	}
	else
		cout << "Votre panier est vide" << endl;
}

/**
* Méthode permettant de livrer le panier d'un client
* \param void
* \return void
*/
void Client::livrerPanier()
{
	monPanier_->livrer();
	delete monPanier_;
}