// Driver programm for CRUD functionality

#include <iostream>
#include <cstring>
#include "courseList.h"
using namespace std;

void ShowMenu(); 

int main(){
    int opt,        //to hold user option
        choice;     //option if user wants to continue or exit 
    int indexC,     //location of the course in the course list (Record)
        indexS;     //location of the student in the roster

    cout << "========================================================" << endl;
    cout << "=================WELCOME TO THE PROGRAM=================" << endl;
    cout << "========================================================" << endl;
    CourseList list;
    do {
        ShowMenu();
        cout << endl << "Please enter the option -> ";
        cin >> opt;
        while ((opt < 0) || (opt > 8)){
            cout << "Invalid input. Please enter the number again." << endl;
            cin >> opt;
        }
        cin.ignore(256, '\n');
        switch (opt){
            case 1: //add a course
            {
                list.AddCourse();
                break;
            }//------------------------------------------------------
            case 2: //add students to a course if it exists
            {
                if (list.GetCurrentNumber() == 0){
                    cout << endl;
                    cout << "Course list is empty. Please add at leat one course first." << endl;
                }
                else {
                    cout << "First, let's find a course you would like to add "
                         << "students to!" << endl
                         << "How would you like to search for it?" << endl;
                    indexC = list.FindCourse();
                    if (indexC != -1){
                        list.AddStudent(indexC);
                    }
                }
                break;
            }//------------------------------------------------------
            case 3:  //update a course
            {
                list.UpdateCourse();
                break;
            }//------------------------------------------------------
            case 4: //print all courses
            {
                cout << list << endl;
                break;
            }//------------------------------------------------------
            case 5: //find a student by name or student ID
            {
                cout << endl << "First, let's find a course where the student is." << endl;
                indexC = list.FindCourse();
                if (indexC != -1){
                    indexS = list.FindStudent(indexC);
                    if (indexS != -1){
                        cout << endl << "Found student:" << endl;
                        list.PrintStudent(indexS, indexC);
                    }
                }
                break;
            }//------------------------------------------------------
            case 6: //find a course by name, course code, or location
            {
                indexC = list.FindCourse();
                if (indexC != -1){
                    cout << endl;
                    cout << "Found course: " << endl;
                    list.PrintCourse(indexC);
                }
                break;
            }//------------------------------------------------------
            case 7: //remove a course from the list by its code
            {
                cout << list;
                cout << endl;
                list.RemoveCourse();
                break;
            }
            case 0:
                cout << endl
                     << "Thank you for using the program! See you soon!" 
                     << endl;
        }
        cout << endl << "Would you like to see a nemu again?" << endl
             << "If YES, please enter 1" << endl
             << "If you would like to exit the program, please enter 0" << endl
             << "Enter the option -> ";
        cin >> choice;
                while ((choice != 0) && (choice !=1)){
                    cout << "Invalid option. Please enter again -> ";
                    cin >> choice;
                }
    } while(choice != 0);
    cout << endl << "Thank you for using the program! See you soon!" << endl;
}

void ShowMenu(){
    cout << endl;
    cout << "Please select an option: " << endl
         << "1 - add a course" << endl
         << "2 - add students to a course" << endl
         << "3 - update a course" << endl
         << "4 - print all courses" << endl
         << "5 - find a student by name or student ID" << endl
         << "6 - find a course by name, course code, or location" << endl
         << "7 - remove a course from the list" << endl 
         << "0 - exit the program" << endl;
}
