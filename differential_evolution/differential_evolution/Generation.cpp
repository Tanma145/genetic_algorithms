#include "Generation.h"
#include <random>

/*
Generation::Generation()
{
	std::vector<double> ind = { 0 };
	generation = { ind };
}

Generation::Generation(int generation_size, int genome_size)
{
	std::mt19937 mersenne(static_cast<unsigned int>(time(0)));

	std::vector<Individual> _generation(generation_size);
	for (int i = 0; i < generation_size; i++) 
	{
		Individual _individual(genome_size);
		for (int j = 0; j < genome_size; j++) 
		{
			_individual[j] = (mersenne() / MERSENNE_MAX) * (boundaries[j].second - boundaries[j].first) + boundaries[j].first;
		}
		_generation[i] = _individual;
	}
	generation = _generation;
}

Generation::Generation(std::vector<Individual> _generation)
{
	generation = _generation;
}

Generation::Generation(const Generation& _generation)
{
	generation = _generation.generation;
}

Individual& Generation::operator[](int i)
{
	return generation[i];
}

void Generation::setBoundaries(std::vector<std::pair<double, double>> _boundaries)
{
	boundaries = _boundaries;
}

Generation Generation::createNewGeneation(double objective_function(std::vector<double>))
{
	std::mt19937 mersenne(static_cast<unsigned int>(time(0)));

	Generation new_generation(*this);

	Individual parent_normal(generation[0].getSize());
	Individual parent_mutated(generation[0].getSize());
	Individual child(generation[0].getSize());
	Individual mutagen_1(generation[0].getSize());
	Individual mutagen_2(generation[0].getSize());

	for (int i = 0; i < generation.size(); i++) {
		parent_normal = generation[i];

		do {
			parent_mutated = generation[mersenne() / MERSENNE_MAX * generation.size()];
		} while (parent_mutated == parent_normal);
		do {
			mutagen_1 = generation[mersenne() / MERSENNE_MAX * generation.size()];
		} while (mutagen_1 == parent_mutated || mutagen_1 == parent_normal);
		do {
			mutagen_2 = generation[mersenne() / MERSENNE_MAX * generation.size()];
		} while (mutagen_2 == parent_mutated || mutagen_2 == parent_normal || mutagen_2 == mutagen_1);

		parent_mutated = parent_mutated.mutate(mutagen_1, mutagen_2);

		child = parent_normal.breed(parent_mutated);
		if (objective_function(child.toVectror()) < objective_function(parent_normal.toVectror())) {
			new_generation[i] = child;
		}
	}
	return new_generation;
}
*/