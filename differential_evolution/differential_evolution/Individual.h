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
double horrific_function(std::vector<double> argument) {
	if (argument.size() == 2) {
		double x = argument[0];
		double y = argument[1];
		double result = 0;
		double sum1 = 0, sum2 = 0;
		double A, B, C, D;

		std::vector<std::vector<double>> A_matrix = { {-0.940, -0.536, -0.743}, {-0.502,  0.804,  0.769}, {-0.428, -0.789,  0.204} };
		std::vector<std::vector<double>> B_matrix = { { 0.590,  0.160, -0.681}, { 0.387,  0.945, -0.195}, {-0.231,  0.152,  0.295} };
		std::vector<std::vector<double>> C_matrix = { {-0.896, -0.613, -0.463}, { 0.038, -0.428, -0.714}, { 0.103,  0.741, -0.317} };
		std::vector<std::vector<double>> D_matrix = { {-0.754, -0.558, -0.989}, {-0.702,  0.881,  0.397}, {-0.056,  0.085, -0.616} };

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				A = A_matrix[i][j];
				B = B_matrix[i][j];
				C = C_matrix[i][j];
				D = D_matrix[i][j];
				sum1 += A * sin(i * PI * (x - 1 / 2)) * sin(j * PI * (y - 1 / 2)) + B * cos(i * PI * (x - 1 / 2)) * cos(j * PI * (y - 1 / 2));
				sum2 += C * sin(i * PI * (x - 1 / 2)) * sin(j * PI * (y - 1 / 2)) + D * cos(i * PI * (x - 1 / 2)) * cos(j * PI * (y - 1 / 2));
			}
		}
		return sqrt(sum1 * sum1 + sum2 * sum2);
	}
	else
		throw - 1;
}
/*
double food_integral(double x, double C_1, double sigma_1) {
	return sigma_1 * (tanh(x + C_1) + 1);
}
double beta_integral(double x, double beta, double sigma_1) {
	return beta * x * x;
}
double plancton_function(std::vector<double> argument) {
	double C = 140;
	double C_0 = 60;
	double C_1 = 40;
	double sigma_1 = 15;
	double sigma_2 = 0.4;
	double ksi = 5e-19;
	double alpha = 0.0012;
	double gamma = 1;
	double betta = 7.5e-8;
	double delta = 0.2;
	double epsilon = 0.013;
}
*/

class Individual
{
private:
	std::vector<double> genome;
public:
	Individual();
	Individual(const Individual&);
	Individual(std::vector<double>);
	Individual(int);
	~Individual() {}

	bool operator== (const Individual&) const;
	bool operator!= (const Individual&) const;
	double& operator[] (int i);
	std::vector<double> toVector();
	Individual& operator= (const Individual&);
	Individual operator+ (const Individual&) const;
	Individual operator- (const Individual&) const;
	Individual operator* (const double&) const;

	int getSize() const;

	Individual mutate(const Individual, const Individual, const double) const;
	Individual breed(const Individual, const double, const std::vector<std::pair<double, double>>) const;

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

inline Individual::Individual(const Individual& ind)
{
	genome = ind.genome;
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

inline std::vector<double> Individual::toVector()
{
	return genome;
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

int Individual::getSize() const
{
	return genome.size();
}

Individual Individual::mutate(const Individual ind_a, const Individual ind_b, const double mutation_power) const
{
	Individual new_ind(genome);
	new_ind = new_ind + (ind_a - ind_b) * mutation_power;
	return new_ind;
}

Individual Individual::breed(const Individual ind_mutated, const double crossing_over_probability, std::vector<std::pair<double, double>> boundaries) const
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