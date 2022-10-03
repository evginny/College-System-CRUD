// Ginny Allen
// Definition for CourseList class 

#include <iostream>
#include <cstring>
#include "courseList.h"

using namespace std;

ostream& operator<<(ostream& os, CourseList& cList){
    os << "Course List:" << endl << endl;
    for (int i = 0; i < cList.CurrentNumber; i++){
        os << "Course " << i + 1 << ": " << endl 
           << cList.Record[i] << endl;
    }
    return os;
}

//default constructor
CourseList::CourseList(){
    CurrentNumber = 0;
    MaxNumber = 2;

    Record = new Course[MaxNumber];
}

//destructor
CourseList::~CourseList(){
    delete [] Record;
}

//encrease number of courses in the Record by one
void CourseList::Grow(){
    MaxNumber = CurrentNumber + 1;
    Course* newRecord = new Course[MaxNumber];

    for (int i = 0; i < CurrentNumber; i++){
        newRecord[i] = Record[i];
    }
    delete [] Record;
    Record = newRecord;
}

//ask an user to input all course data and add this course to the Record
void CourseList::AddCourse(){
    Course c;
    c.Load();
    AddCourse(c);
}

//add course to the Record
//if the current number of courses is greater than the max number, grow Record
void CourseList::AddCourse(const Course& c){

    if (CurrentNumber == MaxNumber){
        Grow();
    }
    Record[CurrentNumber] = c;
    CurrentNumber++;
}

//get current number of courses in the Record
int CourseList::GetCurrentNumber(){
    return CurrentNumber;
}

//locate a name in the Record. Returns the
//position of the course as an integer if found.
//and returns -1 if the course is not found in the Record
int CourseList::FindCourseName(const char* courseName){
    for (int i = 0; i < CurrentNumber; i++){
        if (strcmp(Record[i].GetName(), courseName) == 0){
            return i;
        }
    }
    return -1;
}

//locate a course code in the Record. Returns the
//position of the course as an integer if found.
//and returns -1 if the course is not found in the Record
int CourseList::FindCourseCode(const char* courseCode){
    for (int i = 0; i < CurrentNumber; i++){
        if (strcmp(Record[i].GetCode(), courseCode) == 0){
            return i;
        }
    }
    return -1;
}

//locate a course location in the Record. Returns the
//position of the course as an integer if found.
//and returns -1 if the course is not found in the Record
int CourseList::FindCourseLocation(const char* courseLoc){
    for (int i = 0; i < CurrentNumber; i++){
        if (strcmp(Record[i].GetLocation(), courseLoc) == 0){
            return i;
        }
    }
    return -1;
}

//update a specific course - including editing course data, editing
//students' data in this course, as well as adding and removing
//in/from the course roster
void CourseList::UpdateCourse(){
    int indexC;     //location of the course
    int indexS;     //location of the student
    int option;     //option for updating course
    int choice;     //option if user wants to continue updating

    //if Record is empty, just notify an user
    if (CurrentNumber == 0){
        cout << endl;
        cout << "Course list is empty. Please add at leat one corse first." 
             << endl;
    }
    else{ //if Record has at least one course
        cout << endl;
        cout << "Let's find a course you would like to update." << endl
             << "How would you like to search for this course?" << endl;
        indexC = FindCourse(); //find a location of the course
        if (indexC != -1){     //continue only if a course was found
            do {
                cout << endl << "Please select an option:" << endl
                     << "1 - edit course data" << endl
                     << "2 - edit student data in the course" << endl
                     << "3 - add students" << endl
                     << "4 - remove students" << endl
                     << "Enter the option -> ";
                cin >> option;
                while ((option != 1) && (option != 2) && 
                       (option != 3) && (option != 4)){
                    cout << "Invalid option. Please enter again -> ";
                    cin >> option;
                }
                cin.ignore(256, '\n');
                switch (option){
                    case 1: //edit course data
                    {
                        EditCourse(indexC);
                        break;
                    }
                    case 2: //edit student data in the course
                    {   if (Record[indexC].GetCurrentRoster() == 0){
                            cout << endl 
                                 << "There are no students in this course." 
                                 << endl;
                        }
                        else {
                            cout << endl 
                                 << "Let's find a student record that you "
                                 << "would like to edit." << endl;
                            indexS = FindStudent(indexC);
                            if (indexS != -1){
                                EditStudent(indexS, indexC);
                            }
                        }
                        break;
                    }
                    case 3: //add a student
                    {
                        AddStudent(indexC);
                        break;
                    }
                    case 4: //remove a student if roster contains at least one
                    {
                        if (Record[indexC].GetCurrentRoster() == 0){
                            cout << endl 
                                 << "There is no students in this course "
                                 << "roaster." << endl;
                        }
                        else {
                            cout << endl 
                                 << "Let's find a student that you would like "
                                 << "to delete." << endl;
                            indexS = FindStudent(indexC);
                            if (indexS != -1){
                                Record[indexC].RemoveStudent(indexS);
                            }
                        }
                        break;
                    }
                    default:
                        cout <<"Error! Invalid input." << endl;                        
                }
                cout << endl << "Would you like to continue updating this "
                     << "course?" << endl
                     << "If YES, enter 1" << endl
                     << "If NO, enter 0" << endl
                     << "Enter the option -> ";
                cin >> choice;
                while ((choice != 0) && (choice !=1)){
                    cout << "Invalid option. Please enter again -> ";
                    cin >> choice;
                }
            } while(choice != 0);    
        }
    }
}

