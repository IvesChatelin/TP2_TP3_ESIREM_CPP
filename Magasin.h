#ifndef MAGASIN_H
#define MAGASIN_H

#include "Client.h"
#include "Commande.h"
#include "Produit.h"
#include <vector>

class Magasin {

private:
  std::vector<Produit> _produits;
  std::vector<Client> _clients;
  std::vector<Commande> _commandes;

public:
  Magasin(std::vector<Produit> produits, std::vector<Client> clients,
          std::vector<Commande> commandes);
  std::vector<Produit> getproduits();
  std::vector<Client> getclients();
  std::vector<Commande> getcommande();
  void addProduit(Produit &produit);
  void getAllProduit();
  void getProduitByName(std::string nom);
  void updateQuantiteProduit(std::string nomProduit, int quantite);
  friend void addClientMagasin(Magasin &magasin, Client client);
  friend void getAllClientMagasin(Magasin &magasin);
  friend void getClient(Magasin &magasin, std::string nom_identifiant);
  friend void addProduitPanierClient(Magasin &magasin, std::string nom_produit,
                                     std::string idClient);
  friend void deleteProduitPanierClient(Magasin &magasin,
                                        std::string nom_produit,
                                        std::string idClient);
  friend void updateQteProduitClient(Magasin &magasin, std::string nom_produit,
                                     int qte, std::string idClient);
  friend void validerCommande(Magasin &magasin, Commande commande);
  friend void updateStatusCommande(Magasin &magasin, int Numcommande,
                                   Status status);
  friend void getAllCommande(Magasin &magasin);
  friend void getAllCommande(Magasin &magasin, std::string idclient);
};

#endif