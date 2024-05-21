/*
 * Zachary Lopez
 * Apr 04 2024
 * 5
 * Assignment 5 - Application file
 * FILE 3 OF 3
 */

#include "rationalsZL.h"
#include <iostream>
#include <fstream>
using namespace Lopez;
using namespace std;

int main(){
    // The following code declares 3 sample objects using all the constructors and 2 that the user inputs and then it tests all calculation and prints it to the terminal for you to demonstrate all overrides are fully functional.
    rationalsZL sample1, sample2(5), sample3(5, 3), isample1, isample2, calculated_sample;

    cout << "Input 2 rational numbers with spaces between, formatted like so: 1/1 2/3 \n> ";
    
    cin >> isample1;
    cin >> isample2;
    cout << "Your inputted fractions were: " << isample1 << " " << isample2 << endl;
    cout << "Other sample fractions which were generated in main for constructor demonstration purposes are: " << sample1 << " " << sample2 << " " << sample3 << endl << endl;

    calculated_sample = isample1 + isample2;
    cout << isample1 << " + " << isample2 << " = " << calculated_sample << endl;

    calculated_sample = isample1 - isample2;
    cout << isample1 << " - " << isample2 << " = " << calculated_sample << endl;

    calculated_sample = isample1 * isample2;
    cout << isample1 << " * " << isample2 << " = " << calculated_sample << endl;

    calculated_sample = isample1 / isample2;
    cout << isample1 << " / " << isample2 << " = " << calculated_sample << endl;

    calculated_sample = isample1 > isample2;
    cout << "is " << isample1 << " greater than " << isample2 << "? (1/1 for true, 0/1 for false): " << calculated_sample << endl;

    calculated_sample = isample1 < isample2;
    cout << "is " << isample1 << " less than " << isample2 << "? (1/1 for true, 0/1 for false): " << calculated_sample << endl;

    calculated_sample = isample1 >= isample2;
    cout << "is " << isample1 << " greater than or equal to " << isample2 << "? (1/1 for true, 0/1 for false): " << calculated_sample << endl;

    calculated_sample = isample1 <= isample2;
    cout << "is " << isample1 << " less than or equal to " << isample2 << "? (1/1 for true, 0/1 for false): " << calculated_sample << endl;

    calculated_sample = isample1 == isample2;
    cout << "is " << isample1 << " equal to " << isample2 << "? (1/1 for true, 0/1 for false): " << calculated_sample << endl;

    calculated_sample = isample1 != isample2;
    cout << "is " << isample1 << " not equal to " << isample2 << "? (1/1 for true, 0/1 for false): " << calculated_sample << endl;

    calculated_sample = -isample1;
    cout << isample1 << " negated is: " << calculated_sample << endl;
    
    return 0;
}