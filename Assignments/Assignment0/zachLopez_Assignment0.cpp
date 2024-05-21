/*
 * Zachary Lopez
 * Jan 13 2024 
 * 0
 * Assignment 0 :: Input/Output - cin/cout
 *
 * This program outputs a custom message before asking for the users age and showing them what they inputted as their age.
 */

#include <iostream>

// Main Function
int main() {
  // Declaring age integer variable
  int age;
  // Outputted message that isn't "Hello World!"
  std::cout << "(initramfs) exit\n\n\nWelcome to NonexistentOS!\n\n";
  
  // Ask for age, assigning user input to age variable, and outputting a message showing the user inputted age
  std::cout << "\033[0m\n\nWhat's your age?\n> ";
  std::cin >> age;
  std::cout << "\nYour inputted age: " << age << "\n\n";

  // Returning 0 to make everyone happy!
  return 0;
}
// Closing main function... Have a nice day!
