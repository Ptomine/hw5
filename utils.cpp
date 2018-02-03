#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

#include "Complex.h"

std::vector<Complex> vectorFromFile(const char* const path) {
	std::vector<Complex> tmpVector;
	std::ifstream fin;
	fin.open(path, std::ios::in);
	while(!fin.eof()) {
		float real = 0.F;
		float imaginary = 0.F;
		fin >> real >> imaginary;
		Complex tmpComplex(real, imaginary);
		tmpVector.insert(tmpVector.end(), tmpComplex);
	}
	fin.close();
	return tmpVector;
}
std::vector<Complex> sumVector(std::vector<Complex> fVector, std::vector<Complex> sVector) {
	std::vector<Complex> sum;
	if(fVector.size() != sVector.size()) {
		throw std::invalid_argument("Vectors shold be of equal size.");
	}
	for(int i = 0; i < fVector.size(); i++) {
		Complex tmpSum;
		tmpSum = fVector[i] + sVector[i];
		sum.insert(sum.end(), tmpSum);
	}
	return sum;
}