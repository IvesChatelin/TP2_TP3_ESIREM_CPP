#include <string>

class Client
{
private:
	std::string _idClient;
	std::string _nom;
	std::string _prenom;
public:
	Client(std::string idClient, std::string nom, std::string prenom);
	std::string getId();
	std::string getNom();
	void setNom(std::string nom);
	std::string getPrenom();
	void setPrenom(std::string prenom);
	std::string getClient();
	
	
};