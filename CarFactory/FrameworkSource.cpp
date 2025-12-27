#include "Framework.h"

void createListFK(ListFK &L) {
    L.firstFK = nullptr;
}

bool isEmptyFK(ListFK L) {
    return L.firstFK == nullptr;
}

void addFK(ListFK &L) {
    adrFK P = new eleFK;

    cout << "\n=== Input Framework ===\n";
    cout << "Name          : ";
    cin >> P->info.name;
    cout << "Material      : ";
    cin >> P->info.material;
    cout << "Price         : ";
    cin >> P->info.price;

    P->next = nullptr;
    P->prev = nullptr;

    if (isEmptyFK(L)) {
        L.firstFK = P;
    } else {
        adrFK Q = L.firstFK;
        while (Q->next != nullptr) Q = Q->next;
        Q->next = P;
        P->prev = Q;
    }

    cout << "Framework added!\n";
}

void addFramework(ListFK &L, string name, string material, int price) {
    adrFK P = new eleFK;

    P->info.name = name;
    P->info.material = material;
    P->info.price = price;

    P->next = nullptr;
    P->prev = nullptr;

    if (isEmptyFK(L)) {
        L.firstFK = P;
    } else {
        adrFK Q = L.firstFK;
        while (Q->next != nullptr) Q = Q->next;
        Q->next = P;
        P->prev = Q;
    }

    cout << "Framework added!\n";
}

void deleteFK(ListFK &L, adrFK &P, adrFK framework){
    P = L.firstFK;
    adrFK temp, Q;

    if (isEmptyFK(L)) {
        cout << "No framework to delete.\n";
    }else{
        if(framework == nullptr){
            cout << "Framework with that name, Doesn't Exist!\n";
        }else{
            P = framework;

            if (P == L.firstFK && P->next == nullptr) {
                L.firstFK = nullptr;
            } else if (P == L.firstFK) {
                Q = P->next;
                L.firstFK = Q;
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
            cout << "Framework deleted!\n";
        }
    }
}

void displayFK(ListFK L) {
    if (isEmptyFK(L)) {
        cout << "No Framework Data.\n";
        return;
    }

    adrFK P = L.firstFK;
    cout << "\n=== Framework List ===\n";
    while (P != nullptr) {
        cout << "- " << P->info.name << " | Model: " << " | Material: " << P->info.material << " | Price: " << P->info.price << "\n";
        P = P->next;
    }
}

void buildFK(ListFK &L){
    addFramework(L, "Monoque", "Titanium", 15000000);
};

adrFK findFK(ListFK L, string name){
    adrFK p = L.firstFK;
    while(p != nullptr){
        if(p->info.name == name){
            return p;
        }
        p = p->next;
    }
    return nullptr;
};

