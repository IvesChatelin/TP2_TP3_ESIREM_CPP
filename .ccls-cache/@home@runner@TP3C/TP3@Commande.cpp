#include "Commande.h"
#include <fstream>
#include <iostream>
#include <vector>

Commande::Commande(std::string client, std::vector<Produit> produits,
                   Status status)
    : _client(client), _produits(produits), _status(status) {
  int id = rand() % 100;
  _numCom = id;
}

std::string Commande::getclient() const { return _client; }

int Commande::getNum() { return _numCom; }

std::vector<Produit> Commande::getproduits() { return _produits; }

Status Commande::getstatus() const { return _status; }

std::ostream &operator<<(std::ostream &os, Commande &commande) {
  std::string cl = commande.getclient();
  std::vector<Produit> produits = commande.getproduits();
  std::string stat;
  if (commande.getstatus() == 0) {
    stat = "Status : Livrée";
  } else {
    stat = "Status : Pas Livrée";
  }
  os << "************************\n" + cl << "\n"
     << stat << "\nListe de produit : " << std::endl;
  for (auto it = produits.begin(); it != produits.end(); ++it) {
    std::cout << (*it);
  }
  return os;
}

void Commande::updateStatus(const Status &status) { _status = status; }