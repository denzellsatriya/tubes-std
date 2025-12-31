#include "Factory.h"

void createListCar(ListCar &L) {
    L.firstCar = nullptr;
}

bool isEmptyCar(ListCar L) {
    return L.firstCar == nullptr;
}

void addCar(ListCar &L, string name, adrEngine engine, adrTire tire, adrFK framework) {
    adrCar P = new eleCar;

    P->info.name = name;
    P->info.carEngine = engine;
    P->info.carTire = tire;
    P->info.carFK = framework;
    P->info.price = engine->info.price +
                    tire->info.price +
                    framework->info.price;
    P->next = nullptr;
    P->prev = nullptr;

    if (isEmptyCar(L)) {
        L.firstCar = P;
    } else {
        adrCar Q = L.firstCar;
        while (Q->next != nullptr) Q = Q->next;
        Q->next = P;
        P->prev = Q;
    }
}

void deleteCar(ListCar &L, adrCar &P, string name){
    P = L.firstCar;
    adrCar temp, Q;

    if (isEmptyCar(L)) {
        cout << "No car to delete.\n";
    }else{
        if(findCar(L, name) == nullptr){
            cout << "Car with the name " << name << ", doesn't exist!\n";
        }else{
            P = findCar(L, name) ;

            if (P == L.firstCar && P->next == nullptr) {
                L.firstCar = nullptr;
            } else if (P == L.firstCar) {
                Q = P->next;
                L.firstCar = Q;
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
            cout << "Car deleted!\n";
        }
    }
}

void displayCar(ListCar L) {
    if (isEmptyCar(L)) {
        cout << "\nNo Car Data.\n";
        return;
    }

    adrCar P = L.firstCar;
    cout << "\n========== Car List ==========\n";
    while (P != nullptr) {
        cout << "- " << P->info.name
             << " | Engine: " << P->info.carEngine->info.name
             << " | Tire: " << P->info.carTire->info.name
             << " | Framework: " << P->info.carFK->info.name
             << " | Total Price: " << P->info.price
             << "\n";
        P = P->next;
    }
}

void viewCar(adrCar P){
    cout << "- " << P->info.name
         << "\n Engine: " << P->info.carEngine->info.name
            << " | HP: " << P->info.carEngine->info.horsepower
            << " | Fuel: " << P->info.carEngine->info.fuel
            << " | Price: " << P->info.carEngine->info.price
         << "\n Tire: " << P->info.carTire->info.name
            << " | Size: " << P->info.carTire->info.size
            << " | Type: " << P->info.carTire->info.type
            << " | Price: " << P->info.carTire->info.price
         << "\n Framework: " << P->info.carFK->info.name
            << " | Material: " << P->info.carFK->info.material
            << " | Price: " << P->info.carFK->info.price
         << "\n Total Price: " << P->info.price
         << "\n";
}

void buildCar(ListCar &LC, ListEngine &LE, ListTire &LT, ListFK &LF){
    buildFK(LF);
    buildEngine(LE);
    buildTire(LT);

    addCar(LC, "Red_Car", findEngine(LE, "Turbo"), findTire(LT, "Pirelli"), findFK(LF, "Monoque"));
};

adrCar findCar(ListCar L, string name){
    adrCar p = L.firstCar;
    while(p != nullptr){
        if(p->info.name == name){
            return p;
        }
        p = p->next;
    }
    return nullptr;
};

adrCar findCarByEngine(ListCar L, string name){
    adrCar p = L.firstCar;
    while(p != nullptr){
        if(p->info.carEngine->info.name == name){
            return p;
        }
        p = p->next;
    }
    return nullptr;
};

adrCar findCarByFK(ListCar L, string name){
    adrCar p = L.firstCar;
    while(p != nullptr){
        if(p->info.carFK->info.name == name){
            return p;
        }
        p = p->next;
    }
    return nullptr;
};

adrCar findCarByTire(ListCar L, string name){
    adrCar p = L.firstCar;
    while(p != nullptr){
        if(p->info.carTire->info.name == name){
            return p;
        }
        p = p->next;
    }
    return nullptr;
};

