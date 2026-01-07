#include "Tires.h"

void createListTire(ListTire &L) {
    L.firstTire = nullptr;
}

bool isEmptyTire(ListTire L) {
    return L.firstTire == nullptr;
}

void addTire(ListTire &L, string name, string size, string type, int price) {
    adrTire P = new eleTire;

    P->info.name = name;
    P->info.size = size;
    P->info.type = type;
    P->info.price = price;

    P->next = nullptr;
    P->prev = nullptr;

    if (isEmptyTire(L)) {
        L.firstTire = P;
    } else {
        adrTire Q = L.firstTire;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
        P->prev = Q;
    }
}

void deleteTire(ListTire &L, adrTire &P, string name){
    P = L.firstTire;
    adrTire temp, Q;

    if (isEmptyTire(L)) {
        cout << "No tire to delete.\n";
    }else{
        if(findTire(L, name) == nullptr){
            cout << "Tire with the name " << name << ", doesn't exist!\n";
        }else{
            P = findTire(L, name) ;

            if (P == L.firstTire && P->next == nullptr) {
                L.firstTire = nullptr;
            } else if (P == L.firstTire) {
                Q = P->next;
                L.firstTire = Q;
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
            cout << "Tire deleted!\n";
        }
    }
}

void displayTire(ListTire L) {
    if (isEmptyTire(L)) {
        cout << "No Tire Data.\n";
        return;
    }

    adrTire P = L.firstTire;
    cout << "\n========== Tire List ==========\n";
    while (P != nullptr) {
        cout << "- " << P->info.name << " | Size: " << P->info.size
             << " | Type: " << P->info.type << " | Price: " << P->info.price << "\n";
        P = P->next;
    }
}

void buildTire(ListTire &L){
    addTire(L, "Pirelli", "R15", "Premium", 5900000);
    addTire(L, "Yokohama", "R13", "Economy", 18500000);
};

adrTire findTire(ListTire L, string name){
    adrTire p = L.firstTire;
    while(p != nullptr){
        if(p->info.name == name){
            return p;
        }
        p = p->next;
    }
    return nullptr;
};
