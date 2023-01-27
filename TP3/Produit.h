#ifndef PRODUIT_H
#define PRODUIT_H

#include "iostream"
#include <string>

class Produit {

private:
  std::string _titre;
  std::string _description;
  int _quantite;
  double _prix;

public:
  Produit(std::string titre, std::string description, int quantite,
          double prix);
  std::string getTitre() const;
  std::string getDescription() const;
  int getQuantite() const;
  double getPrix() const;
  void updateQuantite(const int &quantite);
};
bool isValid(int quantite, double prix);
std::ostream &operator<<(std::ostream &os, Produit &produit);
#endif