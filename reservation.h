#include "date.h"
#include "hotel.h"
#include "chambre.h"
#include "client.h"

class Reservation
{
private:
	Date _debut;
	int _nbreNuit;
	Hotel _idHotel;
	Chambre _idChambre;
	Client _idClient;
	double _montant;
public:
	Reservation();
	bool isValid();
	~Reservation();
	
};