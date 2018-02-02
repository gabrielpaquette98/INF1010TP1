/**************************************************
* Nom: client.cpp
* Auteurs: 1894061 et 1899088
* Descripion: Implementation de la classe Panier
*************************************************/

#include "./client.h"

static const uint8_t CAPACITE_DEFAULT_PANIER = 4;

/**
 * Constructeur par parametres
 * 
 */
Client::Client(string  nom, string prenom, int identifiant, string codePostal, long date)
	:nom_(nom)
	, prenom_(prenom)
	, identifiant_(identifiant)
	, codePostal_(codePostal)
	, dateNaissance_(date)
	, monPanier_(nullptr)
{}

/**
 * Destructeur
 */
Client::~Client()
{
	if (monPanier_ != nullptr)
	{
		delete monPanier_;
		monPanier_ = nullptr;
	}
		
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
* Accesseur du prenom du client
* \return prenom_ {string} prenom du client
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
 * \param \in nom {string} nom a donner au client
 * \return void
 */
void Client::modifierNom(string nom)
{
	nom_ = nom;
}

/**
* Mutateur du prenom du client
* \param \in prenom {string} prenom a donner au client
* \return void
*/
void Client::modifierPrenom(string prenom)
{
	prenom_ = prenom;
}

/**
* Mutateur de l'identifiant du client
* \param \in identifiant {int} identifiant a donner au client
* \return void
*/
void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

/**
* Mutateur du code postal du client
* \param \in codePostal {string} code postal a donner au client
* \return void
*/
void Client::modifierCodePostal(string codePostal)
{
	codePostal_ = codePostal;
}

/**
* Mutateur de la date de naissance du client
* \param \in date {ling} date de naissance a donner au client
* \return void
*/
void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

/**
* Methode permettant a un client d'acheter un produit
* et de l'ajouter a son panier
* \param \in prod {Produit*} produit a acheter
* \return void
*/
void Client::acheter(Produit * prod)
{
	if (monPanier_ == nullptr)
		monPanier_ = new Panier(CAPACITE_DEFAULT_PANIER);
	monPanier_->ajouter(prod);
}

/**
* Methode permettant d'afficher le contenu du panier d'un client
* dans la console
* \param void
* \return void
*/
void Client::afficherPanier()
{
	if (monPanier_ == nullptr)
		cout << "Veuillez commencer a acheter des articles pour pouvoir initialiser le panier" << endl;
	else if (monPanier_->obtenirNombreContenu() == 0)
		cout << "Votre panier ne contient aucun article" << endl;
	else
		monPanier_->afficher();
}

/**
* Methode permettant de livrer le panier d'un client
* \param void
* \return void
*/
void Client::livrerPanier()
{
	monPanier_->livrer();
}