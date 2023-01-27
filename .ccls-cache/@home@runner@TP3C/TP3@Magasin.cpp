#include "Magasin.h"
#include <fstream>
#include <vector>

Magasin::Magasin(std::vector<Produit> produits, std::vector<Client> clients,
                 std::vector<Commande> commandes)
    : _produits(produits), _clients(clients), _commandes(commandes){};

std::vector<Produit> Magasin::getproduits() { return _produits; }

std::vector<Client> Magasin::getclients() { return _clients; }

std::vector<Commande> Magasin::getcommande() { return _commandes; }

void Magasin::addProduit(Produit &produit) { _produits.push_back(produit); }

void Magasin::getAllProduit() {
  bool status = false;
  for (auto it = _produits.begin(); it != _produits.end(); ++it) {
    std::cout << (*it);
    status = true;
  }
  if (!status) {
    std::cout << "Aucun produit dans ce magasin !!" << std::endl;
  }
}

void Magasin::getProduitByName(std::string nom) {
  bool status = false;
  for (auto it = _produits.begin(); it != _produits.end(); ++it) {
    if (nom == (*it).getTitre()) {
      std::cout << (*it);
      status = true;
    }
  }
  if (!status) {
    std::cout << "Aucun Produit à ce nom dans ce magasin !!" << std::endl;
  }
}

void Magasin::updateQuantiteProduit(std::string nomProduit, int quantite) {
  bool status = false;
  for (auto it = _produits.begin(); it != _produits.end(); ++it) {
    if (nomProduit == (*it).getTitre()) {
      (*it).updateQuantite(quantite);
      std::cout << "Quantité du Produit modifier !!" << std::endl;
      status = true;
    }
  }
  if (!status) {
    std::cout << "Quantité du Produit non modifier !!" << std::endl;
  }
}

void addClientMagasin(Magasin &magasin, Client client) {
  magasin._clients.push_back(client);
  std::cout << "Client ajouté avec succes " << std::endl;
}

void getAllClientMagasin(Magasin &magasin) {
  bool status = false;
  for (auto it = magasin._clients.begin(); it != magasin._clients.end(); ++it) {
    std::cout << "Identifiant : " + (*it).getIdentifiant() + "\n"
              << "Nom : " + (*it).getnom() + "\n"
              << "Prenom : " + (*it).getprenom() << std::endl;
    status = true;
  }
  if (!status) {
    std::cout << "Aucun client dans ce magasin !! " << std::endl;
  }
  /* avec fichier
  std::ifstream file("clients.txt");
  std::string ligne;
  if (file) {
    while (getline(file, ligne)) {
      std::cout << ligne << std::endl;
    }
    file.close();
  } else {
    std::cout << "Erreur!!! dans l'ouverture du fichier clients " << std::endl;
  }*/
}

void getClient(Magasin &magasin, std::string nom_identifiant) {
  bool status = false;
  for (auto it = magasin._clients.begin(); it != magasin._clients.end(); ++it) {
    if (nom_identifiant == (*it).getnom() ||
        nom_identifiant == (*it).getprenom()) {
      std::cout << "Identifiant : " + (*it).getIdentifiant() + "\n"
                << "Nom : " + (*it).getnom() + "\n"
                << "Prenom : " + (*it).getprenom() << std::endl;
      status = true;
    }
  }
  if (!status) {
    std::cout << "Aucun client enregistré avec ce nom dans ce magasin !! "
              << std::endl;
  }
}

void addProduitPanierClient(Magasin &magasin, std::string nom_produit,
                            std::string idClient) {
  bool status = false;
  for (auto it = magasin._produits.begin(); it != magasin._produits.end();
       ++it) {
    if (nom_produit == (*it).getTitre()) {
      for (auto it2 = magasin._clients.begin(); it2 != magasin._clients.end();
           ++it2) {
        if (idClient == (*it2).getIdentifiant()) {
          (*it2).addProduitpanier(*it);
        }
      }
      status = true;
      std::cout << "Produit ajouté au panier du client !!" << std::endl;
    }
  }
  if (!status) {
    std::cout << "erreur : Ce Produit n'existe pas au panier du client !!"
              << std::endl;
  }
}

void deleteProduitPanierClient(Magasin &magasin, std::string nom_produit,
                               std::string idClient) {
  bool status = false;
  for (auto it = magasin._produits.begin(); it != magasin._produits.end();
       ++it) {
    if (nom_produit == (*it).getTitre()) {
      for (auto it = magasin._clients.begin(); it != magasin._clients.end();
           ++it) {
        if (idClient == (*it).getIdentifiant()) {
          std::vector<Produit> vector = (*it).getpanier();
          for (auto it2 = vector.begin(); it2 != vector.end();) {
            if (nom_produit == (*it2).getTitre()) {
              vector.erase(it2);
            } else {
              ++it;
            }
          }
        }
      }
      std::cout << "Produit supprimer dans le panier du client avec success !"
                << std::endl;
      status = true;
    }
  }
  if (!status) {
    std::cout << "erreur ! Ce client n'existe pas !" << std::endl;
  }
}

void updateQteProduitClient(Magasin &magasin, std::string nom_produit, int qte,
                            std::string idClient) {
  bool status = false;
  for (auto it = magasin._produits.begin(); it != magasin._produits.end();
       ++it) {
    if (nom_produit == (*it).getTitre()) {
      for (auto it = magasin._clients.begin(); it != magasin._clients.end();
           ++it) {
        if (idClient == (*it).getIdentifiant()) {
          std::vector<Produit> vector = (*it).getpanier();
          for (auto it2 = vector.begin(); it2 != vector.end(); ++it2) {
            if (nom_produit == (*it2).getTitre()) {
              (*it2).updateQuantite(qte);
            }
          }
        }
      }
      std::cout << "Qte du Produit modifier avec success !" << std::endl;
      status = true;
    }
  }
  if (!status) {
    std::cout << "erreur ! Ce proquit n'existe pas le pannier !" << std::endl;
  }
}

void validerCommande(Magasin &magasin, Commande commande) {
  magasin._commandes.push_back(commande);
  std::cout << "Commande validée avec success !!" << std::endl;
}

void updateStatusCommande(Magasin &magasin, int Numcommande, Status status) {
  bool isupdate = false;
  for (auto it = magasin._commandes.begin(); it != magasin._commandes.end();
       it++) {
    if (Numcommande == (*it).getNum()) {
      (*it).updateStatus(status);
      isupdate = true;
      std::cout << "Le statu de la commande modifié ! " << std::endl;
    }
  }
  if (!isupdate) {
    std::cout << "Erreur!! le Statu de la commande modifié ! " << std::endl;
  }
}

void getAllCommande(Magasin &magasin) {
  bool status = false;
  for (auto it = magasin._commandes.begin(); it != magasin._commandes.end();
       ++it) {
    std::cout << (*it);
    status = true;
  }
  if (!status) {
    std::cout << "Aucune commande !!" << std::endl;
  }
}

void getAllCommande(Magasin &magasin, std::string idclient) {
  bool status = false;
  for (auto it = magasin._commandes.begin(); it != magasin._commandes.end();
       ++it) {
    if (idclient == (*it).getclient()) {
      std::cout << (*it);
    }
    status = true;
  }
  if (!status) {
    std::cout << "Aucune commande !!" << std::endl;
  }
}