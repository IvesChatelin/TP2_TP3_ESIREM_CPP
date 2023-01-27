#include "Produit.h"
#include "assert.h"
#include <fstream>
#include <string>
#include <vector>

Produit::Produit(std::string titre, std::string description, int quantite,
                 double prix)
    : _titre(titre), _description(description), _quantite(quantite),
      _prix(prix) {
  bool status = isValid(quantite, prix);
  assert(status && "Produit invalide !!!!");
}

std::string Produit::getTitre() const { return _titre; }

std::string Produit::getDescription() const { return _description; }

int Produit::getQuantite() const { return _quantite; }

double Produit::getPrix() const { return _prix; }

bool isValid(int quantite, double prix) {
  if (quantite <= 0 || prix <= 0)
    return false;
  return true;
}

void Produit::updateQuantite(const int &quantite) { _quantite = quantite; }

std::ostream &operator<<(std::ostream &os, Produit &produit) {
  os << "************************************\n"
     << "Nom du produit : " + produit.getTitre() + "\n"
     << "Description du produit : " + produit.getDescription() + "\n"
     << "Quantité du produit : " << produit.getQuantite() << "\n"
     << "Prix unitaire : " << produit.getPrix() << "$" << std::endl;
  return os;
}