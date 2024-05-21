#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class COP3014 {
    private:
        string first;
        string last;
        int zNum;
        double grades[6];
        bool finalTaken;
        bool midtermTaken;
        double totalGrade;
        string finalLetterGrade;
    public:
        COP3014();
        COP3014(string i_first, string i_last, int i_zNum, double i_grades[], bool i_finalTaken, bool i_midtermTaken);
        COP3014(string i_first, string i_last, int i_zNum, double i_grades[], double i_totalGrade, string i_finalLetterGrade, bool i_finalTaken, bool i_midtermTaken);
        void set_First(string i_first);
        void set_Last(string i_last);
        void set_zNum(int i_zNum);
        void set_grades(double i_grades[]);
        void set_finalFlag(bool i_finalTaken);
        void set_midtermFlag(bool i_midtermTaken);
        void set_totalGrade(double i_totalGrade);
        void set_finalLetterGrade(string i_finalLetterGrade);
        string get_First();
        string get_Last();
        int get_zNum();
        void get_grades(double (&destination)[]);
        bool get_finalFlag();
        bool get_midtermFlag();
        double get_totalGrade();
        string get_finalLetterGrade();
        void prompt_info(); // User Input Function
        double compute_totalGrade(double lab, bool base); // Total Grade Compute
        string compute_finalLetterGrade(double lab, bool base); // Compute Letter Grade
        void output_COP3014(bool base); // Output Function to Screen
};
class Spring24 : public COP3014 {
    private:
        double labGrade;
    public:
        Spring24();
        Spring24(string i_first, string i_last, int i_zNum, double i_grades[], bool i_finalTaken, bool i_midtermTaken, double i_labGrade);
        Spring24(string i_first, string i_last, int i_zNum, double i_grades[], double i_totalGrade, string i_finalLetterGrade, bool i_finalTaken, bool i_midtermTaken, double i_labGrade);
        void prompt_info(); // Redeclared user input function
        double compute_totalGrade(); // Redeclared compute function
        void output_COP3014_Spring24(); // Redeclared output function
        void set_labGrade(double i_labGrade);
        double get_labGrade();
};
int main(){
    double example_grades1[6] = {90, 94, 0, 70, 0, 90};
    double example_grades2[6] = {100, 100, 99, 100, 0, 100};
    COP3014 base_student1, base_student2("Frank", "Fabulous", 12345678, example_grades1, true, true);
    Spring24 derived_student1, derived_student2("Tina", "Traveler", 50725032, example_grades2, true, false, 50);
    base_student1.prompt_info();
    derived_student1.prompt_info();
    base_student1.output_COP3014(true);
    base_student2.output_COP3014(true);
    derived_student1.output_COP3014_Spring24();
    derived_student2.output_COP3014_Spring24();
    return 0;
}
// Constructers
COP3014::COP3014(): first("John"), last("Doe"), zNum(00000000), totalGrade(100), finalLetterGrade("A"), finalTaken(true), midtermTaken(true){
    for (int i = 0; i < 6; i++){
        grades[i] = 100;}}
COP3014::COP3014(string i_first, string i_last, int i_zNum, double i_grades[], bool i_finalTaken, bool i_midtermTaken): first(i_first), last(i_last), zNum(i_zNum), finalTaken(i_finalTaken), midtermTaken(i_midtermTaken){
    for (int i = 0; i < 6; i++){
        grades[i] = i_grades[i]; }}
COP3014::COP3014(string i_first, string i_last, int i_zNum, double i_grades[], double i_totalGrade, string i_finalLetterGrade, bool i_finalTaken, bool i_midtermTaken): first(i_first), last(i_last), zNum(i_zNum), totalGrade(i_totalGrade), finalLetterGrade(i_finalLetterGrade), finalTaken(i_finalTaken), midtermTaken(i_midtermTaken){
    for (int i = 0; i < 6; i++){
        grades[i] = i_grades[i];}}
Spring24::Spring24(): COP3014(), labGrade(100) {}
Spring24::Spring24(string i_first, string i_last, int i_zNum, double i_grades[], bool i_finalTaken, bool i_midtermTaken, double i_labGrade): COP3014(i_first, i_last, i_zNum, i_grades, i_finalTaken, i_midtermTaken), labGrade(i_labGrade) {}
Spring24::Spring24(string i_first, string i_last, int i_zNum, double i_grades[], double i_totalGrade, string i_finalLetterGrade, bool i_finalTaken, bool i_midtermTaken, double i_labGrade): COP3014(i_first, i_last, i_zNum, i_grades,i_totalGrade, i_finalLetterGrade, i_finalTaken, i_midtermTaken), labGrade(i_labGrade) {}
void COP3014::set_First(string i_first){
    first = i_first;}
void COP3014::set_Last(string i_last){
    last = i_last;}
void COP3014::set_zNum(int i_zNum){
    zNum = i_zNum;}
void COP3014::set_grades(double i_grades[]){
    for (int i = 0; i < 6; i++){
        grades[i] = i_grades[i];
    }}
void COP3014::set_totalGrade(double i_totalGrade){
    totalGrade = i_totalGrade;}
void COP3014::set_finalFlag(bool i_finalTaken){
    finalTaken = i_finalTaken;}
void COP3014::set_midtermFlag(bool i_midtermTaken){
    midtermTaken = i_midtermTaken;}
void COP3014::set_finalLetterGrade(string i_finalLetterGrade){
    finalLetterGrade = i_finalLetterGrade;}
void Spring24::set_labGrade(double i_labGrade){
    labGrade = i_labGrade;}
string COP3014::get_First(){
    return first;}
string COP3014::get_Last(){
    return last;}
int COP3014::get_zNum(){
    return zNum;}
