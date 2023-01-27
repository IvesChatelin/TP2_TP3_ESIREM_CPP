#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <string>

class Chambre {
private:
  int _num;
  std::string _type;
  double _prix;

public:
  Chambre(int num = 1, std::string type = "", double prix = 1.0);
  int getNum() const;
  std::string getType() const;
  double getPrix() const;
  void updatePrix(const double &prix);
  bool isValid(int num, double prix);
};
std::ostream &operator<<(std::ostream &os, const Chambre &chambre);
#endif