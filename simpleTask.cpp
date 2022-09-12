// simpleTask.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "in_out.h"
#include "engine.h"

int main(){
	double outsideTemprature = readOutsideTemprature();
	Engine engine1;
	engine1.type = InternalCombucstionEngine;
	engine1.Simulation(outsideTemprature, engine1.type);
	outputTime(engine1.time_run);
}
