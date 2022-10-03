// Ginny Allen
// Contains the declaration for CourseList class
// Course List class provides basic CRUD functionality 
// for objects of Course class

#include <iostream>
#include "course.h"

using namespace std;

class CourseList{
    friend ostream& operator<<(ostream& os, CourseList& cList);
    public:
        //default constructor
        CourseList();
        //destructor
        ~CourseList();

        //grow course Record by 1
        void Grow();

        //ask an user to input all data for the course and then add it 
        //to the Record
        void AddCourse();

        //add one course to the Record
        void AddCourse(const Course& course);

        //update a specific course - including editing course data, editing
        //students' data in this course, as well as adding and removing
        //in/from the course roster
        void UpdateCourse();

        //edit course data
        void EditCourse(int& indexCourse);

        //remove a specific course and all its data from the Record
        void RemoveCourse();

        //add one student to the course 
        void AddStudent(int& indexCourse);
        //locate a student in the course roster
        int FindStudent(int& indexCourse);
        //edit student data
        void EditStudent(int& indexStudent, int& indexCourse);
        
        //locate a course in the Record
        int FindCourse();
        
        //get current number of students in the Record
        int GetCurrentNumber();

        //print out student data
        void PrintStudent(int& indexStudent, int& indexCourse);
        //print out coure data
        void PrintCourse(int& indexCourse);

    private:
        //functions:

        //locate course name in the Record
        int FindCourseName(const char* courceName);    
        //locate couse code in the Record 
        int FindCourseCode(const char* courseCode);
        //locate course location in the Record
        int FindCourseLocation(const char* courseLoc);

        //member data:

        int CurrentNumber;  //to hold number current number of courses in
                            //the Record
        int MaxNumber;      //to hold max number of courses in the Record
        Course* Record;     //list of courses

};