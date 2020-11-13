#pragma once
#include "Generation.h"
class DifferentialEvolution
{
private:
	static double population_size;
	static double mutation_power;
	static double crossover_probability;
public:
	static std::vector<double> minimize(double function(std::vector<double>), std::vector<std::pair<double, double>> boundaries, double epsilon);
	static std::vector<double> minimize_iter(double function(std::vector<double>), std::vector<std::pair<double, double>> boundaries, int n);
};

double DifferentialEvolution::population_size = 200;
double DifferentialEvolution::mutation_power = 0.5;
double DifferentialEvolution::crossover_probability = 0.95;

std::vector<double> DifferentialEvolution::minimize(double function(std::vector<double>), std::vector<std::pair<double, double>> boundaries, double epsilon)
{
	Generation::setBoundaries(boundaries);
	Generation generation(population_size, boundaries.size(), mutation_power, crossover_probability);
	while (generation.getRange() > epsilon) {
		std::cout << " - " << generation.getRange() << std::endl;
		Generation new_generation = generation.createNewGeneation(function);
		generation = new_generation;
	}
	return generation.getFittest(function).toVector();
}
std::vector<double> DifferentialEvolution::minimize_iter(double function(std::vector<double>), std::vector<std::pair<double, double>> boundaries, int n)
{
	Generation::setBoundaries(boundaries);
	Generation generation(population_size, boundaries.size(), mutation_power, crossover_probability);
	for (int i = 0; i < n; i++)
	{
		//std::cout << i << " - " << generation.getRange() << std::endl;
		Generation new_generation = generation.createNewGeneation(function);
		generation = new_generation;
	}
	return generation.getFittest(function).toVector();
}