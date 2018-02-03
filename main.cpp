#include <iostream>
#include <vector>

#include "Complex.h"
#include "utils.h"

int main( const int argc, const char* argv[]) {
	if( argc != 3) {
		std::cout << "Wrong arguments." << std::endl;
		return -1;
	}
	try {
		std::vector<Complex> firstVector = vectorFromFile(argv[1]);
		std::vector<Complex> secondVector = vectorFromFile(argv[2]);
		std::cout << "1st:" << std::endl;
		for(int i = 0; i < firstVector.size(); i++) {
			std::cout << firstVector[i] << std::endl;
		}
		std::cout << "2nd:" << std::endl;
		for(int i = 0; i < secondVector.size(); i++) {
			std::cout << secondVector[i] << std::endl;
		}	
		std::vector<Complex> sVector; 
		sVector = sumVector(firstVector, secondVector);
		std::cout << "sum:" << std::endl;
		for(int i = 0; i < sVector.size(); i++) {
			std::cout << sVector[i] << std::endl;
		}
	}	
	catch(const std::exception& e) {
		std::cout << "ERROR: " << e.what() << std::endl;
	}
	catch(...) {
		std::cout << "ERROR: unknown exception.";
	}	
	return 0;
}