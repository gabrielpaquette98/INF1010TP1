
//  panier.cpp
//  Created by Martine Bellaiche on 18-01-22.
//  Copyright © 2018 Martine Bellaiche. All rights reserved.
//

#include <string>
#include "Produit.h"

#ifndef PANIER_H
#define PANIER_H
class Panier
{
public:
    Panier (int capacite);
	~Panier();
    // methodes d'accès
    Produit **  obtenirContenuPanier() const;
    int obtenirNombreContenu() const;
    double obtenirTotalApayer() const;
    
    // méthodes de modification
    
    // autres méthodes
    void ajouter ( Produit * prod);
    void livrer();
    void afficher();

private:
    
    Produit ** contenuPanier_;
    int capaciteContenu_;
    int  nombreContenu_;
    double totalAPayer_;
};

#endif

