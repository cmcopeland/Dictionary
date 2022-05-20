// Camille Copeland - CS10C Dave Harden - Assignment 15 - File Name: Client.cpp - 05/19/2021

#include <iostream>
#include <fstream>
#include <cassert>
#include "HashedDictionary.h"
#include "Entry.h"
#include "HashedEntry.h"
#include <string>

using namespace std;

struct FamousPerson {
    string id;
    char taxStatus;
    string lastname;
    string firstname;
    int age;
    string street;
    string zip;
};

void readOnePerson(istream& infile, FamousPerson& readMe);


// the insertion operator overload is just here so that the HashedDictionary
// display function can use it to print FamousPerson objects.
ostream& operator<<(ostream& out, const FamousPerson& printMe);


int main() {
    HashedDictionary<string, FamousPerson> h;
    FamousPerson tempPerson;

    bool empty = h.isEmpty();
    if (empty) {
        cout << "Dictionary is empty as it should be" << endl;
    }
    else {
        cout << "Dictionary has entries but it shouldn't" << endl;
    }

    ifstream infile("famous.txt");
    assert(infile);

    readOnePerson(infile, tempPerson);
    while (infile) {
        h.add(tempPerson.lastname, tempPerson);
        readOnePerson(infile, tempPerson);
    }

    //h.display();


    //TEST : Remove - isEmpty - getNumberOfItems - clear - getItem - contains


    bool contains = h.contains("moose");
    if (contains) {
        cout << "Dictionary contains bullwinkle and should!" << endl;
    }
    else {
        cout << "Bullwinkle not found and should've been found" << endl;
    }

    contains = h.contains("osbourne");
    if (contains) {
        cout << "Dictionary contains ozzy but it shouldn't...." << endl;
    }
    else {
        cout << "Ozzy be passed out" << endl;
    }

    FamousPerson al = h.getItem("einstein");
    cout << al << endl;

    cout << "Dictionary contains " << h.getNumberOfItems() << " entries." << endl;

    empty = h.isEmpty();
    if (empty) {
        cout << "Dictionary is empty but it shouldn't be" << endl;
    }
    else {
        cout << "Dictionary has entries as it should" << endl;
    }

    bool remove = h.remove("motzart");
    if (remove) {
        cout << "Motzart has been removed as it should've been" << endl;
    }
    else {
        cout << "Motzart is still hanging around" << endl;
    }

    h.clear();

    empty = h.isEmpty();
    if (empty) {
        cout << "Dictionary is empty as it should be" << endl;
    }
    else {
        cout << "Dictionary has entries but it shouldn't" << endl;
    }

}





ostream& operator<<(ostream& out, const FamousPerson& printMe) {
    out << printMe.id << " ";
    out << printMe.taxStatus << " ";
    out << printMe.lastname << " ";
    out << printMe.firstname << " ";
    out << printMe.age << " ";
    out << printMe.street << " ";
    out << printMe.zip;
    return out;
}


void readOnePerson(istream& infile, FamousPerson& readMe) {
    infile >> readMe.id;
    infile >> readMe.taxStatus;
    infile >> readMe.lastname;
    infile >> readMe.firstname;
    infile >> readMe.age;
    infile >> readMe.street;
    infile >> readMe.zip;
}
