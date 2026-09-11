//t

#include <iostream>
#include <string>
using namespace std;

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

int main() {
	spacemarine Titus("leader", "captain", 500);
	spacemarine Angelos("leader", "chaptermaster", 1000);

	cout << Titus.role << " " << Titus.rank << " " << Titus.age << "\n";
	cout << Angelos.role << " " << Angelos.rank << " " << Angelos.age << "\n";
}

