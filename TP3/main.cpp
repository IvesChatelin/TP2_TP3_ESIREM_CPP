#include "Client.h"
#include "Commande.h"
#include "Magasin.h"
#include "Produit.h"
#include <fstream>
#include <iostream>
#include <vector>

int main() {

  std::vector<Produit> produits = {};   // tableau des produits du magasin
  std::vector<Commande> commandes = {}; // tableau des commandes du magasin
  std::vector<Client> clients = {};     // tableau des clients du magasin
  std::string const fileClient("clients.txt");
  std::string const fileProduit("produits.txt");
  std::string const fileCommande("commandes.txt");

  // magasin
  Magasin magasin(produits, clients, commandes);
  char reponse;
menu:
  std::cout << "***Bienvenue Dans EasyStore***" << std::endl;
  std::cout << std::endl;
  std::cout << "**Menu Principal**" << std::endl;
  std::cout << "\tGestion du Magasin = m ";
  std::cout << "\tGestion des Utilisateurs = u ";
  std::cout << "\tGestion des Commandes = c ";
  std::cout << "\texit = * " << std::endl;
  std::cin >> reponse;
  if (reponse == '*') {
    return 0;
  }
menu_magasin:
  if (reponse == 'm') {
    std::cout << "**Menu Magasin**" << std::endl;
    std::cout << "\tAjouter un Nouveau Produit = a ";
    std::cout << "\tAfficher tous les Produits = l";
    std::cout << "\tMise à jour quantité produit = q ";
    std::cout << "\tAfficher un Produit = k ";
    std::cout << "\tMenu principal = * ";
    std::cout << "\texit = # " << std::endl;
    char rep;
    std::cin >> rep;
    if (rep == '#') {
      return 0;
    }
    if (rep == '*') {
      goto menu;
    }
    if (rep == 'q') {
      std::cout << "Entrer le nom du produits : ";
      std::string nom;
      std::cin >> nom;
      std::cout << "Entrer la quantité du Produits = ";
      int qte;
      std::cin >> qte;
      magasin.updateQuantiteProduit(nom, qte);
      std::cout << std::endl;
      goto menu_magasin;
    }
    if (rep == 'a') {
      std::cout << "Entrer le titre du produit : ";
      std::string titre;
      std::cin >> titre;
      std::cout << "Entrer la description du produit : ";
      std::string desc;
      std::cin.ignore();
      std::getline(std::cin, desc);
      std::cout << "Entrer la quantitée du produit : ";
      int qte;
      std::cin >> qte;
      std::cout << "Entrer le prix du produit : ";
      double prix;
      std::cin >> prix;
      Produit produit(titre, desc, qte, prix);
      magasin.addProduit(produit);
      std::ofstream file(fileProduit.c_str(), std::ios::app);
      if (file) {
        file << produit;
        file.close();
      } else {
        std::cout << "erreur !! dans la creation du fichier " << std::endl;
      }
      std::cout << std::endl;
      goto menu_magasin;
    }
    if (rep == 'k') {
      std::cout << "Entrer le titre du produit : ";
      std::string titre;
      std::cin >> titre;
      magasin.getProduitByName(titre);
      std::cout << std::endl;
      goto menu_magasin;
    }
    if (rep == 'l') {
      std::ifstream file("produits.txt");
      std::string ligne;
      if (file) {
        while (getline(file, ligne)) {
          std::cout << ligne << std::endl;
        }
        file.close();
      } else {
        std::cout << "Erreur!!! dans l'ouverture du fichier clients "
                  << std::endl;
      }
      // magasin.getAllProduit();
      std::cout << std::endl;
      goto menu_magasin;
    }
  }
  // utilisateur
  std::vector<Produit> panier = {};
  Client root("chato2020", "ives", "chatelin", panier);
menu_client:
  if (reponse == 'u') {
    std::cout << "**Menu Client**" << std::endl;
    std::cout << "\tAjouter un client = a";
    std::cout << "\tAfficher un client = c";
    std::cout << "\tAfficher tous les clients = b";
    std::cout << "\tAjouter un produit le pannier d'un client = p";
    std::cout << "\tModifier quantitée produit le panier d'un client = m";
    std::cout << "\tSupprimer produit dans le panier d'un client = s";
    std::cout << "\tVider Pannier d'un client = v ";
    std::cout << "\tMenu principal = * ";
    std::cout << "\texit = # " << std::endl;
    char rep;
    std::cin >> rep;
    if (rep == '#') {
      return 0;
    }
    if (rep == '*') {
      goto menu;
    }
    if (rep == 'a') {
      std::cout << "Entrer l'identifiant du client : ";
      std::string identifiant;
      std::cin >> identifiant;
      std::cout << "Entrer le nom du client : ";
      std::string nom;
      std::cin >> nom;
      std::cout << "Entrer le prenom du client : ";
      std::string prenom;
      std::cin.ignore();
      std::getline(std::cin, prenom);
      Client client(identifiant, nom, prenom, panier);
      addClientMagasin(magasin, client);
      std::ofstream file(fileClient.c_str(), std::ios::app);
      if (file) {
        file << client;
        file.close();
      } else {
        std::cout << "erreur !! dans la creation du fichier " << std::endl;
      }
      std::cout << std::endl;
      goto menu_client;
    }
    if (rep == 'c') {
      std::cout << "Entrer l'identifiant ou le nom du client : ";
      std::string identifiant;
      std::cin >> identifiant;
      getClient(magasin, identifiant);
      std::cout << std::endl;
      goto menu_client;
    }
    if (rep == 'b') {
      std::ifstream file("clients.txt");
      std::string ligne;
      if (file) {
        while (getline(file, ligne)) {
          std::cout << ligne << std::endl;
        }
        file.close();
      } else {
        std::cout << "Erreur!!! dans l'ouverture du fichier clients "
                  << std::endl;
      }
      // getAllClientMagasin(magasin);
      std::cout << std::endl;
      goto menu_client;
    }
    if (rep == 'p') {
      std::cout << "Entrer le nom du produit : ";
      std::string nom;
      std::cin >> nom;
      std::cout << "Entrer l' identifiant du client : ";
      std::string id;
      std::cin >> id;
      addProduitPanierClient(magasin, nom, id);
      std::cout << std::endl;
      goto menu_client;
    }
    if (rep == 'm') {
      std::cout << "Entrer l' identifiant du client : ";
      std::string id;
      std::cin >> id;
      std::cout << "Entrer le nom du produit : ";
      std::string nom;
      std::cin >> nom;
      std::cout << "Entrer la quantitée du produit : ";
      int qte;
      std::cin >> qte;
      updateQteProduitClient(magasin, nom, qte, id);
      std::cout << std::endl;
      goto menu_client;
    }
    if (rep == 's') {
      std::cout << "Entrer l' identifiant du client : ";
      std::string id;
      std::cin >> id;
      std::cout << "Entrer le nom du produit : ";
      std::string nom;
      std::cin >> nom;
      deleteProduitPanierClient(magasin, nom, id);
      std::cout << std::endl;
      goto menu_client;
    }
    if (rep == 'v') {
      std::cout << "Entrer l' identifiant du client : ";
      std::string id;
      std::cin >> id;
      std::vector<Client> c = magasin.getclients();
      for (auto it = c.begin(); it != c.end();) {
        if (id == (*it).getIdentifiant()) {
          (*it).videPanier();
        } else {
          ++it;
        }
      }
      std::cout << "Panier du client vidé avec success !!" << std::endl;
    }
    std::cout << std::endl;
    goto menu_client;
  }
  // commande
  std::vector<Produit> pro_com = {};
menu_commande:
  if (reponse == 'c') {
    std::cout << "**Menu Commande**" << std::endl;
    std::cout << "\tMettre à jour statu commande = m ";
    std::cout << "\tAfficher tous commandes = l";
    std::cout << "\tAfficher tous commandes d'un client = c";
    std::cout << "\tValider commande = v ";
    std::cout << "\tMenu principal = * ";
    std::cout << "\texit = # " << std::endl;
    char rep;
    std::cin >> rep;
    if (rep == '#') {
      return 0;
    }
    if (rep == '*') {
      goto menu;
    }
    if (rep == 'm') {
      std::cout << "Entrer le numero de la commande : ";
      int num;
      std::cin >> num;
      std::cout << "Entrer le Statu de la commande en chiffre ( 0 = Livrée / 1 "
                   "= Non_Livrée) : ";
      int stat;
      std::cin >> stat;
      if (stat == 0) {
        updateStatusCommande(magasin, num, Livrée);
      } else {
        updateStatusCommande(magasin, num, Non_livrée);
      }
      std::cout << std::endl;
      goto menu_commande;
    }
    if (rep == 'l') {
      std::ifstream file(fileCommande);
      std::string ligne;
      if (file) {
        while (getline(file, ligne)) {
          std::cout << ligne << std::endl;
        }
        file.close();
      } else {
        std::cout << "Erreur!!! dans l'ouverture du fichier clients "
                  << std::endl;
      }
      // getAllCommande(magasin);
      std::cout << std::endl;
      goto menu_commande;
    }
    if (rep == 'c') {
      std::cout << "Entrer l' identifiant du client : ";
      std::string id;
      std::cin >> id;
      getAllCommande(magasin, id);
      std::cout << std::endl;
      goto menu_commande;
    }
    if (rep == 'v') {
      std::cout << "Entrer l' identifiant du client : ";
      std::string id;
      std::cin >> id;
      std::cout << "Entrer le nom du produit : ";
      std::string nom;
      std::cin >> nom;
      std::vector<Produit> produits = magasin.getproduits();
      for (auto it = produits.begin(); it != produits.end(); ++it) {
        if (nom == (*it).getTitre()) {
          pro_com.push_back(*it);
        }
      }
      std::cout << "Ajouter un produit (o/n) : ";
      char rep;
      std::cin >> rep;
      while (rep == 'o') {
        std::cout << "Entrer le nom du produit : ";
        std::string nom;
        std::cin >> nom;
        std::vector<Produit> produits = magasin.getproduits();
        for (auto it = produits.begin(); it != produits.end(); ++it) {
          if (nom == (*it).getTitre()) {
            pro_com.push_back(*it);
          }
        }
        std::cout << "Ajouter un produit (o/n) : ";
        char rep;
        std::cin >> rep;
      }
      std::cout << "Entrer le Statu de la commande en chiffre ( 0 = Livrée / 1 "
                   "= Non_Livrée) : ";
      int stat;
      std::cin >> stat;
      if (stat == 0) {
        Commande commande(id, pro_com, Livrée);
        validerCommande(magasin, commande);
        std::ofstream file(fileCommande.c_str(), std::ios::app);
        if (file) {
          file << commande;
          file.close();
        } else {
          std::cout << "erreur !! dans la creation du fichier " << std::endl;
        }
      } else {
        Commande commande(id, pro_com, Non_livrée);
        validerCommande(magasin, commande);
        std::ofstream file(fileCommande.c_str(), std::ios::app);
        if (file) {
          file << commande;
          file.close();
        } else {
          std::cout << "erreur !! dans la creation du fichier " << std::endl;
        }
      }
      std::cout << std::endl;
      goto menu_commande;
    }
  }
}