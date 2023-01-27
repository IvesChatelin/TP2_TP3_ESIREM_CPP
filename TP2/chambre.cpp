#include "chambre.h"
#include <assert.h>
#include <iostream>
#include <string>

Chambre::Chambre(int num, std::string type, double prix)
    : _num(num), _type(type), _prix(prix) {
  bool status = isValid(num, prix);
  assert(status && "Chambre non valid");
}

int Chambre::getNum() const { return _num; }

std::string Chambre::getType() const { return _type; }

double Chambre::getPrix() const { return _prix; }

void Chambre::updatePrix(const double &prix) { _prix = prix; }

bool Chambre::isValid(int num, double prix) {
  if (num <= 0 || prix <= 0)
    return false;
  return true;
}

std::ostream &operator<<(std::ostream &os, const Chambre &chambre) {
  os << "*****************Chambres*****************\n"
     << "Numéro de chambre : " << chambre.getNum() << "\n"
     << "Type de Chambre : " << chambre.getType() << "\n"
     << "Prix la Nuit : " << chambre.getPrix() << std::endl;
  return os;
}