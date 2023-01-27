#include "hotel.h"
#include <iostream>
#include <string>
#include <vector>

Hotel::Hotel(std::string identifiant, std::string nom, std::string ville,
             std::vector<Chambre> chambre)
    : _identifiant(identifiant), _nom(nom), _ville(ville), _chambre(chambre) {}

std::string Hotel::getidentifiant() const { return _identifiant; }

std::string Hotel::getnom() const { return _nom; }

std::string Hotel::getville() const { return _ville; }

std::vector<Chambre> Hotel::getChambre() { return _chambre; }

void Hotel::addroom(Chambre chambre) { _chambre.push_back(chambre); }

std::ostream &operator<<(std::ostream &os, Hotel &hotel) {
  std::string detail =
      "**************Hotel*************\nIdentifiant de l'hotel : " +
      hotel.getidentifiant() + "\nNom de l'Hotel : " + hotel.getnom() +
      "\nVille : " + hotel.getville() + "\nNombre de Chambre : ";
  return os << detail << hotel.getChambre().size() << std::endl;
}
