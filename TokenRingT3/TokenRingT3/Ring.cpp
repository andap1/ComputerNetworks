#include "Ring.h"
#include <iostream>

Ring::Ring(int dimensiuneRetea)
{
	for (int index = 0; index < dimensiuneRetea; index++)
	{
		m_reteaPC.emplace_back(index + 1);
	}
}

void Ring::TokenRing(Token jeton)
{
	bool rulare = true;
	bool gasit = false;

	auto gasireSursa = std::find(m_reteaPC.begin(), m_reteaPC.end(), jeton.GetIpSursa());
	if (gasireSursa == std::end(m_reteaPC))
	{
		std::cout << "Sursa mesajului nu se afla in retea!" << std::endl;
		rulare = false;
	}

	auto gasireDestinatie = std::find(m_reteaPC.begin(), m_reteaPC.end(), jeton.GetIpDestinatie());
	if (gasireDestinatie == std::end(m_reteaPC))
	{
		std::cout << "Destinatia mesajului nu se afla in retea!" << std::endl;
		rulare = false;
	}
	
	if (rulare == true)
	{
		jeton.SetLiber(false);
		jeton.AdaugareIstoric(jeton.GetIpSursa());
		jeton.Afisare();

		if (jeton.GetIpSursa() < jeton.GetIpDestinatie())
		{
			for (int index = jeton.GetIpSursa(); index < m_reteaPC.size(); index++)
			{
				jeton.AdaugareIstoric(m_reteaPC[index]);
				if (jeton.GetIpDestinatie() == m_reteaPC[index])
				{
					jeton.SetAjunsLD(true);
					gasit = true;					
				}
				jeton.Afisare();
				if (gasit == true)
				{
					std::cout << "Mesajul este: " << jeton.GetMesajToken() << "\n";
					gasit = false;
				}
			}
			for (int index = 0; index < m_reteaPC[jeton.GetIpSursa() - 1]; index++)
			{
				jeton.AdaugareIstoric(m_reteaPC[index]);
				jeton.Afisare();
			}
			jeton.StergeTot();
			jeton.Afisare();
		}
		else
		{
			for (int index = jeton.GetIpSursa(); index < m_reteaPC.size(); index++)
			{
				jeton.AdaugareIstoric(m_reteaPC[index]);
				jeton.Afisare();
			}			
			for (int index = 0; index < m_reteaPC[jeton.GetIpSursa() - 1]; index++)
			{
				jeton.AdaugareIstoric(m_reteaPC[index]);
				if (jeton.GetIpDestinatie() == m_reteaPC[index])
				{
					jeton.SetAjunsLD(true);
					gasit = true;
				}
				jeton.Afisare();
				if (gasit == true)
				{
					std::cout << "Mesajul este: " << jeton.GetMesajToken() << "\n";
					gasit = false;
				}
			}
			jeton.StergeTot();
			jeton.Afisare();
		}
		std::cout << "\n";
	}
}