#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
  std::string _idClient;
  std::string _nom;
  std::string _prenom;

public:
  Client(std::string idClient = "", std::string nom = "",
         std::string prenom = "");
  std::string getId() const;
  void setId(std::string id);
  std::string getNom() const;
  void setNom(std::string nom);
  std::string getPrenom() const;
  void setPrenom(std::string prenom);
  std::string getClient();
};
std::ostream &operator<<(std::ostream &os, Client client);
#endif