#include"Ring.h"
#include<iostream>
#include <string>

void AfisareDate(Token jeton, Ring retea);

int main()
{

	int numarPC;
	std::cout << "Introduceti numarul de calculatoare din retea: ";
	std::cin >> numarPC;
	Ring retea(numarPC);


	int sursa, destinatie;
	std::cout << "Introduceti calculatorul sursa: ";
	std::cin >> sursa;
	std::cout << "Introduceti calculatorul destinatie: ";
	std::cin >> destinatie;

	std::string mesaj;
	std::cout << "Introduceti mesajul: ";
	std::cin >> mesaj;
	Token jeton(sursa, destinatie, mesaj);

	AfisareDate(jeton, retea);
	retea.TokenRing(jeton);





	return 0;

}

void AfisareDate(Token jeton, Ring retea)
{
	
	std::cout << "Token contine:" << std::endl;
	std::cout << "Sursa: " << jeton.GetIpSursa() << std::endl;
	std::cout << "Destinatia: " << jeton.GetIpDestinatie() << std::endl;
	std::cout << "Mesaj: " << jeton.GetMesajToken() << std::endl;
	std::cout << std::endl;
}
