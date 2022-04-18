#pragma once
#include<string>
#include <vector>

class Token
{
public:
	Token(int sursa, int destinatie, std::string mesaj);

	int GetIpSursa();
	int GetIpDestinatie();
	std::string GetMesajToken();
	bool GetAjunsLD();
	bool GetLiber();
	std::vector<int> GetIstoric();

	void SetIpSursa(int sursa);
	void SetIpDestinatie(int destinatie);
	void SetAjunsLD(bool stare);
	void SetLiber(bool stare);
	void AdaugareIstoric(int pozitie);

	void Afisare();
	void StergeTot();


private:
	int m_ipSursa = -1;
	int m_ipDestinatie = -1;
	std::string m_mesajToken = "";
	bool m_ajunsLD = false;
	bool m_liber = true;
	std::vector<int> m_istoric;
};

