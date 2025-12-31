#ifndef TIRE_H_INCLUDED
#define TIRE_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct eleTire *adrTire;

struct Tire {
    string name;
    string size;
    string type;
    int price;
};

struct eleTire {
    Tire info;
    adrTire prev;
    adrTire next;
};

struct ListTire {
    adrTire firstTire;
};

void createListTire(ListTire &L);
bool isEmptyTire(ListTire L);
void addTire(ListTire &L, string name, string size, string type, int price);
void deleteTire(ListTire &L, adrTire &P, string tire);
void displayTire(ListTire L);
void buildTire(ListTire &L);
adrTire findTire(ListTire L, string name);

#endif

