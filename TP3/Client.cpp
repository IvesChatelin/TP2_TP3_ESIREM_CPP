
#include "Client.h"
#include "Produit.h"
#include <vector>

Client::Client(std::string identifiant, std::string nom, std::string prenom,
               std::vector<Produit> panier)
    : _identifiant(identifiant), _nom(nom), _prenom(prenom), _panier(panier){};

std::string Client::getnom() const { return _nom; }

std::string Client::getIdentifiant() const { return _identifiant; }

std::string Client::getprenom() const { return _prenom; }

std::vector<Produit> Client::getpanier() { return _panier; }

void Client::addProduitpanier(Produit &produit) { _panier.push_back(produit); }

void Client::videPanier() { _panier.clear(); }

void Client::modifierquantite(Produit &produit, int quantite) {
  bool status = false;
  for (auto it = _panier.begin(); it != _panier.end(); ++it) {
    if (produit.getTitre() == (*it).getTitre() &&
        produit.getDescription() == (*it).getDescription()) {
      (*it).updateQuantite(quantite);
      std::cout << "Qte du produit modifiée avec success !!" << std::endl;
      status = true;
    }
  }
  if (!status) {
    std::cout << "erreur !! Ce produit n'existe pas !!" << std::endl;
  }
}

void Client::supprimerProduit(Produit &produit) {
  bool status = false;
  for (auto it = _panier.begin(); it != _panier.end();) {
    if (produit.getTitre() == (*it).getTitre() &&
        produit.getDescription() == (*it).getDescription()) {
      _panier.erase(it);
      std::cout << "Produit supprimé avec success !!" << std::endl;
      status = true;
    } else {
      ++it;
    }
  }
  if (!status) {
    std::cout << "erreur !! Ce produit n'existe pas !!" << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, Client &Cl) {
  std::vector<Produit> vector = Cl.getpanier();
  std::string display =
      "*************************\nIdentifiant : " + Cl.getIdentifiant() +
      "\nnom du client : " + Cl.getnom() + "\n" +
      "prenom du client : " + Cl.getprenom() + "\n" + "articles du panier : ";
  os << display << std::endl;
  for (auto it = vector.begin(); it != vector.end(); ++it) {
    std::cout << (*it);
  }
  return os;
}
