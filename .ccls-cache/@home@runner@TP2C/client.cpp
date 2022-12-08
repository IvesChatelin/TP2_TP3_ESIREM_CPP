
#include "client.h"
#include <string>

Client::Client(std::string idClient, std::string nom, std::string prenom): _idClient(idClient), _nom(nom), _prenom(prenom){

}

std::string Client::getId(){
	return _idClient;
}

std::string Client::getNom(){
	return _nom;
}

std::string Client::getPrenom(){
	return _prenom;
}

std::string Client::getClient(){
	return _idClient + " " + _nom + " " + _prenom;
}


