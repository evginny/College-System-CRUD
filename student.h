// Ginny Allen
// declaration of the Student class
// Contains Student class that contains basic information about students

#include <iostream>
using namespace std;

class Student {

    friend ostream& operator<<(ostream& s, const Student& c);
    public:
        Student();  //default constructor

        //parameterized constructor
        Student(const char* _sname, int _classification,
                const char* _major, const char* _studentId);

        Student(const Student &); //copy constructor
        ~Student();  //destructor

        Student& operator=(const Student& _student);

        void SetNameS(const char* _sname);  //set student name
        char* GetNameS() const;  //get student name

        void SetClassification(int _classification); //set classification
        int GetClassification() const; //get classification

        void SetMajor(const char* _major); //set major
        char* GetMajor() const; //get major

        void SetStudentId(const char* _studentId); //set student ID
        char* GetStudentId() const; //get student ID

        void Load();  //ask user to enter all student data

     // delete   void StudentPrint();

    private:

        char* NameS;         //to hold student name
        int NameSSize;      //to hold number of char in the NameS dynamic array

        char* Major;        //to hold major
        int MajorSize;      //to hold number of char in the Major dynamic array

        char* StudentId;    //to hold student ID
        int StudentIdSize;  //to hold number of char 
                            //in the StudentIdSize dynamic array 

        int Classification; //to hold student classification

};