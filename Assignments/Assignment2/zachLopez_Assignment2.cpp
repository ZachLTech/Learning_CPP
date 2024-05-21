 /*
 * Zachary Lopez
 * Feb 5 2024
 * 2
 * Assignment 2 :: Loan Calculator which takes inputted loan amount, annoual percentage rate, and loan term, then outputs a tabular result of loan payment details alongside a payment summary
 * 
 * Tested Values: 20000 - 10 - 24 ; 34000 - 23 - 36 ; tested possible errors that a user could input to confirm it catches correctly (and I added some extra funny messages for the user if they input incorrect values)
 */

// Including required libs and making namespace std 
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

// Declaring functions
int welcome();
void input_values(double &p, double &APR, int &n);
double monthly_interest_rate(double APR);
double amortization(double p, int n, double MIR);
void calculate_interest_and_principal(double &interest, double &principal, double &balance, int i, double MIR, double p, double m);
void keep_track_of_payments(double &balance, double &total_payments, double &total_interest, double &interest, double &principal, double m);
void output_table(double IPM[], double PPM[], double BPM[], int n);
void output_summary(double m, double total_payments, double total_interest);

// Main Function
int main(){
    // P is loan total, APR is Annual Percentage Rate, MIR is Monthly Interest Rate, m is monthly payments
    double p, APR, MIR, m;
    // N is loan term (in months)
    int n;

    // Main loop to run program
    while (true)
    {
        // Main program function calls
        welcome();
        input_values(p, APR, n);
        // IPM is Interest (Balance) Per Month, PPM is Principle (Balance) Per Month, BPM is Total Balance Per Month
        double IPM[n], PPM[n], BPM[n];
        // mutable loan total
        double balance = p, total_payments, total_interest;
        // Confirms Entered Values are now in Main function Scope
        cout << "\nAmount Entered: $" << p << endl; 
        cout << "APR Entered: " << APR << "%" << endl; 
        cout << "Loan Term Entered: " << n << " Months" << endl;
        // Gets Rates by setting variables equal to calculation functions
        MIR = monthly_interest_rate(APR); // Output Test: cout << "MIR: " << MIR << endl;
        m = amortization(p, n, MIR); // Output Test: cout << "Monthly Payments: $" << m << endl;
        // For loop to aggregate each months values
        for (int i = 0; i < n; i++){
            // temporary variables redeclared per iteration to hold interest and principal values calculated by function until they're assigned to their corresponding array
            double interest, principal;
            // function call to get interest, principal, and calculate balance
            calculate_interest_and_principal(interest, principal, balance, i, MIR, p, m);
            // after function calculates interest, pricipal, and balance it sets them equal to that months array position for each interest, principal, and balance array to be organized into tabular format later
            IPM[i] = interest;
            PPM[i] = principal;
            BPM[i] = balance;
            // does what the function is named (keeps track of payments)
            keep_track_of_payments(balance, total_payments, total_interest, interest, principal, m);
        }
        // calls the functions to output tabular results and summary
        output_table(IPM, PPM, BPM, n);
        output_summary(m, total_payments, total_interest);
    }
    return 0; // Technically unnecessary as main will never use this line
}

// Welcome Function
int welcome(){
    int choice;
    do{
        // Ask the user if they would like to continue the program or quit and gets their answer
        cout << "\n\nWelcome (back) to Zach's Loan Calculation Office! How may I assist you?\n( 1 - Calculate | 2 - Exit )\n\n(1 or 2) > ";
        cin >> choice;
        // Detects and Exits the program if the user types a non integer value
        if (cin.fail()){
            cout << "Are you trying to break my calculator?? Shoo!! I don't accept rude customers! - Next time make sure you're inputting a positive integer (Either 1 or 2)! Please try again." << endl;
            exit(1);
        }
        // Switch case to either exit the program if they choose "Quit" or return 1 for main function to continue with the other calculation functions. Also has safety for incorrect inputs.
        switch (choice){
            case (1):
                return 1;
            case (2):
                cout << "\nBye!" << endl;
                exit(1);
            default:
                cout << "That's not an option." << endl;
                choice = 0;
                break;
        }
    } while(choice != 1 || choice != 2);
    return 0;
}

