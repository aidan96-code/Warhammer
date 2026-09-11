#include <iostream>
#include<string>

using namespace std;

//parent class

class Model {
protected:
	int year;
	string name;
	int movement;
	int wounds;

public:
	Model(int year, string name, int movement, int wounds)
		:year(year), name(name), movement(movement), wounds(wounds) {
	}

	virtual void display() {
		cout << "year " << year << endl;
		cout << "name " << name << endl;
		cout << "movement " << movement << endl;
		cout << "wounds " << wounds << endl;
	}
};

//inherited class

class Imperium : public Model {
private:
	string faction;

public:
	Imperium(int year, string name, int movement, int wounds, string faction)
		:Model(year, name, movement, wounds),
		faction(faction) {

	}

	void display() override {
		cout << "year " << year << endl;
		cout << "name " << name << endl;
		cout << "movement " << movement << endl;
		cout << "wounds " << wounds << endl;
		cout << "Faction: " << faction << endl;
	}
};

int main() {
	Model myModel(2025, "Generic Model", 6, 3);

	Imperium myImperium(2025, "", 6, 1, "Adepta Soriritas");


	cout << "MODEL" << endl;
	myModel.display();

	cout << endl << "IMPERIUM MODEL" << endl;
	myImperium.display();

};
