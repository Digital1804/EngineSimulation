/*
Вспомогательная библиотека для ввода вывода данных
*/
#include "in_out.h"

double readOutsideTemprature() {//Функция для ввода температуры окружающей среды
	std::cout << "Please, input outside temprature: ";
	double temprature;
	std::cin >> temprature;
	return temprature;
}

void outputTime(double time) {//Функция для вывода вреиени симуляции
	std::cout << "Engine overheating time: " << time << " seconds.\n";
}