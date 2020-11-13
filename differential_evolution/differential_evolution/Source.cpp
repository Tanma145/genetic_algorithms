#include <conio.h>
#include <cmath>
#include <list>
#include <iomanip>
#include <ctime>
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
		int n;
		cout << "Enter number of iterations" << endl;
		cin >> n;

		vector<double> fittest;
		clock_t start = clock();
		fittest = DifferentialEvolution::minimize_iter(objective_function, boundaries, n);
		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "-";

		cout << setprecision(16) << "Minimum: (" << fittest[0] << "; " << fittest[1] << ")" << endl;
		cout << "Time: " << seconds;
		_getch();
	}
	catch (int error) {
		cout << "OOF";
	}
}