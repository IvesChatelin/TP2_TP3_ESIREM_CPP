#ifndef CLIENT_H
#define CLIENT_H

#include "Produit.h"
#include <string>
#include <vector>

class Client {

private:
  std::string _identifiant;
  std::string _nom;
  std::string _prenom;
  std::vector<Produit> _panier;

public:
  Client(std::string identifiant, std::string nom, std::string prenom,
         std::vector<Produit> panier);
  std::string getIdentifiant() const;
  std::string getnom() const;
  std::string getprenom() const;
  std::vector<Produit> getpanier();
  void addProduitpanier(Produit &produit);
  void videPanier();
  void modifierquantite(Produit &produit, int quantite);
  void supprimerProduit(Produit &produit);
};
std::ostream &operator<<(std::ostream &os, Client &Cl);

#endif