#include <iostream>
#include <fstream>
#include "Person.h"
#include "Sorter.h"

using namespace std;

int main()
{
	const unsigned PEOPLE_COUNT = 4;

	Person* match = new Person(30, 180, 85);
	Person* people[PEOPLE_COUNT];

	people[0] = new Person(40, 182, 90);
	people[1] = new Person(12, 100, 50);
	people[2] = new Person(30, 180, 85);
	people[3] = new Person(40, 182, 90);



	// Lehet, hogy a HSZK-ban módosítani kell az elérési utat, hogy legyen írási jog.
	const char* fname = "people.dat";

	ofstream os(fname);

	if (!os) {
		cerr << "Error opening output file: " << fname << endl;
		return -1;
	}

	cout << "\tSerializing people" << endl;
	cout << "State\tIndex\tAge\tHeight\tWeight\tMatch" << endl;
	for (unsigned i = 0; i < PEOPLE_COUNT; i++)
	{
		cout << "Ser.\t" << i << '\t' << *people[i] << '\t' << (!(*people[i] == *match || *people[i] < *match) ? '+' : '-') << endl;

		people[i]->serialize(os);

		people[i]->setAge(0);
		people[i]->setHeight(20);
		people[i]->setWeight(10);
		cout << "Modif.\t" << i << '\t' << *people[i] << '\t' << (!(*people[i] == *match || *people[i] < *match) ? '+' : '-') << endl;
	}

	os.close();

	if (!os) {
		cerr << "Error writing output file: " << fname << endl;
		return -1;
	}

	ifstream is(fname);
	if (!is) {
		cerr << "Error opening input file: " << fname << endl;
		return -1;
	}

	cout << endl << "\tDeserializing people" << endl;
	cout << "State\tIndex\tAge\tHeight\tWeight\tMatch" << endl;
	for (unsigned j = 0; j < PEOPLE_COUNT; j++) {
		people[j]->deserialize(is);
		cout << "Deser.\t" << j << '\t' << *people[j] << '\t' << (!(*people[j] == *match || *people[j] < *match) ? '+' : '-') << endl;
	}

	is.close();
	if (!is) {
		cerr << "Error reading input file: " << fname << endl;
		return -1;
	}

	delete match;
	for (unsigned k = 0; k < PEOPLE_COUNT; k++)
		delete people[k];

	// Ide rakj töréspontot. Ha a debugger ideáig eljut, sikeresen lefutott minden teszt.
	return 0;
}