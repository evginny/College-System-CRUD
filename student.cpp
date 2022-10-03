//Ginny Allen
// Definition for Student class

#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

//print out student data
ostream& operator<<(ostream& os, const Student& s){
  os << "Name:           " << s.GetNameS() << endl
     << "Student ID:     " << s.GetStudentId() << endl
     << "Major:          " << s.GetMajor() << endl
     << "Classification: " << s.GetClassification() << " year" << endl << endl;
  return os;
}

//default constructor
Student::Student(){
    NameSSize = 11;
    NameS = new char[NameSSize];
    MajorSize = 11;
    Major = new char[MajorSize];
    StudentIdSize = 6;
    StudentId = new char[StudentIdSize];
    Classification = 1;
    
}

//copy constructor
Student::Student(const Student & S){
    NameSSize = S.NameSSize;
    NameS = new char[NameSSize];
    strcpy(NameS, S.NameS);

    MajorSize = S.MajorSize;
    Major = new char[MajorSize];
    strcpy(Major, S.Major);

    StudentIdSize = S.StudentIdSize;
    StudentId = new char[StudentIdSize];
    strcpy(StudentId, S.StudentId);

    Classification = S.Classification;
}
//parameterized constructor
Student::Student(const char* _sname, int _classification, const char* _major, const char* _studentId){
    int sizeName = strlen(_sname);
    NameS = new char[sizeName + 1];
    strcpy(NameS, _sname);

    Classification = _classification;

    int sizeMajor = strlen(_major);
    Major = new char[sizeMajor + 1];
    strcpy(Major, _major);

    int sizeId = strlen(_studentId);
    StudentId = new char[sizeId + 1];
    strcpy(StudentId, _studentId);
}

//destructor - delete all dynamic arrays
Student::~Student(){
    delete [] NameS;
    delete [] Major;
    delete [] StudentId;
}


Student& Student::operator=(const Student& _student){
    delete [] NameS;
    int size = strlen(_student.NameS);
    NameS = new char[size + 1];
    strcpy(NameS, _student.NameS);

    delete [] Major;
    int sizeM = strlen(_student.Major);
    Major = new char[sizeM + 1];
    strcpy(Major, _student.Major);

    delete [] StudentId;
    int sizeS = strlen(_student.StudentId);
    StudentId = new char[sizeS + 1];
    strcpy(StudentId, _student.StudentId);

    Classification = _student.Classification;

    return *this;
}

//set student name
void Student::SetNameS(const char* _sname){
    int size = strlen(_sname);

    if (size + 1 > NameSSize){      //if number of char in the new _sname array 
        delete [] NameS;            //is greater than in the NameSSize
        NameS = new char[size + 1]; //delete NameS and create new one
    }

    strcpy(NameS, _sname);
}

char* Student::GetNameS() const{
    return NameS;
}

//set classification 
//only legal input for int _classification is 1, 2, 3 and 4
//if int _classification is something else, notify the user and set 
//Classification to 1
void Student::SetClassification(int _classification){
    if ((_classification == 1) ||   
        (_classification == 2) ||
        (_classification == 3) ||
        (_classification == 4)){
            Classification = _classification;
        }
    else {
        cout << "Invalid input. Classification is set to Freshmen." << endl;
        Classification = 1;
    }
    
}

//get classification
int Student::GetClassification() const{
    if (Classification == 1){
        cout << "Freshmen - ";
    }
    else if (Classification == 2){
        cout << "Sophomores - ";
    }
    else if (Classification == 3){
        cout << "Junior - ";
    }
    else if (Classification == 4){
        cout << "Senior - ";
    }
    return Classification;
}

//set major
void Student::SetMajor(const char* _major){
    int size = strlen(_major);

    if (size + 1 > MajorSize){      //if number of char in the _major array
        delete [] Major;            //is greater than in the MajorSize
        Major = new char[size + 1]; //delete Major dyn array and create new one
    }

    strcpy(Major, _major);
}

//get major
char* Student::GetMajor() const{
    return Major;
}

//set student ID
void Student::SetStudentId(const char* _studentId){
    int size = strlen(_studentId);

    if (size + 1 > StudentIdSize){      //if number of char in the _studentId
        delete [] StudentId;            //array is greater than in MajorSize
        StudentId = new char[size + 1]; //MajorSize delete Major dyn array and
    }                                   //create new one

    strcpy(StudentId, _studentId);
}

//get student ID
char* Student::GetStudentId() const{
    return StudentId;
}

//ask user to enter all student data
void Student::Load(){
    char* name = new char[256];
    cout << endl << "Enter the name of the student -> ";
    cin.getline(name, 256);	
    SetNameS(name);

    cout << "Enter the student ID -> ";
    char* id = new char[256];
    cin.getline(id, 256);
    SetStudentId(id);

    cout << "Enter the major -> ";
    char* major = new char[256];
    cin.getline(major, 256);
    SetMajor(major);

    cout << "Enter the student classification" << endl
         << "(1 - Freshmen, 2 - Sophomores, 3 - Junior, 4 - Senior) -> ";
    int classif;
    cin >> classif;
    cin.ignore(256, '\n');
    Classification = classif;
}


