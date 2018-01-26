/**************************************************
* Titre: Travail pratique #1 - Main.cpp
* Date: 20 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA
**************************************************/

#include "Produit.h"
#include "Rayon.h"
#include "client.h"
#include "panier.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//C'est à vous de voir si vous devez allouer dynamiquement ou non les élèments

	//1-  Creez 15 objets du classe produit
    
    	const int NOMBRE_OBJETS_A_CREER = 15;
	
	vector<Produit*> listeDeProduits;

	for (size_t i = 0; i < NOMBRE_OBJETS_A_CREER; i++)
	{
		Produit* produitAjoute = new Produit("produit" + to_string(i+1), i + 1, 10.00);
		listeDeProduits.push_back(produitAjoute);
	}
    
	//2-  Modifiez le nom, la référence, le prix de  troisieme objet Produit créé
    //   afficher les attributs de cet objet Produit
 
	
	//3-  Creez un objet du classe rayon à l'aide du constructeur par défaut
   
	//4-  Modifiez la catégorie  du rayon
   
    // 5- Ajouter 6 produits de  voret chaoix dans le rayon créé
    

    // 6- afficher le contenu du rayon
   
  
	//7-  Creez un objet de classe client à l'aide du constructeur
   

	//8-  afficher l'etat des attributs du client
   

	//9-   Le client achete 9 produits
   

	//10- Afficher le contenu du panier du client

     //11- livrer le panier du client
   
    
	//12- afficher le contenu du panier du client
    
	//13-  terminer le programme correctement
    
    return 0;
}