// Get User Input Function
void input_values(double &p, double &APR, int &n){
    // Declaring boolean used in while loop to check if the form has been successfully completed
    bool formComplete = false;

    while (formComplete != true){
        //  The following cout and cin calls simply asks the user for each value and assigns it to the right variable if all checks are passed
        // The following if statements detects and exits the program if the user types a non integer value
        // The following else if statements output a funny message if the user inputs a negative value and restarts the input process
        cout << "\nWhat's your loan amount? \n> $";
        cin >> p;
        if (cin.fail()){
            cout << "Are you trying to break my calculator?? Shoo!! I don't accept rude customers! - Next time make sure you're inputting a positive number! Restart and Please try again." << endl;
            exit(1);
        }
        else if (p < 0){
            cout << "How did you get a negative loan? That's odd... This calculator only accepts positive numbers. Restart and Please try again." << endl;
            continue;
        }

        cout << "\nWhat's your annual percentage rate? \n> ";
        cin >> APR;
        if (cin.fail()){
            cout << "Are you trying to break my calculator?? Shoo!! I don't accept rude customers! - Next time make sure you're inputting a positive number! Restart and Please try again." << endl;
            exit(1);
        }
        else if (APR < 0){
            cout << "A NEGATIVE RATE?? I wish! I know you're joking... This calculator only accepts positive numbers. Restart and Please try again." << endl;
            continue;
        }

        cout << "\nWhat's your loan term? (Integer In months)\n> ";
        cin >> n;
        if (cin.fail()){
            cout << "Are you trying to break my calculator?? Shoo!! I don't accept rude customers! - Next time make sure you're inputting a positive integer! Restart and Please try again." << endl;
            exit(1);
        }
        else if (n < 0){
            cout << "Nice try time traveller. This calculator only accepts positive numbers. Restart and Please try again." << endl;
            continue;
        }
        // Sets the boolean variable true if the user successfully inputs valid info so the loop will end and the rest of the program can commence
        formComplete = true;
    }
}

// Calculates Monthly Interest Rate Function (Somewhat unnecessary to be a function imo)
double monthly_interest_rate(double APR){
    // Returns monthly interest rate using formula given
    return pow((1 + APR / 100), (1.0 / 12)) - 1;
}

double amortization(double p, int n, double MIR){
    // Returns total payment per month using amortization formula and rounds it to nearest thousandth
    return round(1000*(((p * MIR) * pow((1 + MIR), n)) / (pow((1 + MIR), n) - 1)))/1000;
}

void calculate_interest_and_principal(double &interest, double &principal, double &balance, int i, double MIR, double p, double m){
    // Calculate interest and principal
    interest = round(1000*(MIR * balance))/1000;
    principal = m - interest;
}

void keep_track_of_payments(double &balance, double &total_payments, double &total_interest, double &interest, double &principal, double m){
    // Updates total payments, total interest, and mutable balance variable for further iterations
    balance -= principal;
    total_payments += m;
    total_interest += interest;
    // Output Test w/ i as parameter: cout << "Interest & Principal & Balance For Month " << i+1 << ": " << interest << " : " << principal << " : " << balance << endl;
}

// Outputs interest and principal portion of the loan for each month & remaining balance
void output_table(double IPM[], double PPM[], double BPM[], int n){
    string table;

    // appends the header to the table
    table += "\nMonth\t\tInterest\t\tPrincipal\t\tBalance\n";

    // appends the data to the table
    // I was having issues with the converted doubles to strings outputting with too many zero's and couldn't figure it out so I used this source to help with the outputting error and learnt about the str.erase function: https://stackoverflow.com/questions/13686482/c11-stdto-stringdouble-no-trailing-zeros
    for (int i = 0; i < n; i++) {
        // Declares 3 variables each set equal the rounded (with calculation for precision) Interest, Principle, and Balance values that're converted to string
        string IPMStr = to_string(round(1000*IPM[i])/1000); 
        string PPMStr = to_string(round(1000*PPM[i])/1000); 
        string BPMStr = to_string(round(1000*BPM[i+1])/1000);
        // Stripping extra 0's off the end of IPM String
        IPMStr.erase(IPMStr.find_last_not_of('0') + 1, string::npos);
        IPMStr.erase ( IPMStr.find_last_not_of('.') + 1, string::npos );
        // Stripping extra 0's off the end of PPM String
        PPMStr.erase(PPMStr.find_last_not_of('0') + 1, string::npos);
        PPMStr.erase ( PPMStr.find_last_not_of('.') + 1, string::npos );
        // Stripping extra 0's off the end of BPM String
        BPMStr.erase(BPMStr.find_last_not_of('0') + 1, string::npos);
        BPMStr.erase ( BPMStr.find_last_not_of('.') + 1, string::npos );
        // Appending Values to table with \t format as mentioned in the assignment PDF (thanks)
        table += "Month " + to_string(i+1) + "\t\t";
        table += "$" + IPMStr + "\t\t";
        table += "$" + PPMStr + "\t\t";
        table += "$" + BPMStr + "\n";
    }

    // Outputs the table ofc :)
    // For some reason some of the layers aren't aligned in the table though... I couldn't figure that one out but it's still organized. It has to do with the change in character size from x to xx in the month numbers.
    cout << table << endl;
}

void output_summary(double m, double total_payments, double total_interest){
    // Outputs the final totals for a summary of their payments. Also ends with a nice message.
    cout << "\nPayment Every Month: $" << m << endl;
    cout << "Total Payments: $" << total_payments << endl;
    cout << "Total Interest: $" << total_interest << endl;
    cout << "\nHope you're happy with your results!" << endl;
}



// After completing this assignment I now realized I could've avoided array usage if I made the graph function print line by line with the info per iteration instead of iterating through and appending it to an array with all the data but I just like data science and arrays I guess... oops 