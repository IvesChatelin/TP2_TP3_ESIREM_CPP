#include "client.h"
#include <iostream>
#include <string>

Client::Client(std::string idClient, std::string nom, std::string prenom)
    : _idClient(idClient), _nom(nom), _prenom(prenom) {}

std::string Client::getId() const { return _idClient; }

void Client::setId(std::string id) { _idClient = id; }

std::string Client::getNom() const { return _nom; }

void Client::setNom(std::string nom) { _nom = nom; }

std::string Client::getPrenom() const { return _prenom; }

void Client::setPrenom(std::string prenom) { _prenom = prenom; }

std::string Client::getClient() {
  return _idClient + " " + _nom + " " + _prenom;
}

std::ostream &operator<<(std::ostream &os, Client client) {
  os << "***********Client**********\n"
     << "ID du client : " + client.getId() + "\n" +
            "Nom du Client : " + client.getNom() + "\n" +
            "Prenom du client : " + client.getPrenom()
     << std::endl;
  return os;
}
