#pragma once
#ifndef ENGINE
#define ENGINE
#include <vector>
#include <cmath>
#include <vector>
#include <iostream>
#include "typeOfEngins.h"

class Engine{
public:
	EngineType type = NonType;
	double time_run = 0;//����� ��������� ���������
	double time_dif = 0.1;
	double inert_moment = 0.1;//������ �������
	double temp_overheat = 110;//����������� ���������
	double temp_engine = 35;//������� ����������� ���������
	std::vector<int> torque = { 20, 75, 100, 105, 75, 0 };//�������� ������
	std::vector<int> crank_rotation_speed = { 0, 75, 150, 200, 250, 300 };//�������� �������� ���������
	double crank_speed = crank_rotation_speed[0];
	double coef_of_heat_vers_torque = 0.01;//����������� ����������� �������� ������� �� ��������� �������
	double coef_of_heat_vers_crank = 0.001;//����������� ����������� �������� ������� �� �������� �������� ���������
	double coef_of_heat_vers_temp = 0.1;//����������� ����������� �������� ���������� �� ����������� ��������� � ���������� �����
	Engine();
	Engine(double inert_moment, double temp_overheat, std::vector<int> torque, std::vector<int>crank_rotation_speed,double coef_of_heat_vers_torque, double coef_of_heat_vers_crank, double coef_of_heat_vers_temp,EngineType type);
	void Simulation(double temp_outside, EngineType type);
private:
	int cur_pos = 0;
	double speedOfHeating();
	double speedOfCalming(double temp_calm);
	double acceleration();
};

#endif