#include "date.h"
#include <assert.h>
#include <iostream>
#include <string>

Date::Date(int jour, int mois, int annee)
    : _jour(jour), _mois(mois), _annee(annee) {
  bool status = isValid(jour, mois, annee);
  assert(status && "Date non valide ");
}

int Date::getjour() const { return _jour; }

int Date::getmois() const { return _mois; }

int Date::getannee() const { return _annee; }

Date Date::getDate() { return *this; }

void Date::updatemois(int mois) {
  bool status = isValid(_jour, mois, _annee);
  assert(status && "mois non valide");
  _mois = mois;
}

void Date::updatejour(int jour) {
  bool status = isValid(jour, _mois, _annee);
  assert(status && "jour non valide");
  _jour = jour;
}

void Date::updateannee(int annee) {
  bool status = isValid(_jour, _mois, annee);
  assert(status && "annee non valide ");
}

bool Date::isValid(int jour, int mois, int annee) {

  if ((jour < 1) || (jour > 31) || (annee < 2022))
    return false;
  if ((mois < 1) || (mois > 12) || (annee < 2022))
    return false;
  if (((mois == 2) && (jour > 29)) || (annee < 2022))
    return false;
  if (((((mois == 4) || (mois == 6) || (mois == 9) || (mois == 11))) &&
       (jour > 30)) ||
      (annee < 2022))
    return false;
  return true;
}

int getJouDuMois(int mois) {
  if (mois == 2) {
    return 29;
  } else if (mois == 4 || mois == 6 || mois == 9 || mois == 11) {
    return 30;
  } else {
    return 31;
  }
}

Date operator+(const Date &date, const int days) {
  if (days < 0) {
    return date;
  }
  Date tmp = date;
  int new_day = tmp.getjour() + days;
  int new_month = tmp.getmois();
  int days_in_month = getJouDuMois(tmp.getmois());
  while (new_day > days_in_month) {
    new_day -= days_in_month;
    new_month++;
    if (new_month > 12) {
      new_month = 1;
    }
    tmp.updatemois(new_month);
    days_in_month = getJouDuMois(tmp.getmois());
  }
  return Date(new_month, new_day);
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
  std::string month[12] = {"Jan",  "Feb", "March", "April", "May", "June",
                           "July", "Aug", "Sept",  "Oct",   "Nov", "Dec"};
  std::string to_display = std::to_string(date.getjour()) + "/" +
                           month[date.getmois() - 1] + "/" +
                           std::to_string(date.getannee());
  os << to_display << std::endl;
  return os;
}
