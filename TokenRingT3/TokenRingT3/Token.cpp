#include "Token.h"
#include <iostream>

Token::Token(int sursa, int destinatie, std::string mesaj)
    :m_ipSursa(sursa), m_ipDestinatie(destinatie), m_mesajToken(mesaj)
{
}

int Token::GetIpSursa()
{
    return m_ipSursa;
}

int Token::GetIpDestinatie()
{
    return m_ipDestinatie;
}

std::string Token::GetMesajToken()
{
    return m_mesajToken;
}

bool Token::GetAjunsLD()
{
    return m_ajunsLD;
}

bool Token::GetLiber()
{
    return m_liber;
}

std::vector<int> Token::GetIstoric()
{
    return m_istoric;
}

void Token::SetIpSursa(int sursa)
{
    m_ipSursa = sursa;
}

void Token::SetIpDestinatie(int destinatie)
{
    m_ipDestinatie = destinatie;
}

void Token::SetAjunsLD(bool stare)
{
    m_ajunsLD = stare;
}

void Token::SetLiber(bool stare)
{
    m_liber = stare;
}

void Token::AdaugareIstoric(int pozitie)
{
    m_istoric.emplace_back(pozitie);
}

void Token::Afisare()
{
    std::cout << "Jeton(" << m_ipSursa << ", " << m_ipDestinatie << ", " << m_mesajToken << ", " << m_ajunsLD << ", " << m_liber << ", ";
    for (int index = 0; index < m_istoric.size(); index++)
    {
        std::cout << m_istoric[index] << " ";
    }
    std::cout << ")\n";
}

void Token::StergeTot()
{
    m_ipSursa = -1;
    m_ipDestinatie = -1;
    m_mesajToken.clear();
    m_ajunsLD = false;
    m_liber = true;
    m_istoric.clear();
}