//print out student data 
void CourseList::PrintStudent(int& indexS, int& indexC){
    Record[indexC].PrintSpecificStudent(indexS);
}

//edit student data - name, ID, major, classification
void CourseList::EditStudent(int& indexStudent, int& indexCourse){
    int option;     //option for editing
    int choice;     //option if the user wants to continue editing this student
    cout << endl << "Student data:" << endl;
    Record[indexCourse].PrintSpecificStudent(indexStudent);
    do {
        cout << endl << "Please select an option:" << endl
             << "1 - edit student name" << endl
             << "2 - edit student ID" << endl
             << "3 - edit student major" << endl
             << "4 - edit student classification" << endl
            << "Enter the option -> ";
        cin >> option;
        while ((option != 1) && (option != 2) && 
            (option != 3) && (option != 4)){
            cout << "Invalid option. Please enter again -> ";
            cin >> option;
        }
        cin.ignore(256, '\n');
        switch (option){
            case 1:
            {
                Record[indexCourse].UpdateStudentName(indexStudent);
                break;
            }
            case 2:
            {
                Record[indexCourse].UpdateStudentID(indexStudent);
                break;
            }
            case 3:
            {
                Record[indexCourse].UpdateStudentMajor(indexStudent);
                break;
            }
            case 4:
            {
                Record[indexCourse].UpdateStudentClassif(indexStudent);
                break;
            }
            default:
                cout <<"Error! Invalid input." << endl;
        }
        cout << endl << "Would you like to continue editing this student?" 
                     << endl
                     << "If YES, enter 1" << endl
                     << "If NO, enter 0" << endl
                     << "Enter the option -> ";
        cin >> choice;
        while ((choice != 0) && (choice !=1)){
            cout << "Invalid option. Please enter again -> ";
            cin >> choice;
        }
         
    } while (choice != 0);

    cout << endl << "Updated student data:" << endl;
    Record[indexCourse].PrintSpecificStudent(indexStudent);
}

//edit course data - name, code, location
void CourseList::EditCourse(int& index){
    int option;     //option for editing
    int choice;     //option if the user wants to continue editing this course
    cout << endl << "Course data:" << endl;
    cout << Record[index] << endl;
    do {
        cout << endl << "Please select an option:" << endl
             << "1 - edit course name" << endl
             << "2 - edit course code" << endl
             << "3 - edit course location" << endl
             << "Enter the option -> ";
        cin >> option;
        while ((option != 1) && (option != 2) && 
               (option != 3)){
            cout << "Invalid option. Please enter again -> ";
            cin >> option;
        }
        cin.ignore(256, '\n');
        switch (option){
            case 1:
            {
                cout << "Enter a new name -> ";
                char* name = new char[256];
                cin.getline(name, 256);
                Record[index].SetName(name);
                break;
            }
            case 2:
            {
                cout << "Enter a new code -> ";
                char code[8];
                cin.getline(code, 8);
                Record[index].SetCode(code);
                break;
            }
            case 3:
            {
                cout << "Enter a new location -> ";
                char location[11];
                cin.getline(location, 11);
                Record[index].SetLocation(location);
                break;
            }
            default:
                cout <<"Error! Invalid input." << endl;
        }
        cout << endl << "Would you like to continue editing this course?"
                     << endl
                     << "If YES, enter 1" << endl
                     << "If NO, enter 0" << endl
                     << "Enter the option -> ";
                cin >> choice;
                while ((choice != 0) && (choice !=1)){
                    cout << "Invalid option. Please enter again -> ";
                    cin >> choice;
                }
    } while(choice != 0);
    cout << endl << "The updated course data: " << endl;
    cout << Record[index];
    cout << endl;
}

