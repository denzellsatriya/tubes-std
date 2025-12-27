//#include "head.h"
#include "Engine.h"
#include "Tires.h"
#include "Framework.h"
#include "Factory.h"

// Menu Display
void displayMenu(){
    cout << "\n========== MENU ==========\n";
    cout << "1. Tire\n";
    cout << "2. Engine\n";
    cout << "3. Framework\n";
    cout << "4. Car\n";
    cout << "5. Display All\n";
    cout << "0. Exit\n";

    cout << "\nChoice: ";
}
void carMenu(){
    cout << "\n========== Car ==========\n";
    cout << "1. Display Car\n";
    cout << "2. Delete Car\n";
    cout << "3. Add Car\n";
    cout << "0. Back\n";

    cout << "\nChoice: ";
}
void engineMenu(){
    cout << "\n========== Engine ==========\n";
    cout << "1. Display Engine\n";
    cout << "2. Delete Engine\n";
    cout << "3. Add Engine\n";
    cout << "0. Back\n";

    cout << "\nChoice: ";
}
void frameworkMenu(){
    cout << "\n========== Framework ==========\n";
    cout << "1. Display Framework\n";
    cout << "2. Delete Framework\n";
    cout << "3. Add Framework\n";
    cout << "0. Back\n";

    cout << "\nChoice: ";
}
void tireMenu(){
    cout << "\n========== Tire ==========\n";
    cout << "1. Display Tire\n";
    cout << "2. Delete Tire\n";
    cout << "3. Add Tire\n";
    cout << "0. Back\n";

    cout << "\nChoice: ";
}

