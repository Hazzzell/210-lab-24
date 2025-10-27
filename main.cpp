#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>          // std::set
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(set<Goat> trip);
void add_goat(set<Goat> &trip, string [], string []);
void display_trip(set<Goat> trip);
void delete_goat(set<Goat> &trip);

int main_menu(){
    int choice;
    cout << "\n*** GOAT MANAGER 3001 ***\n" ;
    cout << "\n[1] Add a goat\n" ;
    cout << "\n[2] Delete a goat\n" ;
    cout << "\n[3] List goats\n" ;
    cout << "\n[4] Quit\n" ;
    cout << "\nChoice --> " ;
    cin >> choice;

    while (cin.fail() || choice < 1 || choice > 4) {
        cin.clear();
        cin.ignore();
        cout << "Invalid, Try again: "; 
        cin >> choice;
    }
    return choice;
}

int main() {
    srand(time(0));
    bool again = true;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();

    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    set<Goat> trip;
    int choice;


    do {
        choice = main_menu();
        switch (choice) {
            case 1: 
            add_goat(trip, names, colors);
            break;

            case 2:
            delete_goat(trip);
            break;

            case 3:
            display_trip(trip);
            break;

            case 4:
            again = false;
            break;
        }
    } while (again);
    return 0;
}

int select_goat(set<Goat> trip){
    display_trip(trip);
    if (trip.empty()) return -1;

    int choice;
    cout << "\nSelect Goat number to delete: ";
    cin >> choice;

    while (cin.fail() || choice < 1 || choice > 4) {
        cin.clear();
        cin.ignore();
        cout << "Invalid, Try again: "; 
        cin >> choice;
    }
    return choice;
}

void add_goat(set<Goat> &trip, string names[], string colors[]){
    int randName = rand() % SZ_NAMES;
    int randColor = rand() % SZ_COLORS;
    int randAge = rand() % (MAX_AGE + 1);

    Goat g(names[randName], randAge, colors[randColor]);
    trip.insert(g);

    cout << "\nAdded Goat: " 
    << g.get_name() << " (" 
    << g.get_age() << ", " 
    << g.get_color() << ")\n";
}

void display_trip(set<Goat> trip){
    if (trip.empty()){
        cout << "\nThere are No goats.\n";
        return;
    }
    cout << "\nCurrent Goat Trip:\n";
    int i = 1;
    for (const Goat& g: trip){
        cout << setw(4) << "[" << i++ << "]"
        << g.get_name() << " ("
        << g.get_age() << ", " << g.get_color() << ")\n";
    }
}

void delete_goat(set<Goat> &trip){
    int choice = select_goat(trip);
    if (choice == -1) return;

    int i = 1;
    for (auto it = trip.begin(); it != trip.end(); ++it, ++i) {
        if (i == choice) {
            cout << "\nDeleted " << it->get_name() << endl;
            trip.erase(it);
            break;
        }
    }
}
