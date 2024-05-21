#include <iostream>
#include <cmath>
#include <typeinfo>
#include <fstream>
#include <string>
using namespace std;


int main () {
  // Create a text file
  ofstream MyWriteFile("filename.txt");

  // Write to the file
  MyWriteFile << "Files can be tricky, but it is fun enough!" << endl << "Files ccky, but it is fun enough!" << endl << "Files can be tricky, n enough!" << endl;
 
  // Close the file
  MyWriteFile.close();

  // Create a text string, which is used to output the text file
  string myText;

  // Read from the text file
  ifstream MyReadFile("filename.txt");

  // Use a while loop together with the getline() function to read the file line by line
  while (getline (MyReadFile, myText)) {
    // Output the text from the file
    cout << myText << endl;
  }

  // Close the file
  MyReadFile.close();
}
