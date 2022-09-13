/*
Файл для описания методов класса Engine
*/

#include "engine.h"

#define ABSOLUTE_ERROR 0.001//допустимая погрешность
#define MAX_TIME 1200//максимальное время симуляции

Engine::Engine() {}

Engine::Engine(double inert_moment, double temp_overheat, std::vector<int> torque, std::vector<int> crank_rotation_speed,
		double coef_of_heat_vers_torque, double coef_of_heat_vers_crank, double coef_of_heat_vers_temp,
		EngineType type) {//конструктор экземпляра класса
	this->inert_moment = inert_moment;
	this->temp_overheat = temp_overheat;
	this->torque = torque;
	this->crank_rotation_speed = crank_rotation_speed;
	this->coef_of_heat_vers_torque = coef_of_heat_vers_torque;
	this->coef_of_heat_vers_crank = coef_of_heat_vers_crank;
	this->coef_of_heat_vers_temp = coef_of_heat_vers_temp;
	this->type = type;
}

void Engine::Simulation(double temp_outside, EngineType type) {//Функция запускающая симуляцию работы двигателя
	double eps = (this->temp_overheat - this->temp_engine);
	while (eps > ABSOLUTE_ERROR && this->time_run<MAX_TIME) {
		this->time_run += this->time_dif;
		this->crank_speed += acceleration() * this->time_dif;
		if ((this->cur_pos < this->torque.size() - 2) && (this->crank_speed < this->crank_rotation_speed[this->cur_pos + 1]))
			this->cur_pos++;
		this->temp_engine += (speedOfHeating() - speedOfCalming(temp_outside))*this->time_dif;
		eps = (this->temp_overheat - this->temp_engine);
	}
}

double Engine::speedOfHeating(){//Функция для расчета скорости нагрева двигателя
	return this->torque[this->cur_pos] * this->coef_of_heat_vers_torque + 
		pow(this->crank_rotation_speed[this->cur_pos], 2) * this->coef_of_heat_vers_crank;
}

double Engine::speedOfCalming(double temp_calm){//Функция для расчета скорости охлаждения двигателя
	return this->coef_of_heat_vers_temp * (this->temp_engine - temp_calm);
}

double Engine::acceleration() {//Функция для расчета ускорения оборотов коленвала
	return this->torque[this->cur_pos] * this->inert_moment;
}