// Main Program
int main()
{
    //==========List==========
    ListTire LT;
    ListEngine LE;
    ListFK LF;
    ListCar LC;

    createListTire(LT);
    createListEngine(LE);
    createListFK(LF);
    createListCar(LC);

    //Temp data
    buildCar(LC, LE, LT, LF);

    //Tampilan
    int pilihan1, pilihan2, price;
    string name;

    do {
        displayMenu();
        cin >> pilihan1;

        switch(pilihan1){
            //Tire
            case 1:
                do{
                    adrTire t;
                    string size, type;
                    tireMenu();
                    cin >> pilihan2;
                    switch(pilihan2){
                        case 1:
                            displayTire(LT);
                            break;
                        case 2:
                            displayTire(LT);
                            cout << "\n=== Delete Tire ===\n";

                            cout << "Name          : ";
                            cin >> name;
                            deleteTire(LT, t, findTire(LT, name));
                            break;
                        case 3:
                            displayTire(LT);
                            cout << "\n=== Input Tire ===\n";

                            bool loop = true;
                            do{
                                cout << "Name          : ";
                                cin >> name;
                                t = findTire(LT, name);
                                if(t == nullptr){
                                    loop = false;
                                }else{
                                    cout << "Name Already Exist!\n";
                                }
                            }while(loop == true);
                            cout << "Size          : ";
                            cin >> size;
                            cout << "Type          : ";
                            cin >> type;
                            cout << "Price         : ";
                            cin >> price;
                            addTire(LT, name, size, type, price);
                            break;

                    }
                } while(pilihan2 != 0);
                pilihan2 = NULL;
                break;
            //Engine
            case 2:
                do{
                    adrEngine e;
                    string fuel;
                    int HP;

                    engineMenu();
                    cin >> pilihan2;
                    switch(pilihan2){
                        case 1:
                            displayEngine(LE);
                            break;
                        case 2:
                            displayEngine(LE);
                            cout << "\n=== Delete Engine ===\n";

                            cout << "Name          : ";
                            cin >> name;
                            deleteEngine(LE, e, findEngine(LE, name));
                            break;
                        case 3:
                            displayEngine(LE);
                            cout << "\n=== Input Engine ===\n";

                            bool loop = true;
                            do{
                                cout << "Name          : ";
                                cin >> name;
                                e = findEngine(LE, name);
                                if(e == nullptr){
                                    loop = false;
                                }else{
                                    cout << "Name Already Exist!\n";
                                }
                            }while(loop == true);
                            cout << "Horsepower    : ";
                            cin >> HP;
                            cout << "Fuel Type     : ";
                            cin >> fuel;
                            cout << "Price         : ";
                            cin >> price;
                            addEngine(LE, name, HP, fuel, price);
                            break;
                    }
                } while(pilihan2 != 0);
                pilihan2 = NULL;
                break;
            //Framework
            case 3:
                do{
                    adrFK fk;
                    string material;
                    frameworkMenu();
                    cin >> pilihan2;
                    switch(pilihan2){
                        case 1:
                            displayFK(LF);
                            break;
                        case 2:
                            displayFK(LF);
                            cout << "\n=== Delete Framework ===\n";

                            cout << "Name          : ";
                            cin >> name;
                            deleteFK(LF, fk, findFK(LF, name));
                            break;
                        case 3:
                            displayFK(LF);
                            cout << "\n=== Input Framework ===\n";

                            bool loop = true;
                            do{
                                cout << "Name          : ";
                                cin >> name;
                                fk = findFK(LF, name);
                                if(fk == nullptr){
                                    loop = false;
                                }else{
                                    cout << "Name Already Exist!\n";
                                }
                            }while(loop == true);
                            cout << "Material      : ";
                            cin >> material;
                            cout << "Price         : ";
                            cin >> price;
                            addFramework(LF, name, material, price);
                            break;
                    }
                } while(pilihan2 != 0);
                pilihan2 = NULL;
                break;
            //Car
            case 4:
                do{
                    adrTire t;
                    adrEngine e;
                    adrFK fk;
                    adrCar c;
                    carMenu();
                    string eName, fkName, tName;

                    cin >> pilihan2;
                    switch(pilihan2){
                        case 1:
                            displayCar(LC);
                            break;
                        case 2:
                            displayCar(LC);
                            cout << "\n=== Delete Car ===\n";

                            cout << "Name          : ";
                            cin >> name;
                            deleteCar(LC, c, findCar(LC, name));
                            break;
                        case 3:
                            displayCar(LC);
                            cout << "\n=== Input Car ===\n";

                            bool loop = true;
                            do{
                                cout << "Name          : ";
                                cin >> name;
                                c = findCar(LC, name);
                                if(c == nullptr){
                                    loop = false;
                                }else{
                                    cout << "Car Already Exist!\n";
                                }
                            }while(loop == true);

                            loop = true;
                            while (loop == true){
                                displayEngine(LE);
                                cout << "\nSelect Engine : ";
                                cin >> eName;

                                e = findEngine(LE, eName);
                                if(e == nullptr){
                                    cout << "\nEngine Doesn't Exist!" << endl;
                                }else{
                                    loop = false;
                                }
                            }

                            loop = true;
                            while (loop == true){
                                displayTire(LT);
                                cout << "\nSelect Tire : ";
                                cin >> tName;

                                t = findTire(LT, tName);
                                if(t == nullptr){
                                    cout << "\nTire Doesn't Exist!" << endl;
                                }else{
                                    loop = false;
                                }
                            }

                            loop = true;
                            while (loop == true){
                                displayFK(LF);
                                cout << "\nSelect Framework : ";
                                cin >> fkName;

                                fk = findFK(LF, fkName);
                                if(fk == nullptr){
                                    cout << "\nFramework Doesn't Exist!" << endl;
                                }else{
                                    loop = false;
                                }
                            }

                            addCar(LC, name, e, t, fk);
                            break;

                    }
                } while(pilihan2 != 0);
                pilihan2 = NULL;
                break;
            //Display
            case 5:
                displayTire(LT);
                displayFK(LF);
                displayEngine(LE);
                displayCar(LC);
        }

    } while(pilihan1 != 0);

    cout << "Exiting Car Factory.\n";
    return 0;
}