//add students to a course
void CourseList::AddStudent(int& indexC){
    int choice;
    if (CurrentNumber == 0){
        cout << endl;
        cout << "Course list is empty. Please add at leat one course first." 
             << endl;
    }
    else {
        do {
            Student s;
            s.Load();
            Record[indexC].AddStudent(s);
            cout << endl << "Would you like to add more students to this "
                 << "course?" << endl
                 << "If YES, enter 1" << endl
                 << "If NO, enter 0" << endl
                 << "Enter the option -> ";
            cin >> choice;
            while ((choice != 0) && (choice != 1)){
                cout << "Invalid option. Please enter again -> ";
                cin >> choice;
            }
            cin.ignore(256, '\n'); 
        } while (choice != 0);
    }
}

//print out course data if it exists
void CourseList::PrintCourse(int& indexC){
    if (indexC == -1){
        return;
    }
    cout << Record[indexC];
}

//locate a course in the Record. Returns the
//position of the course as an integer if found.
//and returns -1 if the course is not found in the Record
int CourseList::FindCourse(){
    int option;     //option for how to find a course
    int index;      //location of the course
    cout << endl << "Please select an option:" << endl
         << "1 - search by name" << endl
         << "2 - search by course code" << endl
         << "3 - search by location" << endl
         << "Enter the option ->";
    cin >> option;
    while ((option != 1) && (option != 2) && (option != 3)){
        cout << "Invalid option. Please enter again -> ";
        cin >> option;
    }
    cin.ignore(256, '\n');

    switch (option) {
        case 1:
        {
            cout << "Please enter the name of the course -> ";
            char* courseName = new char[256];
            cin.getline(courseName, 256);
            index = FindCourseName(courseName);
            break;
        }
        case 2:
        {
            cout << "Please enter the code of the course -> ";
            char courseCode[8];
            cin.getline(courseCode, 8);
            index = FindCourseCode(courseCode);
            break;
        }
        case 3:
        {
            cout << "Please enter the location of the course -> ";
            char courseLocation[11];
            cin.getline(courseLocation, 11);
            index = FindCourseLocation(courseLocation);
            break;
        }
        default:
            cout <<"Error! Invalid input." << endl;
    }
    if(index == -1){
        cout << "The course is not found." << endl;
    }
    return index;
}

//remove a course from the Record by asking an user to input course code
void CourseList::RemoveCourse(){
    cout << "Please enter the course code of course you wish to remove -> ";
    char courseCode[8];
    cin.getline(courseCode, 8);
    int indexC = FindCourseCode(courseCode);
    if (indexC == 1){
        cout << endl << "The course is not found." << endl;
    }
    else {
        for (int i = indexC + 1; i < CurrentNumber; i++){
            Record[i - 1] = Record[i];
        }
        CurrentNumber--;
        cout << endl << "Course is removed" << endl;
    }
}

//locate a student location in the Roster. Returns the
//position of the course as an integer if found.
//and returns -1 if the course is not found in the roster
int CourseList::FindStudent(int& courseIndex){
    int option;     //option for how to search for student
    int indexS;     //location of the student in the roster
    cout << endl << "Please select an option:" << endl
         << "1 - search by name" << endl
         << "2 - search by student ID" << endl
         << "Enter the option ->";
    cin >> option;
    while ((option != 1) && (option != 2)){
        cout << "Invalid option. Please enter again -> ";
        cin >> option;
    }
    cin.ignore(256, '\n');

    switch (option) {
        case 1:
        {
            cout << endl;
            cout << "Please enter the name of the student -> ";
            char* _name = new char[256];
            cin.getline(_name, 256);
            indexS = Record[courseIndex].FindStudentName(_name);
            break;
        }
        case 2:
        {
            cout << endl;
            cout << "Please enter the student ID -> ";
            char * _id = new char[256];
            cin.getline(_id, 256);
            indexS = Record[courseIndex].FindStudentId(_id);
            break;
        }
        default:
            cout <<"Error! Invalid input." << endl;
    }
    if (indexS == -1){
        cout << endl << "Student is not found." << endl;
    }
    return indexS;
}