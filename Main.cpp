#include <iostream>
#include <string>

using namespace std;

class imperium {
protected:
	int year;
	string name;
	int movement;
	int wounds;

public:
	imperium(int year, string name, int movement, int wounds)
		:year(year), name(name), movement(movement), wounds(wounds) {
	}

	virtual void display() {
		cout << "year " << year << endl;
		cout << "name " << name << endl;
		cout << "movement " << movement << endl;
		cout << "wounds " << wounds << endl;
	}
};

class spacemarine : public imperium {
private:
	string chapter;

public:
	spacemarine(int year, string name, int movement, int wounds, string chapter)
		:imperium(year, name, movement, wounds), chapter(chapter) {
	}

	void display() override {
		cout << "year " << year << endl;
		cout << "name " << name << endl;
		cout << "movement " << movement << endl;
		cout << "wounds " << wounds << endl;
		cout << "chapter " << chapter << endl;
	}
};

int main() {
	imperium testImperium(2025, "test", 6, 3);

	spacemarine testMarine(2025, "Dreadnought", 8, 9, "Ultramarines");

	cout << "TESTMODEL" << endl;
	testImperium.display();

	cout << "TESTMARINE" << endl;
	testMarine.display();

};