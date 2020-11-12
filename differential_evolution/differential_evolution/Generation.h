#pragma once
#include "Individual.h"
#include <utility>

class Generation
{
private:
	std::vector<Individual> generation;
	static std::vector<std::pair<double, double>> boundaries;
	double range;
	double mutation_power;
	double crossover_probability;
public:
	Generation();
	Generation(int, int, double, double);
	Generation(std::vector<Individual>);
	Generation(const Generation&);
	~Generation() {}

	void setMutationPower(double);
	void setCrossoverProbablity(double);
	double getRange();
	Individual& operator[] (int i);
	Individual getFittest(double fitness(std::vector<double>));
	Generation& operator= (const Generation&);
	
	static void setBoundaries(std::vector<std::pair<double, double>>);

	Generation createNewGeneation(double objective_function(std::vector<double>));

	friend std::ostream& operator<<(std::ostream& out, Generation _generation) {
		for (int i = 0; i < _generation.generation.size(); i++)
			out << _generation.generation[i] << std::endl;
		return out;
	}
};

Generation::Generation()
{
	std::vector<double> ind = { 0 };
	generation = { ind };
	mutation_power = 0;
	crossover_probability = 0;
}

Generation::Generation(int generation_size, int genome_size, double mp = 0, double cp = 0)
{
	std::mt19937 mersenne(static_cast<unsigned int>(time(0)));
	mutation_power = mp;
	crossover_probability = cp;
	range = 0;
	std::vector<double> max(genome_size);
	std::vector<double> min(genome_size);
	for (int i = 0; i < genome_size; i++) 
	{
		min[i] = boundaries[i].second;
		max[i] = boundaries[i].first;
	}

	std::vector<Individual> _generation(generation_size);
	for (int i = 0; i < generation_size; i++)
	{
		Individual _individual(genome_size);
		for (int j = 0; j < genome_size; j++)
		{
			_individual[j] = (mersenne() / MERSENNE_MAX) * (boundaries[j].second - boundaries[j].first) + boundaries[j].first;
			if (_individual[j] > max[j])
				max[j] = _individual[j];
			if (_individual[j] < min[j])
				min[j] = _individual[j];
			if ((max[j] - min[j]) > range)
				range = max[j] - min[j];
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
	range = _generation.range;
	mutation_power = _generation.mutation_power;
	crossover_probability = _generation.crossover_probability;
}

inline void Generation::setMutationPower(double mp)
{
	mutation_power = mp;
}

inline void Generation::setCrossoverProbablity(double cp)
{
	crossover_probability = cp;
}

inline double Generation::getRange()
{
	return range;
}

Individual& Generation::operator[](int i)
{
	return generation[i];
}

Individual Generation::getFittest(double fitness(std::vector<double>))
{
	Individual fit(generation[0]);
	for (int i = 0; i < generation.size(); i++) {
		if (fitness(generation[i].toVector()) < fitness(fit.toVector()))
			fit = generation[i];
	}
	return fit;
}

inline Generation& Generation::operator=(const Generation& _generation)
{
	generation = _generation.generation;
	range = _generation.range;
	mutation_power = _generation.mutation_power;
	crossover_probability = _generation.crossover_probability;
	return *this;
}

void Generation::setBoundaries(std::vector<std::pair<double, double>> _boundaries)
{
	boundaries = _boundaries;
}
//œ–Œ¬≈–»“‹ –¿ÕƒŒÃ ¬ ›“Œ… ‘”Õ ÷»»
Generation Generation::createNewGeneation(double objective_function(std::vector<double>))
{
	std::mt19937 mersenne(static_cast<unsigned int>(time(0)));

	Generation new_generation(*this);

	Individual parent_normal(generation[0].getSize());
	Individual parent_mutated(generation[0].getSize());
	Individual child(generation[0].getSize());
	Individual mutagen_1(generation[0].getSize());
	Individual mutagen_2(generation[0].getSize());

	new_generation.range = 0;
	std::vector<double> max(generation[0].getSize());
	std::vector<double> min(generation[0].getSize());
	for (int i = 0; i < generation[0].getSize(); i++)
	{
		min[i] = boundaries[i].second;
		max[i] = boundaries[i].first;
	}

	for (int i = 0; i < generation.size(); i++) {
		parent_normal = generation[i];

		do {
			parent_mutated = generation[mersenne() / MERSENNE_MAX * (generation.size() - 1)];
		} while (parent_mutated == parent_normal);
		do {
			mutagen_1 = generation[mersenne() / MERSENNE_MAX * (generation.size() - 1)];
		} while (mutagen_1 == parent_mutated || mutagen_1 == parent_normal);
		do {
			mutagen_2 = generation[mersenne() / MERSENNE_MAX * (generation.size() - 1)];
		} while (mutagen_2 == parent_mutated || mutagen_2 == parent_normal || mutagen_2 == mutagen_1);

		parent_mutated = parent_mutated.mutate(mutagen_1, mutagen_2, mutation_power);

		child = parent_normal.breed(parent_mutated, crossover_probability, boundaries);
		if (objective_function(child.toVector()) < objective_function(parent_normal.toVector())) {
			new_generation[i] = child;
		}
		//range
		for (int j = 0; j < generation[0].getSize(); j++) {
			if (new_generation[i][j] > max[j])
				max[j] = new_generation[i][j];
			if (new_generation[i][j] < min[j])
				min[j] = new_generation[i][j];
			if ((max[j] - min[j]) > new_generation.range)
				new_generation.range = max[j] - min[j];
		}
	}
	return new_generation;
}

std::vector<std::pair<double, double>> Generation::boundaries = { {0, 0} };