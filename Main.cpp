#include <iostream>
#include <string>
#include <vector>

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

	virtual void display() const {
		cout << "Year: " << year << endl;
		cout << "Name: " << name << endl;
		cout << "Movement: " << movement << endl;
		cout << "Wounds: " << wounds << endl;
	}
};

class spacemarine : public imperium {
private:
	string chapter;

public:
	spacemarine(int year, string name, int movement, int wounds, string chapter)
		:imperium(year, name, movement, wounds), chapter(chapter) {
	}

	void display() const override {
		cout << "Year: " << year << endl;
		cout << "Name: " << name << endl;
		cout << "Movement: " << movement << endl;
		cout << "Wounds: " << wounds << endl;
		cout << "Chapter: " << chapter << endl;
	}
};

int main() {
	vector<spacemarine> army;

	int numberofMarines;

	cout << "How many space marines do you want to add? ";
	cin >> numberofMarines;

	for (int i = 0; i < numberofMarines; i++) {

		int year;
		string name;
		int movement;
		int wounds;
		string chapter;

		cout << "\n--- Space Marine " << i + 1 << "---\n";

		cout << "Enter year: ";
		cin >> year;

		cout << "Enter name: ";
		cin.ignore();
		getline(cin, name);

		cout << "Enter movement: ";
		cin >> movement;

		cout << "Enter wounds: ";
		cin >> wounds;

		cout << "Enter chapter: ";
		cin.ignore();
		getline(cin, chapter);

		spacemarine newMarine(
			year,
			name,
			movement,
			wounds,
			chapter
		);

		army.push_back(newMarine);
	}

	cout << "\n====================\n";
	cout << "YOUR SPACE MARINE ARMY\n";
	cout << "====================\n";

	for (const spacemarine& marine : army) {
		marine.display();
		cout << "-----------\n";
	}
	return 0;

}