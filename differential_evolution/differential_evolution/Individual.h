#pragma once
#include <vector>
#include <iostream>
#include <ctime>
#include <random>
#define PI 3.14159265358979323846
#define MERSENNE_MAX 4294967295.0 

double rosenbrock_function(std::vector<double> argument) {
	if (argument.size() == 2) {
		double x = argument[0];
		double y = argument[1];
		return pow((1 - x), 2) + 100 * pow((y - x * x), 2);
	}
	else
		throw - 1;
}
double icicle_function(std::vector<double> argument) {
	if (argument.size() == 2) {
		double x = argument[0];
		double y = argument[1];
		return (1 + sin(10*x) + cos(2*x) + cos(2*x + 2*y) + cos(2*y) + sin(20* y) + y*y);
	}
	else
		throw - 1;

}
double wt_function(std::vector<double> argument) {
	if (argument.size() == 2) {
		std::mt19937 mersenne(static_cast<unsigned int>(time(0)));

		double x = argument[0];
		double y = argument[1];
		double result = 0;
		double sum1 = 0, sum2 = 0;
		double A, B, C, D;
		for (int i = 1; i <= 7; i++) {
			for (int j = 1; j <= 7; j++) {
				A = i / (i * i + j * j) * 2 - 1;
				B = j / (i * i + j * j) * 2 - 1;
				C = i / (i * i + j * j) * 2 - 1;
				D = j / (i * i + j * j) * 2 - 1;
				sum1 += A * sin(i * PI * (x - 1 / 2)) * sin(j * PI * (y - 1 / 2)) + B * cos(i * PI * (x - 1 / 2)) * cos(j * PI * (y - 1 / 2));
				sum2 += C * sin(i * PI * (x - 1 / 2)) * sin(j * PI * (y - 1 / 2)) + D * cos(i * PI * (x - 1 / 2)) * cos(j * PI * (y - 1 / 2));
			}
		}
		return sqrt(sum1 * sum1 + sum2 * sum2);
	}
	else
		throw - 1;
}

class Individual
{
private:
	std::vector<double> genome;
	static double mutation_power;
	static double crossing_over_probability;
public:
	Individual();
	Individual(std::vector<double>);
	Individual(int);
	~Individual() {}

	bool operator== (const Individual&) const;
	bool operator!= (const Individual&) const;
	double& operator[] (int i);
	Individual& operator= (const Individual&);
	Individual operator+ (const Individual&) const;
	Individual operator- (const Individual&) const;
	Individual operator* (const double&) const;

	std::vector<double> toVectror();
	int getSize() const;
	static void setMutationPower(double);
	static double getMutationPower();
	static void setCrossingOverProbability(double);
	static double getCrossingOverProbability();


	Individual mutate(const Individual, const Individual) const;
	Individual breed(const Individual, std::vector<std::pair<double, double>>) const;

	friend std::ostream& operator<<(std::ostream& out, Individual _individual) {
		out << "(" << _individual[0];
		for (int i = 1; i < _individual.getSize(); i++)
			out << ", " << _individual[i];
		out << ")";
		return out;
	}
};

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

Individual Individual::breed(const Individual ind_mutated, std::vector<std::pair<double, double>> boundaries) const
{
	std::mt19937 mersenne(static_cast<unsigned int>(time(0)));

	Individual new_ind(getSize());
	for (int i = 0; i < getSize(); i++) {
		if ((mersenne() / MERSENNE_MAX) < crossing_over_probability)
			new_ind[i] = ind_mutated.genome[i];
		else
			new_ind[i] = genome[i];
		if (new_ind[i] > boundaries[i].second)
			new_ind[i] = boundaries[i].second;
		else if (new_ind[i] < boundaries[i].first)
			new_ind[i] = boundaries[i].first;
	}
	return new_ind;
}

double Individual::mutation_power = 0;
double Individual::crossing_over_probability = 0;