void COP3014::get_grades(double (&destination)[]){
    for (int i = 0; i < 6; i++){
        destination[i] = grades[i];}}
bool COP3014::get_finalFlag(){
    return finalTaken;}
bool COP3014::get_midtermFlag(){
    return midtermTaken;}
double COP3014::get_totalGrade(){
    return totalGrade;}
string COP3014::get_finalLetterGrade(){
    return finalLetterGrade;}
double Spring24::get_labGrade(){
    return labGrade;}
double COP3014::compute_totalGrade(double lab, bool base){
    double assign1 = grades[0], assign2 = grades[1], assign3 = grades[2], assign4 = grades[3], midterm = grades[4], final = grades[5];
    if (midtermTaken == false){
        midterm = 0;
    }
    if (finalTaken == false){
        final = 0;
    }
    if (base == true){
        double total = ((assign1 + assign2 +assign3 + assign4)/4.0) * 0.25 + midterm *0.3 + final * 0.45;
        return total;
    }
    else if (base == false){
        double total = ((assign1 + assign2 +assign3 + assign4)/4.0) * 0.25 + midterm *0.25 + final * 0.4 + lab *0.1;
        return total;
    }}
double Spring24::compute_totalGrade(){
    return COP3014::compute_totalGrade(labGrade, false);}
string COP3014::compute_finalLetterGrade(double lab, bool base){
    double total;
    if (base == true){
        total = compute_totalGrade(0, true);
    }
    else if (base == false){
        total = compute_totalGrade(lab, false);
    }
    string Grade;
    if (total >= 90 && total <= 100){ Grade = "A"; }
    else if (total >= 87 && total < 90){ Grade = "A-"; }
    else if (total >= 83 && total < 87){ Grade = "B+"; }
    else if (total >= 80 && total < 83){ Grade = "B"; }
    else if (total >= 77 && total < 80){ Grade = "B-"; }
    else if (total >= 73 && total < 77){ Grade = "C+"; }
    else if (total >= 70 && total < 73){ Grade = "C"; }
    else if (total >= 67 && total < 70){ Grade = "C-"; }
    else if (total >= 63 && total < 67){ Grade = "D+"; }
    else if (total >= 60 && total < 63){ Grade = "D"; }
    else if (total >= 51 && total < 60){ Grade = "D-"; }
    else if (total <= 50){ Grade = "F"; }
    else{ Grade = "A - Above 100%"; }
    if (finalTaken == false){ Grade = "F"; }
    if (midtermTaken == false && (Grade == "C+" || Grade == "B-" || Grade == "B" || Grade == "B+" || Grade == "A-" || Grade == "A" || Grade == "A - Above 100%")){
        Grade = "C";
    } return Grade;}
void COP3014::prompt_info(){
    cout << "\nWhat is the students First and Last name? (separate by space - i.e. 'John Doe') \n>";
    cin >> first >> last;
    cout << "\nWhat is the students Z-Number? (Do not include the Z. Only put the 8 digits following - i.e. '12345678') \n>";
    cin >> zNum;
    cout << "\nDid the student complete Midterm? (Type ONLY 0 for No and 1 for Yes)\n>";
    cin >> midtermTaken;
    cout << "\nDid the student complete Final? (Type ONLY 0 for No and 1 for Yes)\n>";
    cin >> finalTaken;
    for (int i = 0; i < 6; i++){
        if (i == 4){
            cout << "\nWhat percent grade did the student get on their Midterm? (Simply write the percentage as a number between 0 and 100 WITHOUT a percentage symbol) \n>";
            cin >> grades[i];
        }
        else if (i == 5){
            cout << "\nWhat percent grade did the student get on their Final? (Simply write the percentage as a number between 0 and 100 WITHOUT a percentage symbol) \n>";
            cin >> grades[i];
        }
        else{
            cout << "\nWhat percent grade did the student get on assignment " << i+1 << "? (Simply write the percentage as a number between 0 and 100 WITHOUT a percentage symbol)\n>";
            cin >> grades[i];
        }}}
void Spring24::prompt_info(){
    COP3014::prompt_info();
    cout << "\nWhat percent grade did the student get on their Lab? (Simply write the percentage as a number between 0 and 100 WITHOUT a percentage symbol) \n>";
    cin >> labGrade;}
void COP3014::output_COP3014(bool base){
    cout << setprecision(2) << fixed;
    cout << "\n\n" << first << " " << last << " - " << zNum << endl;
    cout << "\tAssign 1: " << grades[0] << endl;
    cout << "\tAssign 2: " << grades[1] << endl;
    cout << "\tAssign 3: " << grades[2] << endl;
    cout << "\tAssign 4: " << grades[3] << endl;
    if (midtermTaken == false){
        cout << "\tMidterm: 0 - NOT TAKEN" << endl;
    }
    else{
        cout << "\tMidterm: " << grades[4] << endl;
    }
    if (finalTaken == false){
        cout << "\tFinal: 0 - NOT TAKEN" << endl;
    }
    else{
        cout << "\tFinal: " << grades[5] << endl;
    }
    if (base == true){
        cout << "\tTotal grade: " << compute_totalGrade(0, true) << endl;
        cout << "\tFinal grade: " << compute_finalLetterGrade(0, true) << endl;
    }} // BASE CLASS ALL WORKS FIRST TRY YAY
void Spring24::output_COP3014_Spring24(){
    COP3014::output_COP3014(false);
    cout << "\tLab: " << labGrade << endl;
    cout << "\tTotal grade: " << compute_totalGrade() << endl;
    cout << "\tFinal grade: " << compute_finalLetterGrade(labGrade, false) << endl;} // Took a unique route  on the implementation of each Spring24 function and it works perfectly!! :)