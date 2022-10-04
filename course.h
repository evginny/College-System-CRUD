// Declaration for Course Class
// Contsins basic information about courses, and the roseter
// that holds a list of students who are taking these courses

#include <iostream>
#include "student.h"
using namespace std;

class Course {
    //friend function
    friend ostream& operator<<(ostream& s, const Course& c);

    public:
        //default constructor
        Course();
        //parameterized constructor
        Course(const char* _name, const char* _code, const char* _location);
        //copy constructor
        Course(const Course &);
        //destructor
        ~Course();

        Course& operator=(const Course& course);


        char* GetName() const;              //get course name
        const char* GetCode() const;        //get course code
        const char* GetLocation() const;    //get course location

        int GetCurrentRoster() const;       //get number of student in the 
                                            //roster

        void SetName(const char* _name);    //set course name
        void SetCode(const char* _code);    //set course code
        void SetLocation(const char* _location);    //set course location

        void AddStudent(const Student& _student);   //add one student to the
                                                    //course roster


        void PrintStudent() const;  //print all students in the roster
        //print specific student from the roster
        void PrintSpecificStudent(int& index) const;    

        void UpdateStudentName(int& indexS);    //update student name
        void UpdateStudentID(int& indexS);      //update student ID
        void UpdateStudentMajor(int& indexS);   //update student major
        void UpdateStudentClassif(int& indexS); //update student classification

        void RemoveStudent(int& indexS);    //remove a specific student from
                                            //the roster
        
        //ask user to enter all course data
        void Load();
        //locate a student name in the roster
        int FindStudentName(const char* _name) const;
        //locate a student ID in the roster
        int FindStudentId(const char* _id) const;

    private:
        char* NameC;        //to hold course name
        int NameCSize;      //to hold a number of char in NameC
        char CourseCode[8]; //to hold course code
        char Location[11];  //to hold course location
        Student* Roster;    //to hold a list of student
        int MaxRoster;      //to hold a max number of student in the roster
		int CurrentRoster;  //to hold a current number of student in the roster
};