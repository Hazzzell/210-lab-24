// Goat.h

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
using namespace std;

class Goat {
private:
    string name;
    int age;
    string color;
public: 
    Goat() { name = ""; age = 0; color = ""; }

    // write three more constructors
    // name only
    Goat(string n) { 
        name = n; 
        age = 0; 
        color = "";
    }

    // name and age
    Goat(string n, int a){
        name = n; 
        age = a; 
        color = "";
    }

    // name, age and color
    Goat(string n, int a, string c){
        name = n; 
        age = a; 
        color = c;
    }

    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    // write overloaded < operator for the std::list
    // ordering name, age, color
    bool operator<(const Goat& other) const{
        if (name != other.name) return name < other.name;
        else if (age != other.age) return age < other.age;
        else return color < other.color;
    }
};

#endif
