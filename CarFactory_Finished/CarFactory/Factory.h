#ifndef FACTORY_H_INCLUDED
#define FACTORY_H_INCLUDED
#include <iostream>
#include "Engine.h"
#include "Tires.h"
#include "Framework.h"
using namespace std;

typedef struct eleCar *adrCar;
struct Car{
    adrEngine carEngine;
    adrTire carTire;
    adrFK carFK;
    string name;
    int price;
};
struct eleCar{
    Car info;
    adrCar next;
    adrCar prev;
};
struct ListCar{
    adrCar firstCar;
};

void createListCar(ListCar &L);
bool isEmptyCar(ListCar L);
void addCar(ListCar &L, string name, adrEngine engine, adrTire tire, adrFK framework);
void deleteCar(ListCar &L, adrCar &P, string name);
void displayCar(ListCar L);
void viewCar(adrCar P);
void buildCar(ListCar &LC, ListEngine &LE, ListTire &LT, ListFK &LF);
adrCar findCar(ListCar L, string name);
adrCar findCarByEngine(ListCar L, string name);
adrCar findCarByFK(ListCar L, string name);
adrCar findCarByTire(ListCar L, string name);

#endif // FACTORY_H_INCLUDED
