// Definition for Course class

#include <iostream>
#include <cstring>  //for C-strings
#include "course.h"

using namespace std;

//default constructor
Course::Course(){
    NameCSize = 26;
    NameC = new char[NameCSize];
    MaxRoster = 2;
    Roster = new Student[MaxRoster];
    strcpy(CourseCode, "");
    strcpy(Location, "");

    CurrentRoster = 0;
}

//parameterized constructor
Course::Course(const char* _name, const char* _code, const char* _location){
    int nameCSize = strlen(_name);
    NameC = new char[nameCSize + 1];
    strcpy(NameC, _name);

    MaxRoster = 2;
    Roster = new Student[MaxRoster];

    strcpy(CourseCode, _code);
    strcpy(Location, _location);

    CurrentRoster = 0;
 } 

//copy constructor
Course::Course(const Course & C){
    NameCSize = C.NameCSize;
    NameC = new char[NameCSize];
    strcpy(NameC, C.NameC);

    strcpy(CourseCode, C.CourseCode);
    strcpy(Location, C.Location);

    MaxRoster = C.MaxRoster;
    CurrentRoster = C.CurrentRoster;

    Roster = new Student[MaxRoster];

    for (int i = 0; i < CurrentRoster; i++){
        Roster[i] = C.Roster[i];
    }
}

//destructor - delete all dynamic arrays
Course::~Course(){
    delete [] NameC;
    delete [] Roster;
}

//print out course data
ostream& operator<<(ostream& s, const Course& c){
    s << "Name:     " << c.GetName() << endl
      << "Code:     " << c.GetCode() << endl
      << "Location: " << c.GetLocation() << endl
      << "Roster:   " << endl;
      c.PrintStudent();
    return s;
}

//print all students in the roster
//if roster is empty - notify the user
void Course::PrintStudent() const{
    if (CurrentRoster == 0){
        cout << "Current roster is empty." << endl;
        return;
    }
    int num = 1;
    for (int i = 0; i < CurrentRoster; i++){
        cout << "***********************************" << endl;
        cout << "Student " << num << ": " << endl;
        cout << Roster[i];
        cout << "***********************************" << endl;
        num ++;
    }
}

//print specific student from the roster
//if index of the student is -1 - notify the user that this
//student is not found
void Course::PrintSpecificStudent(int& indexS) const{
    if (indexS == -1){
        cout << "No data found." << endl;
        return;
    }
    cout << Roster[indexS];
}

//update student name by asking an user to input new student name
void Course::UpdateStudentName(int& indexS){
    cout << "Enter a new student name -> ";
    char* nameS = new char[256];
    cin.getline(nameS, 256);	
    Roster[indexS].SetNameS(nameS);
}

//update student ID by asking an user to input new student ID
void Course::UpdateStudentID(int& indexS){
    cout << "Enter a new student ID -> ";
    char* id = new char[256];
    cin.getline(id, 256);
    Roster[indexS].SetStudentId(id);
}

//update student major by asking an user to input new student major
void Course::UpdateStudentMajor(int& indexS){
    cout << "Enter a new major -> ";
    char* major = new char[256];
    cin.getline(major, 256);
    Roster[indexS].SetMajor(major);
}

//update student classification by asking an user
//to input new student classification
void Course::UpdateStudentClassif(int& indexS){
    int classific;
    cout << "Enter a new student classification" << endl
         << "(1 - Freshmen, 2 - Sophomores, 3 - Junior, 4 - Senior) -> ";
    cin >> classific;
    cin.ignore(256, '\n');
    Roster[indexS].SetClassification(classific);
}

//ask an user to input course name, course code, and course location
void Course::Load(){
    char* name = new char[256];
    cout << "Enter the name of the course -> ";
    cin.getline(name, 256);	
    SetName(name);
    cout << endl;

    cout << "Enter the code of the course -> ";
    char code[8];
    cin.getline(code, 8);
    SetCode(code);
    cout << endl;

    cout << "Enter the location of the course -> ";
    char location[11];
    cin.getline(location, 11);
    SetLocation(location);
    cout << endl;
}

//set course name
void Course::SetName(const char* _name){
    int size = strlen(_name);

    if (size + 1 > NameCSize){      //if number of char in the _name is greater
        delete [] NameC;            //then number in NameCSize, delete dynamic
        NameC = new char[size + 1]; //array NameC and create a new one
    }
    strcpy(NameC, _name);
}

//get course name
char* Course::GetName() const{
    return NameC;
}

//set course code
//if number of char in _code is greater or less than 7, notify an user and
//leave CourseCode blank or with its previous value
void Course::SetCode(const char* _code){
    int size = strlen(_code);

    if (size != 7){    
        cout << "The Course Code is invalid." << endl;
    }
    else {

        strcpy(CourseCode, _code);
    }
} 

//get course code
const char* Course::GetCode() const{
    return CourseCode;
}

//set course location
//if the number of characters in the _location char array is greater than 10,
//notify an user, and leave Location blank or with previous value
void Course::SetLocation(const char* _location){
    int size = strlen(_location);

    if (size > 10){
        cout << "The Location is invalid." << endl;
    }
    else {
        strcpy(Location, _location);
    }
}

//get course location
const char* Course::GetLocation() const{
    return Location;
}

//add one student to the course roster
//if number of student in the roster is equal to the max number of student,
//grow Roster by adding 10 more students to it
void Course::AddStudent(const Student& _student){
    if (CurrentRoster == MaxRoster){
        int newSize = MaxRoster + 10;
        Student* newRoster = new Student[newSize];

        for (int i = 0; i < CurrentRoster; i++){
            newRoster[i] = Roster[i];
        }

        delete [] Roster;
        Roster = newRoster;
        MaxRoster = newSize;
    }

    Roster[CurrentRoster] = _student;
    CurrentRoster++;
} 

Course& Course::operator=(const Course& course){
    if (this != &course){

        delete [] NameC;
        int size = strlen(course.NameC);
        NameC = new char[size + 1];
        strcpy(NameC, course.NameC);
        strcpy(CourseCode, course.CourseCode);
        strcpy(Location, course.Location);


       

        Roster = new Student[MaxRoster];

        for (int i = 0; i < course.CurrentRoster; i++){
            Roster[i] = course.Roster[i];
        }
    }
    return *this;
}


//locate a name in the roster.  Returns the
//position of the student as an integer if found.
//and returns -1 if the student is not found in the roster.
int Course::FindStudentName(const char* _name) const{
    for (int i = 0; i < CurrentRoster; i++){
        if (strcmp(Roster[i].GetNameS(), _name) == 0)
            return i;   
    }
    return -1;
}

//locate a student ID in the roster.  Returns the
//position of the student as an integer if found.
//and returns -1 if the student is not found in the roster.
int Course::FindStudentId(const char* _id) const{
    for (int i = 0; i < CurrentRoster; i++){
        if (strcmp(Roster[i].GetStudentId(), _id) == 0)
            return i;
    }
    return -1;
}

//remove a specific student from the course toster
void Course::RemoveStudent(int& indexS){
    for (int i = indexS + 1; i < CurrentRoster; i++){
        Roster[i - 1] = Roster[i];
    }
    CurrentRoster--;
    cout << "Student data is deleted." << endl;
}

//get number of students in the roster
int Course::GetCurrentRoster() const{
    return CurrentRoster;
}
