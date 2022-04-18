#pragma once
#include"Token.h"

class Ring
{
public:
	Ring(int dimensiuneRetea);

	void TokenRing(Token jeton);

private:
	std::vector<int> m_reteaPC;
};