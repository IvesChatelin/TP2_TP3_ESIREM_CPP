#include <iostream>
#include "client.h"

int main()
{
	Client cl1("D15Ives","NZOKOU","Ives Chatelin");
	std::cout<<cl1.getClient()<<std::endl;
	return 0;
}