#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// base person class
class person {
protected:    // derived classes have access to these variables
  string name;
  int age;
public:
  void getInfo(string& name, int& age) {
    this->name = name;
    this->age = age;
  }
  void displayInfo() {
    cout << "Name: " << name << ". Age: " << age << endl;
  }
};

// student class
class student : public person {    // student is a person, inherits info
private:
  string major;
  int studentID;
public:
  void getStudentInfo(string& name, int& age, string& major, int& studentID) {
    getInfo(name, age);    // display person information
    this->major = major;
    this->studentID = studentID;
  }
  void displayStudentInfo() {
    displayInfo();
    cout << "Major: " << major << endl;
    cout << "Student ID: " << studentID << endl;
  }
};

// instructor class
class classInstructor : public person {    // instructor is a person, inherits info
public:
  void getInstructorInfo(string& name, int& age) {
    getInfo(name, age);    // display person information
  }
  void displayInstructorInfo() {
    displayInfo();
  }
};

// course class
class course {
private:
  string courseID;
  classInstructor instructor;    // course has a instructor
public:
  void getCourseInfo(string& courseID, string& instructorName, int& instructorAge) {
    this->courseID = courseID;
    instructor.getInstructorInfo(instructorName, instructorAge);
  }    // uses the instructor object here
  void displayCourseInfo() {
    cout << "Course ID: " << courseID << endl;
    cout << "Instructor: ";
    instructor.displayInstructorInfo();
  }
};

int main () {
  string instructorName, courseID, studentName, studentMajor;
  int instructorAge, studentAge, studentID;

// input data
  cout << "Enter instructor's name: ";
  getline(cin, instructorName);
  cout << "\nEnter instructor's age: ";
  cin >> instructorAge;
  cout << "\nEnter course ID: ";
  cin.ignore();
  getline(cin, courseID);
  cout << "\nEnter student's name: ";
  getline(cin, studentName);
  cout << "\nEnter student's age: ";
  cin >> studentAge;
  cout << "\nEnter student's ID: ";
  cin >> studentID;
  cout << "\nEnter student's major: ";
  cin.ignore();
  getline(cin, studentMajor);
  // ^data collection^
  // cout << "\n" << instructorName << ", " << instructorAge << ", is teaching " << courseID << ". " << endl;
  // cout << "\n" << studentName << ", " << studentAge << ", student ID is " << studentID << ", and major is " << studentMajor << ". " << endl;
  // ^input data test^

// output data
  // functions to set data
  course a;
  a.getCourseInfo(courseID, instructorName, instructorAge);
  student b;
  b.getStudentInfo(studentName, studentAge, studentMajor, studentID); 
  // function to display information
  cout << "\nCourse information: " << endl;
  a.displayCourseInfo();
  cout << endl << "Student information: " << endl;
  b.displayStudentInfo();

  return 0;
};