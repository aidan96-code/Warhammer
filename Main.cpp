#include <iostream>
#include <string>
using namespace std;

//spacemarine class

class spacemarine {
public:
	string role;
	string rank;
	int age;
	spacemarine(string x, string y, int z) {
		role = x;
		rank = y;
		age = z;
	}
};

//sister class

class SoB {
public:
	string rank;
	string name;
	int wounds;
	SoB(string x, string y, int z) {
		rank = x;
		name = y;
		wounds = z;
	}
};

//main function

int main() {
	spacemarine Titus("leader", "captain", 500);
	spacemarine Angelos("leader", "chaptermaster", 1000);
	SoB Celestine("Saint", "Celestine", 8);
	SoB Maria("battle sister", "Maria", 1);

	cout << Titus.role << " " << Titus.rank << " " << Titus.age << "\n";
	cout << Angelos.role << " " << Angelos.rank << " " << Angelos.age << "\n";
	cout << Celestine.rank << " " << Celestine.name << " " << Celestine.wounds << "\n";
}

