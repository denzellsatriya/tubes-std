//#include "head.h"
#include "Engine.h"
#include "Tires.h"
#include "Framework.h"
#include "Factory.h"
#include "limits"

// Menu Display
void displayMenu(){
    cout << "\n========== MENU ==========\n";
    cout << "1. Tire\n";
    cout << "2. Engine\n";
    cout << "3. Framework\n";
    cout << "4. Car\n";
    cout << "5. Display All\n";
    cout << "0. Exit\n";
}
void carMenu(){
    cout << "\n========== Car ==========\n";
    cout << "1. Display Car\n";
    cout << "2. View Car\n";
    cout << "3. Delete Car\n";
    cout << "4. Add Car\n";
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
    bool loop = true;

    do {
        displayMenu();

        cout << "\nChoice: ";
        cin >> pilihan1;

        switch(pilihan1){
            //Tire
            case 1:
                do{
                    adrTire t;
                    adrCar c;
                    string size, type;
                    tireMenu();
                    cin >> pilihan2;

                    switch(pilihan2){
                        case 1:
                            displayTire(LT);
                            break;
                        case 2:
                            displayTire(LT);
                            if(!isEmptyTire(LT)){
                                cout << "\n========== Delete Tire ==========\n";

                                cout << "Name          : ";
                                cin >> name;
                                c = findCarByTire(LC, name);
                                if(c != nullptr){
                                    cout << "\nTire " << name << " is in use for " << c->info.name << endl;
                                }else{
                                     deleteTire(LT, t, name);
                                }
                            }
                            break;
                        case 3:
                            displayTire(LT);
                            cout << "\n========== Input Tire ==========\n";

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

                            loop = true;
                            do{
                                cout << "Price         : ";
                                cin >> price;
                                if(price == NULL){
                                    cout << "Input Must Be A Number & Higher Than 0!\n";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }else{
                                    loop = false;
                                }
                            }while(loop == true);

                            addTire(LT, name, size, type, price);
                            cout << "\nTire added!\n";
                            break;
                    }
                } while(pilihan2 != 0);
                pilihan2 = NULL;
                break;
            //Engine
            case 2:
                do{
                    adrEngine e;
                    adrCar c;
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
                            if(!isEmptyEngine(LE)){
                                cout << "\n========== Delete Engine ==========\n";

                                cout << "Name          : ";
                                cin >> name;
                                c = findCarByEngine(LC, name);
                                if(c != nullptr){
                                    cout << "\nEngine " << name << " is in use for " << c->info.name << endl;
                                }else{
                                     deleteEngine(LE, e, name);
                                }
                            }
                            break;
                        case 3:
                            displayEngine(LE);
                            cout << "\n========== Input Engine ==========\n";

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

                            loop = true;
                            do{
                                cout << "Horsepower    : ";
                                cin >> HP;
                                if(HP == NULL){
                                    cout << "Input Must Be A Number & Higher Than 0!\n";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }else{
                                    loop = false;
                                }
                            }while(loop == true);

                            cout << "Fuel Type     : ";
                            cin >> fuel;

                            loop = true;
                            do{
                                cout << "Price         : ";
                                cin >> price;
                                if(price == NULL){
                                    cout << "Input Must Be A Number & Higher Than 0!\n";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }else{
                                    loop = false;
                                }
                            }while(loop == true);

                            addEngine(LE, name, HP, fuel, price);
                            cout << "\nEngine added!\n";
                            break;
                    }
                } while(pilihan2 != 0);
                pilihan2 = NULL;
                break;
            //Framework
            case 3:
                do{
                    adrFK fk;
                    adrCar c;
                    string material;
                    frameworkMenu();
                    cin >> pilihan2;
                    switch(pilihan2){
                        case 1:
                            displayFK(LF);
                            break;
                        case 2:
                            displayFK(LF);
                            if(!isEmptyFK(LF)){
                                cout << "\n========== Delete Framework ==========\n";

                                cout << "Name          : ";
                                cin >> name;
                                c = findCarByFK(LC, name);
                                if(c != nullptr){
                                    cout << "\nFramework " << name << " is in use for " << c->info.name << endl;
                                }else{
                                     deleteFK(LF, fk, name);
                                }
                            }
                            break;
                        case 3:
                                displayFK(LF);
                                cout << "\n========== Input Framework ==========\n";

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

                                loop = true;
                                do{
                                    cout << "Price         : ";
                                    cin >> price;
                                    if(price == NULL){
                                        cout << "Input Must Be A Number & Higher Than 0!\n";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    }else{
                                        loop = false;
                                    }
                                }while(loop == true);

                                addFramework(LF, name, material, price);
                                cout << "\nFramework added!\n";
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

                            if(!isEmptyCar(LC)){
                                cout << "\n========== View Car ==========\n";
                                cout << "Name          : ";
                                cin >> name;

                                c = findCar(LC, name);
                                if(c != nullptr){
                                    viewCar(c);
                                }else{
                                    cout << "\nCar with the name " << name << " doesnt't exist!" << endl;
                                }
                            }
                            break;
                        case 3:
                            displayCar(LC);

                            if(!isEmptyCar(LC)){
                                cout << "\n========== Delete Car ==========\n";

                                cout << "Name          : ";
                                cin >> name;
                                deleteCar(LC, c, name);
                            }
                            break;
                        case 4:
                            if(!isEmptyEngine(LE) && !isEmptyFK(LF) && !isEmptyTire(LT)){
                                displayCar(LC);
                                cout << "\n========== Input Car ==========\n";

                                //Input Name
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

                                //Input Engine
                                loop = true;
                                while (loop == true){
                                    displayEngine(LE);
                                    cout << "\nSelect Engine : ";
                                    cin >> eName;

                                    e = findEngine(LE, eName);
                                    if(e == nullptr){
                                        cout << "\nEngine Doesn't Exist!" << endl;
                                    }else{ loop = false; }
                                }

                                //Input Tire
                                loop = true;
                                while (loop == true){
                                    displayTire(LT);
                                    cout << "\nSelect Tire : ";
                                    cin >> tName;

                                    t = findTire(LT, tName);
                                    if(t == nullptr){
                                        cout << "\nTire Doesn't Exist!" << endl;
                                    } else{ loop = false; }
                                }

                                //Input Framework
                                loop = true;
                                while (loop == true){
                                    displayFK(LF);
                                    cout << "\nSelect Framework : ";
                                    cin >> fkName;

                                    fk = findFK(LF, fkName);
                                    if(fk == nullptr){
                                        cout << "\nFramework Doesn't Exist!" << endl;
                                    } else { loop = false; }
                                }
                                addCar(LC, name, e, t, fk);
                                cout << "\nCar added!\n";

                            }else{
                                string component;

                                if(isEmptyEngine(LE)){ component += " Engine,"; }
                                if(isEmptyFK(LF)){ component += " Framework,"; }
                                if(isEmptyTire(LT)){ component += " Tire,"; }

                                cout << "\nNo" << component << " exist to build a car!\n";
                            }
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
                break;
        }

    } while(pilihan1 != 0);

    cout << "Exiting Car Factory.\n";
    return 0;
}
