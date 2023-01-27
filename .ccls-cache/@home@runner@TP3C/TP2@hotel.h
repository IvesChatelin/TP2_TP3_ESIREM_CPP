#ifndef HOTEL_H
#define HOTEL_H

#include "chambre.h"
#include "date.h"
#include <string>
#include <vector>

class Hotel {
private:
  std::string _identifiant;
  std::string _nom;
  std::string _ville;
  std::vector<Chambre> _chambre;

public:
  Hotel(std::string identifiant, std::string nom, std::string ville,
        std::vector<Chambre> chambre);
  std::string getidentifiant() const;
  std::string getnom() const;
  std::string getville() const;
  std::vector<Chambre> getChambre();
  void addroom(Chambre chambre);
};
std::ostream &operator<<(std::ostream &os, Hotel &hotel);
#endif