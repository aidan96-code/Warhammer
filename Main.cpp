#include <iostream>
#include <string>
#include <vector>
#include <memory>

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
	virtual ~imperium() = default;
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

class sistersofbattle : public imperium {
private:
	string order;

public:
	sistersofbattle(int year, string name, int movement, int wounds, string order)
		:imperium(year, name, movement, wounds), order(order) {
	}

	void display() const override {
		cout << "Year: " << year << endl;
		cout << "Name: " << name << endl;
		cout << "Movement: " << movement << endl;
		cout << "Wounds: " << wounds << endl;
		cout << "Order: " << order << endl;
	}
};


int main() {
	vector<unique_ptr<imperium>> army;

	int numberofUnits;

	cout << "How many units do you want to add? ";
	cin >> numberofUnits;

	for (int i = 0; i < numberofUnits; i++) {

		int choice;

		cout << "\n====================\n";
		cout << "UNIT " << i + 1 << endl;
		cout << "====================\n";

		cout << "What unit would you like to add?\n";
		cout << "1. Space Marine\n";
		cout << "2. Sisters of Battle\n";
		cout << "Enter your choice (1 or 2): ";

		cin >> choice;

		int year;
		string name;
		int movement;
		int wounds;

		cout << "Enter year: ";
		cin >> year;

		cout << "Enter name: ";
		cin.ignore();
		getline(cin, name);

		cout << "Enter movement: ";
		cin >> movement;

		cout << "Enter wounds: ";
		cin >> wounds;

		if (choice == 1) {
			string chapter;
			cout << "Enter chapter: ";
			cin.ignore();
			getline(cin, chapter);
			army.push_back(
				make_unique<spacemarine>(
					year,
					name,
					movement,
					wounds,
					chapter
				)
			);
		}
		else if (choice == 2) {
			string order;
			cout << "Enter order: ";
			cin.ignore();
			getline(cin, order);
			army.push_back(
				make_unique<sistersofbattle>(
					year,
					name,
					movement,
					wounds,
					order
				)
			);
		}
		else {
			cout << "Invalid choice. Please enter 1 or 2." << endl;
			i--; // Decrement i to repeat this iteration
			continue; // Skip the rest of the loop and go to the next iteration
		}
	}

	cout << "\n====================\n";
	cout << "YOUR IMPERIUM ARMY\n";
	cout << "====================\n";

	for (const auto& unit : army) {
		unit->display();
		cout << "-----------\n";
	}
	return 0;

}