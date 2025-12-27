#ifndef FRAMEWORK_H_INCLUDED
#define FRAMEWORK_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct eleFK *adrFK;
struct Framework{
    string name;
    string material;
    int price;
};
struct eleFK{
    Framework info;
    adrFK prev;
    adrFK next;
};
struct ListFK{
    adrFK firstFK;
};

void createListFK(ListFK &L);
bool isEmptyFK(ListFK L);
void addFramework(ListFK &L, string name, string material, int price);
void deleteFK(ListFK &L, adrFK &P, adrFK framework);
void displayFK(ListFK L);
void buildFK(ListFK &L);
adrFK findFK(ListFK L, string name);

#endif // FRAMEWORK_H_INCLUDED
