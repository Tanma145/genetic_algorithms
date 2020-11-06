#include <conio.h>
#include <cmath>
#include <list>
#include "Generation.h"

using namespace std;

int main() {
	try {
		std::mt19937 mersenne(static_cast<unsigned int>(time(0)));
		vector<double> v(3);
		for (int k = 0; k < 4; k++) {
			for (int j = 0; j < 3; j++) {
				for (int i = 0; i < v.size(); i++) {
					v[i] = (mersenne() / MERSENNE_MAX) * 2 - 1;
					cout.precision(3);
					cout << v[i] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

	}
	catch (int error) {
		cout << "OOF";
	}
}