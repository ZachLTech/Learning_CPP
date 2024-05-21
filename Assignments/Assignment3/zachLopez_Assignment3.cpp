 /*
 * Zachary Lopez
 * Feb 23 2024
 * 3
 * Assignment 3 :: Randomizes student test scores and tests taken for an input file to average the scores out of 10 and output the programmatically crafted input file alongside each students averaged scores to the right 
 * 
 * Tested Values: The generated input is random therefore no values could be tested except student names (although I tested when it generates 0 tests for a student and it works)
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

struct score{
    string first;
    string last;
    int scores[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double average;
};

int randQuizzesTaken();
int randQuizScore();
score generateInput(score student, int iteration, ofstream& GeneratedGradesFile);
void populateOutput(score student[], ofstream& OutputAveragedGradesFile);

int main(){
    // Make Streams and open the files
    ofstream StudentSheetRawGenerate("raw_scores.txt");
    ofstream StudentSheetAvg("avg_scores.txt");
    // Assigns the randomization seed to the amount of seconds passed since January, 1970 (Method found in this article: https://www.digitalocean.com/community/tutorials/random-number-generator-c-plus-plus)
    srand((unsigned) time(NULL));
    // Array of students and their info to be used later
    score students[10];
    // Loops through to generate 10 students and output it into file
    for (int i=0; i < 10; i++){
        students[i] = generateInput(students[i], i, StudentSheetRawGenerate);
    }
    // Populates output file with averages at the end
    populateOutput(students, StudentSheetAvg);
    // Closes files
    StudentSheetRawGenerate.close();
    StudentSheetAvg.close();
    // Bye :)
    return 0;
}


/****************************************************
 * Randomization Functions (2) and Average Function *
 ****************************************************/
int randQuizzesTaken(){
    // Define the range which is based on the function parameters
    int range = ((10 - 0)+1);
    // Return a number between the given range
    return 0 + (rand() % range);
}
int randQuizScore(){
    // Define the range which is based on the function parameters
    int range = ((20 - 1)+1);
    // Return a number between the given range
    return 1 + (rand() % range);
}
double average(int scores[]){
    int total = 0;
    // Iterates through array and adds numbers to total
    for (int i=0; i < 10; i++){
        total += scores[i];
    }
    // Returns average (total divided by 10 since there can only be 10 scores according to instructions)
    return double(total)/10;
}


/*****************************
 * Input and Output Function *
 *****************************/
score generateInput(score student, int iteration, ofstream& GeneratedGradesFile){

    /*********************Generate Student Scores*********************/
    // Generates a random number of quizzes that the student took
    int quizzesTaken = randQuizzesTaken();
    // Generates scores per quiz between 1 and 20
    for (int i=0; i < quizzesTaken; i++){
        student.scores[i] = randQuizScore();
    }

    /*********************Get Student Names**********************/
    cout << "\nStudent " << iteration+1 << " - First Name? \n> ";
    cin >> student.first;
    cout << "\nStudent " << iteration+1 << " - Last Name? \n> ";
    cin >> student.last;

    /********************Output Data To File*******************/
    // Outputs first and last name
    GeneratedGradesFile << student.last << ", " << student.first << " ";
    // Iterates through scores and outputs each one in file ONLY if the score isn't 0 (meaning the student didn't take the quiz)
    for (int i=0; i < 10; i++){
        if (student.scores[i] != 0){
            GeneratedGradesFile << student.scores[i] << " ";
        }
        else{
            continue;
        }
    }
    // Starts new line in file for next iteration of this function
    GeneratedGradesFile << endl;
    // Returns student struct to main
    return student;
}

void populateOutput(score students[], ofstream& OutputAveragedGradesFile){
    /********************Output Data With Average To File*******************/
    // output message in file
    OutputAveragedGradesFile << "This file displays the students' quiz scores along with the average score for each student.\n" << endl;
    // For loop iterates through student info and outputs it in file including the averaged info
    for (int i=0; i < 10; i++){
        OutputAveragedGradesFile << students[i].last << ", " << students[i].first << " ";
        // Iterates through scores and outputs each one in file ONLY if the score isn't 0 (meaning the student didn't take the quiz)
        for (int i2=0; i2 < 10; i2++){
            if (students[i].scores[i2] != 0){
                OutputAveragedGradesFile << students[i].scores[i2] << " ";
            }
            else{
                continue;
            }
        }
        // output the average in file after each line (and calculates it with function) 
        OutputAveragedGradesFile << ": " << average(students[i].scores) << endl;
    }
}