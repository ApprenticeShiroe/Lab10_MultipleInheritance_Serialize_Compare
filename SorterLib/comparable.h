#pragma once

class Comparable
{
public:
	// Igazzal t�r vissza, ha a k�t Comparable egyenl� (implement�ci� f�gg�),
	// minden m�s esetben hamissal.
	virtual bool operator==(const Comparable& other) const = 0;
	// Igazzal t�r vissza, ha a bal oldali Comparable kisebb (szint�n
	// implement�ci� f�gg�),
	// mint a jobb oldali (other), minden m�s esetben hamissal.
	virtual bool operator<(const Comparable& other) const = 0;
};