#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
  int _jour;
  int _mois;
  int _annee;

public:
  Date(int jour = 1, int mois = 1, int annee = 2022);
  Date getDate();
  int getjour() const;
  int getmois() const;
  int getannee() const;
  void updatejour(int jour);
  void updatemois(int mois);
  void updateannee(int annee);
  bool isValid(int jour, int mois, int annee);
};
std::string to_string(Date date);
int getJouDuMois(int mois);
Date operator+(const Date &date, const int days);
std::ostream &operator<<(std::ostream &os, const Date &date);
#endif