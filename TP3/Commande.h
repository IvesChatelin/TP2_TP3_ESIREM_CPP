#ifndef COMMANDE_H
#define COMMANDE_H

#include "Client.h"
#include "Produit.h"

enum Status {
  Livrée,
  Non_livrée,
};

class Commande {

private:
  int _numCom;
  std::string _client;
  std::vector<Produit> _produits;
  Status _status;

public:
  Commande(std::string idClient, std::vector<Produit> produits, Status status);
  int getNum();
  std::string getclient() const;
  std::vector<Produit> getproduits();
  Status getstatus() const;
  void updateStatus(const Status &status);
};
std::ostream &operator<<(std::ostream &os, Commande &commande);

#endif