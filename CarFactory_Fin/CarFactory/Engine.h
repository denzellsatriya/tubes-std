#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct eleEngine *adrEngine;
struct Engine{
    string name;
    int horsepower;
    string fuel;
    int price;
};
struct eleEngine{
    Engine info;
    adrEngine prev;
    adrEngine next;
};
struct ListEngine{
    adrEngine firstEngine;
};

void createListEngine(ListEngine &L);
bool isEmptyEngine(ListEngine L);
void addEngine(ListEngine &L, string name, int HP, string fuel, int price);
void deleteEngine(ListEngine &L, adrEngine &P, string engine);
void displayEngine(ListEngine L);
void buildEngine(ListEngine &L);
adrEngine findEngine(ListEngine L, string name);


#endif // ENGINE_H_INCLUDED
