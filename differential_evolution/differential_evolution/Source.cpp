#include <conio.h>
#include <cmath>
#include <list>
#include <iomanip>
#include "DifferentialEvolution.h"

using namespace std;

int main() {
	try {
		int flag;
		double (*objective_function)(vector<double>);
		objective_function = rosenbrock_function;
		cout << "What function would you like to minimize?"  << endl;
		cout << "1 - Rosenbrock function" << endl;
		cout << "2 - Icicle function" << endl;
		cout << "3 - Horrific function" << endl << endl;
		cin >> flag;
		switch (flag) {
		case 1:
			objective_function = rosenbrock_function;
			break;
		case 2:
			objective_function = icicle_function;
			break;
		case 3:
			objective_function = horrific_function;
			break;
		}

		vector<pair<double, double>> boundaries(2);
		for (int i = 0; i < 2; i++) {
			cout << "Enter minimum and maximum value for x_" << i + 1 << endl;
			cin >> boundaries[i].first >> boundaries[i].second;
		}

		double epsilon;
		cout << "Enter epsilon" << endl;
		cin >> epsilon;

		vector<double> fittest;
		fittest = DifferentialEvolution::minimize_iter(objective_function, boundaries, 1000);

		cout << setprecision(16);
		cout << "Fittest: (" << fittest[0] << "; " << fittest[1] << ")";
		_getch();
	}
	catch (int error) {
		cout << "OOF";
	}
}