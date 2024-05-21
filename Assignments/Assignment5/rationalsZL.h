/*
 * Zachary Lopez
 * Apr 01 2024
 * 5
 * Assignment 5 - Interface file
 * FILE 1 OF 3
 */

// For safety from redefinition as stated in instructions to be required
#ifndef RATIONALSZL_H
#define  RATIONALSZL_H
// Standard Libs
#include <iostream>
#include <fstream>
using namespace std;
// Class wrapped in namespace as instructions mentioned
namespace Lopez{
    class rationalsZL{
    private:
        // Main variables
        int numerator;
        int denominator;
        // Helper functions below except they aren't necessary
        // rationalsZL fractionToDecimal(rationalsZL& rational_number);
        // rationalsZL simplify(rationalsZL& rational_number);
    public:
        // Constructors 
        rationalsZL();
        rationalsZL(int numerator);
        rationalsZL(int numerator, int denominator);
        // Friend function operator overloads
        friend istream& operator>>(istream& ins, rationalsZL& rational_number);
        friend ostream& operator<<(ostream& outs, rationalsZL& rational_number);
        friend rationalsZL operator +(rationalsZL& rational_number1, rationalsZL& rational_number2);
        friend rationalsZL operator -(rationalsZL& rational_number1, rationalsZL& rational_number2);
        friend rationalsZL operator *(rationalsZL& rational_number1, rationalsZL& rational_number2);
        friend rationalsZL operator /(rationalsZL& rational_number1, rationalsZL& rational_number2);
        friend bool operator ==(rationalsZL& rational_number1, rationalsZL& rational_number2);
        friend bool operator !=(rationalsZL& rational_number1, rationalsZL& rational_number2);
        friend bool operator >(rationalsZL& rational_number1, rationalsZL& rational_number2);
        friend bool operator >=(rationalsZL& rational_number1, rationalsZL& rational_number2);
        friend bool operator <(rationalsZL& rational_number1, rationalsZL& rational_number2);
        friend bool operator <=(rationalsZL& rational_number1, rationalsZL& rational_number2);
        // Unary operator overload
        friend rationalsZL operator -(rationalsZL& rational_number);
    };
}
// End of redefinition safety protocol 
#endif