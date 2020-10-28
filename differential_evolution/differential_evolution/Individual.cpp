#include "Individual.h"
#include <random>

/*
Individual::Individual()
{
	genome = { 0 };
}

Individual::Individual(std::vector<double> _genome)
{
	genome = _genome;
}

Individual::Individual(int size)
{
	std::vector<double> _genome(size);
	genome = _genome;
}

bool Individual::operator==(const Individual& ind) const
{
	return genome == ind.genome;
}

bool Individual::operator!=(const Individual& ind) const
{
	return genome != ind.genome;
}

double& Individual::operator[](int i)
{
	if (i < getSize())
		return genome[i];
	else
		throw - 1;
}

Individual& Individual::operator=(const Individual& ind) 
{
	genome = ind.genome;
	return *this;
}

Individual Individual::operator+(const Individual& ind) const
{
	if (getSize() == ind.getSize()) {
		Individual new_ind(genome);
		for (int i = 0; i < getSize(); i++) {
			new_ind.genome[i] += ind.genome[i];
		}
		return new_ind;
	}
	else
		throw - 1;
}

Individual Individual::operator-(const Individual& ind) const
{
	if (getSize() == ind.getSize()) {
		Individual new_ind(genome);
		for (int i = 0; i < getSize(); i++) {
			new_ind.genome[i] -= ind.genome[i];
		}
		return new_ind;
	}
	else
		throw - 1;
}

Individual Individual::operator*(const double& scalar) const
{
	Individual new_ind(genome);
	for (int i = 0; i < getSize(); i++) {
		new_ind.genome[i] *= scalar;
	}
	return new_ind;
}

std::vector<double> Individual::toVectror()
{
	return genome;
}

int Individual::getSize() const
{
	return genome.size();
}

void Individual::setMutationPower(double mp)
{
	mutation_power = mp;
}

double Individual::getMutationPower()
{
	return mutation_power;
}

void Individual::setCrossingOverProbability(double cop)
{
	crossing_over_probability = cop;
}

double Individual::getCrossingOverProbability()
{
	return crossing_over_probability;
}

Individual Individual::mutate(const Individual ind_a, const Individual ind_b) const
{
	Individual new_ind(genome);
	new_ind = new_ind + (ind_a - ind_b) * getMutationPower();
	return new_ind;
}

Individual Individual::breed(const Individual ind_mutated) const
{
	std::mt19937 mersenne(static_cast<unsigned int>(time(0)));

	Individual new_ind(getSize());
	for (int i = 0; i < getSize(); i++) {
		if ((mersenne() / MERSENNE_MAX) < crossing_over_probability) 
			new_ind.genome[i] = ind_mutated.genome[i];
		else
			new_ind.genome[i] = genome[i];
	}
	return new_ind;
}
*/
