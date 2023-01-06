#include "reservation.h"
#include "chambre.h"
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>

Reservation::Reservation(int numReservation, std::string idhotel,
                         std::string idclient, int idchambre, int nbreNuit,
                         Date dateDebut)
    : _numReservation(numReservation), _idHotel(idhotel), _idClient(idclient),
      _idChambre(idchambre), _nbreNuit(nbreNuit), _debut(dateDebut) {
  bool status = isValid(nbreNuit, idchambre);
  assert(status && "Reservation non valid !!!");
}

bool Reservation::isValid(int nbreNuit, int idchambre) {
  if (nbreNuit <= 0 || idchambre <= 0)
    return false;
  return true;
}

int Reservation::getNbreNuit() { return _nbreNuit; }

int Reservation::getNumReservation() const { return _numReservation; }

std::string Reservation::getidClient() { return _idClient; }

std::string Reservation::getIdHotel() { return _idHotel; }

int Reservation::getidChambre() { return _idChambre; }

double Reservation::getMontant() { return _montant_total; }

void Reservation::setMontant(double montant) { _montant_total = montant; }

Date Reservation::getDate() { return _debut; }

// modifie la date et le nombre de nuit
void Reservation::updateDate_NbreNuit(const Date &date, const int &nbrenuit) {
  _debut = date;
  _nbreNuit = nbrenuit;
}

// modifie la date
void Reservation::updateDate_NbreNuit(const Date &date) { _debut = date; }

// modifie le nombre de nuit
void Reservation::updateDate_NbreNuit(const int &nbrenuit) {
  _nbreNuit = nbrenuit;
}

// calcule de montant d'une reservation
double montant_reservation(Reservation &reservation, Hotel hotel) {
  std::vector<Chambre> vector;
  vector = hotel.getChambre();
  if (reservation.getIdHotel() == hotel.getidentifiant()) {
    for (auto it = vector.begin(); it != vector.end(); ++it) {
      if (it->getNum() == reservation.getidChambre()) {
        reservation.setMontant(it->getPrix() * reservation.getNbreNuit());
        return it->getPrix() * reservation.getNbreNuit();
      }
    }
  }
  return 0;
}

// retourne les chambres du mmême dispobible à l'htôle
Chambre chambre_dispo(std::vector<Reservation> reservations, Hotel hotel,
                      Date d, std::string type) {
  std::vector<Chambre> list_chambre;
  list_chambre = hotel.getChambre();
  int num = 0;
  Date d_added;
  Chambre ch;
  for (auto it = list_chambre.begin(); it != list_chambre.end(); ++it) {
    if (type == (*it).getType()) {
      num = (*it).getNum();
      if (reservations.empty()) {
        ch = (*it);
      } else {
        for (auto it2 = reservations.begin(); it2 != reservations.end();
             ++it2) {
          d_added = ((*it2).getDate() + (*it2).getNbreNuit());
          if (num != (*it2).getidChambre() &&
              ((d_added.getjour() < d.getjour()) ||
               (d_added.getmois() < d.getmois()) ||
               (d_added.getannee() < d.getannee()))) {
            ch = (*it);
          }
        }
      }
    }
  }
  return ch;
}

// affiche la liste des reservations
void getAllReservation(std::vector<Reservation> reservations) {
  for (auto it = reservations.begin(); it != reservations.end(); ++it) {
    std::cout << "N° de la reservation : " << (*it).getNumReservation() << "\n"
              << "Identifiant de l'hotêl : " + (*it).getIdHotel() + "\n"
              << "Identifiant du client : " + (*it).getidClient() + "\n"
              << "N° de chambre : " << (*it).getidChambre() << "\n"
              << "Nombre de Nuit : " << (*it).getNbreNuit() << "\n"
              << "Date de reservation : " << (*it).getDate()
              << "Montant de la Reservation : " << (*it).getMontant() << "$\n"
              << std::endl;
  }
}

// affiche une reservation à partir de son numero de reservation
void getReservation(std::vector<Reservation> reservations, int num) {
  for (auto it = reservations.begin(); it != reservations.end(); ++it) {
    if (num == (*it).getNumReservation()) {
      std::cout << "N° de la reservation : " << (*it).getNumReservation()
                << "\n"
                << "Identifiant de l'hotêl : " + (*it).getIdHotel() + "\n"
                << "Identifiant du client : " + (*it).getidClient() + "\n"
                << "N° de chambre : " << (*it).getidChambre() << "\n"
                << "Nombre de Nuit : " << (*it).getNbreNuit() << "\n"
                << "Date de reservation : " << (*it).getDate()
                << "Montant de la Reservation : " << (*it).getMontant() << "$\n"
                << std::endl;
    } else {
      std::cout << "Aucune Reservation enregistrée à ce numero !!" << std::endl;
    }
  }
}

// affiche les reservation faites pas un client
void getReservation(std::vector<Reservation> reservations,
                    std::string idClient) {
  for (auto it = reservations.begin(); it != reservations.end(); ++it) {
    if (idClient == (*it).getidClient()) {
      std::cout << "N° de la reservation : " << (*it).getNumReservation()
                << "\n"
                << "Identifiant de l'hotêl : " + (*it).getIdHotel() + "\n"
                << "Identifiant du client : " + (*it).getidClient() + "\n"
                << "N° de chambre : " << (*it).getidChambre() << "\n"
                << "Nombre de Nuit : " << (*it).getNbreNuit() << "\n"
                << "Date de reservation : " << (*it).getDate()
                << "Montant de la Reservation : " << (*it).getMontant() << "$\n"
                << std::endl;
    } else {
      std::cout
          << "Aucune Reservation enregistrée avec l'identifiant de ce client !!"
          << std::endl;
    }
  }
}

// Modifie une Rservation
void updateReservation(std::vector<Reservation> &reservations,
                       std::string &hotel_client) {
  bool status = false;
  for (auto it = reservations.begin(); it != reservations.end(); ++it) {
    if (hotel_client == (*it).getIdHotel()) {
      (*it)._idHotel = hotel_client;
      std::cout << "Reservation modifiée avec success !!" << std::endl;
      status = true;
    }
    if (hotel_client == (*it).getidClient()) {
      (*it)._idClient = hotel_client;
      std::cout << "Reservation modifiée avec success !!" << std::endl;
      status = true;
    }
  }
  if (!status) {
    std::cout << "erreur! Reservation non modifiée !!" << std::endl;
  }
}