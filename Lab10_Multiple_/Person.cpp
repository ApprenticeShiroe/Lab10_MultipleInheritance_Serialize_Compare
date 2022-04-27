#include "Person.h"


void Person::serialize(std::ostream& os) const {
	os << age << std::endl
		<< height << std::endl
		<< weight << std::endl;
}
void Person::deserialize(std::istream& is) {
	is >> age >> height >> weight;
}

bool Person::operator==(const Comparable& other) const{
	Person const* otherPerson = (Person const*)&otherPerson;
	return age == otherPerson->age
		&& height == otherPerson->height
		&& weight == otherPerson->weight;
}
bool Person::operator<(const Comparable& other) const {
	Person const* otherPerson = (Person const*)&otherPerson;
	return age < otherPerson->age;
}

std::ostream& operator<<(std::ostream& os, Person const& p) {
	return os << (int)p.age << ", "
		<< p.height << ", "
		<< p.weight;
}