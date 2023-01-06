#include "chambre.h"
#include "client.h"
#include "date.h"
#include "hotel.h"
#include "reservation.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

int main() {

  // tableau de Chambres
  Chambre ch1(3, "Single", 100.0);
  Chambre ch2(4, "Single", 100.0);
  Chambre ch3(5, "Single", 100.0);
  Chambre ch4(6, "Double", 125.0);
  Chambre ch5(7, "Double", 125.0);
  Chambre ch6(8, "Double", 125.0);
  Chambre ch7(9, "Double", 125.0);
  Chambre ch8(10, "Double", 125.0);
  Chambre ch9(11, "Suit", 210.0);
  Chambre ch10(12, "Suit", 210.0);
  std::vector<Chambre> chambres = {ch1, ch2, ch3, ch4, ch5,
                                   ch6, ch7, ch8, ch9, ch10};

  // tableau de Clients
  Client cl1("Chato237", "NZOKOU", "Ives Chatelin");
  Client cl2("Nono237", "NONO", "Christiant");
  std::vector<Client> clients = {cl1, cl2};

  // Hotêl
  Hotel h1("OCEAN15N", "Hotel de Dijon", "Dijon", chambres);

  // Partie Client
  std::string nom, prenom;
  std::cout << "Entrez votre nom : ";
  std::cin >> nom;
  std::cout << "Entrez votre prenom : ";
  std::cin >> prenom;
  std::cout << std::endl;
  bool status = false;
  Client cl;
  for (auto it = clients.begin(); it != clients.end(); ++it) {
    if (nom == (*it).getNom() && prenom == (*it).getPrenom()) {
      cl = (*it);
      std::cout << *it;
      std::cout << std::endl;
      status = true;
    }
  }
  if (!status) {
    std::string id;
    std::cout << "Vous n'êtes pas client " << std::endl;
    std::cout << std::endl;
    std::cout << "Entrez un identifiant : ";
    std::cin >> id;
    cl.setId(id);
    cl.setNom(nom);
    cl.setPrenom(prenom);
    clients.push_back(cl);
  }

  // Date
  int jour, mois, annee, nb_nuit;
  std::cout << "Entrer la date de la reservation" << std::endl;
  std::cout << "Jour : ";
  std::cin >> jour;
  while (jour <= 0) {
    std::wcerr << "Erreur !! le jour doit être superieur à 0 " << std::endl;
    std::cout << "Jour : ";
    std::cin >> jour;
  }
  std::cout << "le mois : ";
  std::cin >> mois;
  while ((jour > 29 && mois == 2) || (mois <= 0) || (mois > 12)) {
    std::wcerr << "Erreur !! le mois doit être en 1 et 12 et le mois de "
                  "fevrier pas plus de 29 jour"
               << std::endl;
    std::cout << "le mois : ";
    std::cin >> mois;
  }
  std::cout << "l'annee : ";
  std::cin >> annee;
  while (annee <= 0 || annee < 2022) {
    std::wcerr << "Erreur!!!! la date, doivent être superieur à 0 et 2022"
               << std::endl;
    std::cout << "l'annee : ";
    std::cin >> annee;
  }
  std::cout << std::endl;
  Date d(jour, mois, annee);

  // Nombre de Nuit
  std::cout << "Entrer le Nombre de Nuit : ";
  std::cin >> nb_nuit;
  while (nb_nuit <= 0) {
    std::wcerr << "Erreur!!!! le Nombre de jour doit être superieur à 0!"
               << std::endl;
    std::cout << "Entrer le Nombre de Nuit : ";
    std::cin >> nb_nuit;
  }
  std::cout << std::endl;

  // Partie reservation
  std::vector<Reservation> reservations = {};
  std::string type;
  std::cout << "Quel type de chambre souhaitez-vous : ";
  std::cin >> type;
  std::cout << std::endl;
  std::vector<Chambre> ch_dispos;
  ch_dispos.push_back(chambre_dispo(reservations, h1, d, type));
  Chambre chambre_libre = ch_dispos[0];
  if (ch_dispos.empty()) {
    std::cout << "Aucune Chambre disponible dans cette hotêl !!!!" << std::endl;
    std::cout << std::endl;
  } else {
    std::cout << "**Chambre disponible** \n"
              << "Identifiant : " << chambre_libre.getNum() << "\n"
              << "Prix : " << chambre_libre.getPrix() << "$\n"
              << std::endl;
  }
  int num = rand() % 1000;
  Reservation rserv(num, h1.getidentifiant(), cl.getId(),
                    chambre_libre.getNum(), nb_nuit, d);
  montant_reservation(rserv, h1);
  Date d2(14, 01, 2023);
  rserv.updateDate_NbreNuit(d2);
  reservations.push_back(rserv);
  getAllReservation(reservations);
  /*getReservation(reservations, num);
  getReservation(reservations, cl.getId());
  annuleReservation(reservations);*/
  // std::cout << reservations.size() << std::endl;
  return 0;
}