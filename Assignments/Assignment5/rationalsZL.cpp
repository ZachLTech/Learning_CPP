/*
 * Zachary Lopez
 * Apr 04 2024
 * 5
 * Assignment 5 - Implementation file
 * FILE 2 OF 3
 */

#include "rationalsZL.h"
#include <iostream>
#include <fstream>
using namespace std;

// Class was originally wrapped in unnamed namespace as instructions mentioned but I wasn't able to access any of the private variables so I had to put it back in my namespace... the instructions confused me when mentioning "the implementation functions which are helpers and stand alone should [...] be placed in an unnamed namespace"
namespace Lopez{

    // Constructor definitions
    rationalsZL::rationalsZL(): numerator(0), denominator(1) {}
    rationalsZL::rationalsZL(int numerator): numerator(numerator), denominator(1) {}
    rationalsZL::rationalsZL(int numerator, int denominator): numerator(numerator), denominator(denominator){}

    // Friend function operator overload definitions
    // In/Out
    istream& operator>>(istream& ins, rationalsZL& rational_number){
        char slash;
        int numerator, denominator;

        ins >> rational_number.numerator;
        ins >> slash;
        ins >> rational_number.denominator;

        return ins;
    }
    ostream& operator<<(ostream& outs, rationalsZL& rational_number){
        outs << rational_number.numerator << "/" << rational_number.denominator;
        return outs;
    }
    // Arithmetic
    rationalsZL operator +(rationalsZL& rational_number1, rationalsZL& rational_number2){
        // Initializes temp variable to be returned
        rationalsZL rational_calculated;
        // Uses the numerator equation given in instructions to calculate the numerator with the numerator setter
        rational_calculated.numerator = ((rational_number1.numerator * rational_number2.denominator) + (rational_number1.denominator * rational_number2.numerator));
        // Uses the denominator equation given in instructions to calculate the denominator with the denominator setter
        rational_calculated.denominator = (rational_number1.denominator * rational_number2.denominator);
        // Returns calculated rational number
        return rational_calculated;
    }
    rationalsZL operator -(rationalsZL& rational_number1, rationalsZL& rational_number2){
        // Initializes temp variable to be returned
        rationalsZL rational_calculated;
        // Uses the numerator equation given in instructions to calculate the numerator with the numerator setter
        rational_calculated.numerator = ((rational_number1.numerator * rational_number2.denominator) - (rational_number1.denominator * rational_number2.numerator));
        // Uses the denominator equation given in instructions to calculate the denominator with the denominator setter
        rational_calculated.denominator = (rational_number1.denominator * rational_number2.denominator);
        // Returns added rational number
        return rational_calculated;
    }
    rationalsZL operator *(rationalsZL& rational_number1, rationalsZL& rational_number2){
        // Initializes temp variable to be returned
        rationalsZL rational_calculated;
        // Uses the numerator equation given in instructions to calculate the numerator with the numerator setter
        rational_calculated.numerator = ((rational_number1.numerator * rational_number2.numerator));
        // Uses the denominator equation given in instructions to calculate the denominator with the denominator setter
        rational_calculated.denominator = (rational_number1.denominator * rational_number2.denominator);
        // Returns added rational number
        return rational_calculated;
    }
    rationalsZL operator /(rationalsZL& rational_number1, rationalsZL& rational_number2){
        // Initializes temp variable to be returned
        rationalsZL rational_calculated;
        // Uses the numerator equation given in instructions to calculate the numerator with the numerator setter
        rational_calculated.numerator = ((rational_number1.numerator * rational_number2.denominator));
        // Uses the denominator equation given in instructions to calculate the denominator with the denominator setter
        rational_calculated.denominator = (rational_number2.numerator * rational_number1.denominator);
        // Returns added rational number
        return rational_calculated;
    }
    // Comparisons
    bool operator ==(rationalsZL& rational_number1, rationalsZL& rational_number2){
        // Checks if they're equal and returns true if true and false otherwise
        if ((rational_number1.numerator * rational_number2.denominator) == (rational_number1.denominator * rational_number2.numerator)){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator !=(rationalsZL& rational_number1, rationalsZL& rational_number2){
        // Checks if they're not equal and returns true if true and false otherwise
        if ((rational_number1.numerator * rational_number2.denominator) == (rational_number1.denominator * rational_number2.numerator)){
            return false;
        }
        else{
            return true;
        }
    }

    bool operator >(rationalsZL& rational_number1, rationalsZL& rational_number2){
        if ((rational_number1.numerator * rational_number2.denominator) > (rational_number1.denominator * rational_number2.numerator)){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator >=(rationalsZL& rational_number1, rationalsZL& rational_number2){
        if ((rational_number1.numerator * rational_number2.denominator) >= (rational_number1.denominator * rational_number2.numerator)){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator <(rationalsZL& rational_number1, rationalsZL& rational_number2){
        if ((rational_number1.numerator * rational_number2.denominator) < (rational_number1.denominator * rational_number2.numerator)){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator <=(rationalsZL& rational_number1, rationalsZL& rational_number2){
        if ((rational_number1.numerator * rational_number2.denominator) <= (rational_number1.denominator * rational_number2.numerator)){
            return true;
        }
        else{
            return false;
        }
    }
    // Unary operator overload definition
    rationalsZL operator -(rationalsZL& rational_number){
        // Initializes temp variable to be returned
        rationalsZL negated_number;
        // Sets numerator to the same number passed through but negated
        negated_number.numerator = (-(rational_number.numerator));
        // Sets numerator to the same number passed through 
        negated_number.denominator = (rational_number.denominator);
        // Returns negated rational number
        return negated_number;
    }
};