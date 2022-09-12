#include "in_out.h"

double readOutsideTemprature() {
	std::cout << "Please, input outside temprature: ";
	double temprature;
	std::cin >> temprature;
	return temprature;
}

void outputTime(double time) {
	std::cout << "Engine overheating time: " << time << " seconds.\n";
}