/*
 * Zachary Lopez
 * Jan 25 2024
 * 1
 * Assignment 1 :: Meant to return the least amount of coins from an inputted price between 0 and 100 dollars
 * 
 * Tested Values: -5, -5.99, 0, 0.00, 2.99, 43.543, 43, 000043.2300000, 5435, 543.543, 00000543505.20000543, 5.42, 100
 */

// Including required libs and making namespace std 
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
  // Initializing coin variables as integers and a double for the inputted amount before conversion. Also const values for each coin
  const int QUARTER=25, DIME=10, NICKEL=5, PENNIE=1;
  int quarters, dimes, nickels, pennies;
  double amount;
  
  // Welcome message with instructions and getting inputted value
  cout << "\n\n\nWelcome to Zach's Coin Shop!\nTo convert your money to coins, input an amount of money to be converted that's less than $100 (I don't have many coins)\n\nNote: Make sure to format your input as: $xx.xx\n\n> $";
  cin >> amount;

  // Conditionals to test if the inputted amount is too high or low. Also checks if it's 0 just to add a funny message before continuing
  if(amount>=100){
    cout << "\nYour inputted value must be less than $100! Like I said, I don't have very many coins... Come again!";
    exit(1);
  }
  else if(amount<0){
    cout << "\nYour inputted value must be less than $100! \nWait, you have... negative coins?? How.. maybe you can find some on the floor outside but I don't have any to spare for you sorry. Come again!";
    exit(1);
  }
  else if(amount==0){
    cout << "\nuhh, I'm not sure I can help you if you have no money but I guess we'll just continue.\n";
  }

  // Make amount malleable by multiplyinig 100
  amount *= 100;
  // Converting amount array to int to avoid some issues, shouldn't lose data since amount is now a whole number. This also seemed to not result in any off-by-one errors
  int amountint = int(amount);
  // Check quarters
  quarters = amountint / QUARTER;
  amountint %= QUARTER;
  // Check dimes
  dimes = amountint / DIME;
  amountint %= DIME;
  // Check nickels
  nickels = amountint / NICKEL;
  amountint %= NICKEL;
  // Finish it off with pennies
  pennies = amountint;
  
  // Outputs a message including their inputted amount, how many coins are returned, and a humble goodbye.
  cout << "\nOk! Here you go.\n\nYour Inputted Amount: $" << amount/100 << endl << "\nCoins Returned:\n" << quarters << " Quarter(s)\n" << dimes << " Dime(s)\n" << nickels << " Nickel(s)\n" << pennies << " Pennie(s)\n";
  cout << "\n\nThank you for visiting. Have a nice day!";

  // End's the program following good practice
  return 0;
}