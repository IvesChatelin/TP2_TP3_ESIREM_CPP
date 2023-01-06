#ifndef RESERVATION_H
#define RESERVATION_H

#include "date.h"
#include "hotel.h"
#include "iostream"
#include <string>

class Reservation {
private:
  int _numReservation;
  std::string _idHotel;
  std::string _idClient;
  int _idChambre;
  int _nbreNuit;
  Date _debut;
  double _montant_total;

public:
  Reservation(int numReservation, std::string idhotel, std::string idclient,
              int idchambre, int nbreNuit, Date dateDebut);
  bool isValid(int nbreNuit, int idchambre);
  int getNumReservation() const;
  int getNbreNuit();
  std::string getidClient();
  Date getDate();
  std::string getIdHotel();
  int getidChambre();
  double getMontant();
  void setMontant(double montant);
  void updateDate_NbreNuit(const Date &date, const int &nbrenuit);
  void updateDate_NbreNuit(const Date &date);
  void updateDate_NbreNuit(const int &nbrenuit);
  friend void updateReservation(std::vector<Reservation> &reservations,
                                std::string &hotel_client);
};

double montant_reservation(Reservation &reservation, Hotel hotel);
Chambre chambre_dispo(std::vector<Reservation> reservations, Hotel hotel,
                      Date d, std::string type);
void getAllReservation(std::vector<Reservation> reservations);
void getReservation(std::vector<Reservation> reservations, int num);
void getReservation(std::vector<Reservation> reservations,
                    std::string idClient);
void annuleReservation(std::vector<Reservation> &reservations);

#endif