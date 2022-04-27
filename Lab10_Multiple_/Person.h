#pragma once
#include "serializable.h"
#include "comparable.h"

class Person : public Serializable, public Comparable
{
private:
	unsigned char age;
	double height;
	double weight;
public:
	Person(unsigned char age, double height, double weight) :age(age), height(height), weight(weight) {}

	unsigned char getAge() const { return age; }
	double getHeight() const { return height; }
	double getWeight() const { return weight; }

	void setAge(unsigned char age) { this->age = age; }
	bool setHeight(double height) {
		if (height < 0)return false;
		this->height = height;
		return true;
	}
	bool setWeight(double weight) {
		if (weight < 0)return false;
		this->weight = weight;
		return true;
	}


	void serialize(std::ostream& os) const;
	void deserialize(std::istream& is);

	bool operator==(const Comparable& other) const;
	bool operator<(const Comparable& other) const;

	friend std::ostream& operator<<(std::ostream& os, Person const& p);

};