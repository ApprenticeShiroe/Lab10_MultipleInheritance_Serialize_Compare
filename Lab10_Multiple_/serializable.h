#pragma once
#include <iostream>

class Serializable
{
public:
	// Bele�rja az os-be a mentend� r�szeit
	virtual void serialize(std::ostream& os) const = 0;
	// Vissza�ll�tja mag�t az is-b�l
	virtual void deserialize(std::istream& is) = 0;
};
