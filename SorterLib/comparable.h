#pragma once

class Comparable
{
public:
	// Igazzal tér vissza, ha a két Comparable egyenlõ (implementáció függõ),
	// minden más esetben hamissal.
	virtual bool operator==(const Comparable& other) const = 0;
	// Igazzal tér vissza, ha a bal oldali Comparable kisebb (szintén
	// implementáció függõ),
	// mint a jobb oldali (other), minden más esetben hamissal.
	virtual bool operator<(const Comparable& other) const = 0;
};