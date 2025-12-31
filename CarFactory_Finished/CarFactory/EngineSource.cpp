#include "Engine.h"

void createListEngine(ListEngine &L) {
    L.firstEngine = nullptr;
}

bool isEmptyEngine(ListEngine L) {
    return L.firstEngine == nullptr;
}

void addEngine(ListEngine &L, string name, int HP, string fuel, int price) {
    adrEngine P = new eleEngine;

    P->info.name = name;
    P->info.horsepower = HP;
    P->info.fuel = fuel;
    P->info.price = price;

    P->next = nullptr;
    P->prev = nullptr;

    if (isEmptyEngine(L)) {
        L.firstEngine = P;
    } else {
        adrEngine Q = L.firstEngine;
        while (Q->next != nullptr) Q = Q->next;
        Q->next = P;
        P->prev = Q;
    }
}

void deleteEngine(ListEngine &L, adrEngine &P, string name){
    P = L.firstEngine;
    adrEngine temp, Q;

    if (isEmptyEngine(L)) {
        cout << "No engine to delete.\n";
    }else{
        if(findEngine(L, name) == nullptr){
            cout << "Engine with the name " << name << ", doesn't exist!\n";
        }else{
            P = findEngine(L, name);

            if (P == L.firstEngine && P->next == nullptr) {
                L.firstEngine = nullptr;
            } else if (P == L.firstEngine) {
                Q = P->next;
                L.firstEngine = Q;
                P->next = nullptr;
                Q->prev = nullptr;
            } else if (P->next == nullptr) {
                Q = P->prev;
                Q->next = nullptr;
                P->prev = nullptr;
            } else {
                Q = P->prev;
                temp = P->next;
                Q->next = temp;
                temp->prev = Q;
                P->prev = nullptr;
                P->next = nullptr;
            }
            cout << "Engine deleted!\n";
        }
    }
}

void displayEngine(ListEngine L) {
    if (isEmptyEngine(L)) {
        cout << "No Engine Data.\n";
        return;
    }

    adrEngine P = L.firstEngine;
    cout << "\n========== Engine List ==========\n";
    while (P != nullptr) {
        cout << "- " << P->info.name << " | HP: " << P->info.horsepower
             << " | Fuel: " << P->info.fuel << " | Price: " << P->info.price << "\n";
        P = P->next;
    }
}

void buildEngine(ListEngine &L){
    addEngine(L, "Turbo", 300, "Bensin", 900000000);
    addEngine(L, "Tesla_M-Y", 200, "Listrik", 500000000);
}

adrEngine findEngine(ListEngine L, string name){
    adrEngine p = L.firstEngine;
    while(p != nullptr){
        if(p->info.name == name){
            return p;
        }
        p = p->next;
    }
    return nullptr;
};

