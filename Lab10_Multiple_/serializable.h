#pragma once
#include <iostream>

class Serializable
{
public:
	// Beleírja az os-be a mentendõ részeit
	virtual void serialize(std::ostream& os) const = 0;
	// Visszaállítja magát az is-bõl
	virtual void deserialize(std::istream& is) = 0;
};
