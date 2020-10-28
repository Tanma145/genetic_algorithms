#include <conio.h>
#include <cmath>
#include <list>
#include "Generation.h"

using namespace std;

int main() {
	try {
		std::list<Generation> species;
		int genome_size, generation_size;
		cout << "Enter the size of a genome: ";
		cin >> genome_size;

		vector<pair<double, double>> bounds(genome_size);
		for (int i = 0; i < genome_size; i++) {
			cout << "Enter min and max values for gene " << i << ": ";
			cin >> bounds[i].first >> bounds[i].second;
		}
		Generation::setBoundaries(bounds);

		cout << "Enter the size of a generation: ";
		cin >> generation_size;
		Generation origin(generation_size, genome_size);
		species.push_back(origin);
		cout << origin << endl;

		double mutation_power, crossing_over_probability;
		cout << "Enter mutation power: ";
		cin >> mutation_power;
		Individual::setMutationPower(mutation_power);
		cout << "Enter crossing-over probability: ";
		cin >> crossing_over_probability;
		Individual::setCrossingOverProbability(crossing_over_probability);

		Generation new_generation = origin;
		bool flag = true;
		while (flag) {
			new_generation = new_generation.createNewGeneation(rosenbrock_function);
			species.push_back(new_generation);
			cout << new_generation << endl << endl << "Continue? " << endl << endl;
			cin >> flag;	
		}
	}
	catch (int error) {
		cout << "OOF";
	}
}