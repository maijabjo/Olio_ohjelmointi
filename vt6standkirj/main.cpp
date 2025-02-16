#include <iostream>
#include "Student.h"
#include "student.cpp"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
  int selection =0;
  vector<Student>studentList;

  do
    {
      cout<<endl;
      cout<<"Select"<<endl;
      cout<<"Add students = 0"<<endl;
      cout<<"Print all students = 1"<<endl;
      cout<<"Sort and print students according to Name = 2"<<endl;
      cout<<"Sort and print students according to Age = 3"<<endl;
      cout<<"Find and print student = 4"<<endl;
      cin>>selection;

      switch(selection)

      {
      case 0:
      {
          string name;
          int age;
          cout << "What is the student's name? ";
          cin >> name;
          cout << "What is the student's age? ";
          cin >> age;

          Student newStudent(name, age);
          studentList.push_back(newStudent);
          break;
      }
      case 1:
      {
          cout << "The list of all students:" << endl;
          for (Student& student : studentList) {
              student.printStudentInfo();
          }
          break;
      }

      case 2:
      {
          sort(studentList.begin(), studentList.end(),
                   [](Student& a, Student& b) {
                       return a.getName() < b.getName();
                   });

          cout << "The list of all students sorted by name:" << endl;
          for (Student& student : studentList) {
              student.printStudentInfo();
          }
          break;
      }

      case 3:
      {
          sort(studentList.begin(), studentList.end(),
               [](Student& a, Student& b) {
                   return a.getAge() < b.getAge();
               });

          cout << "The list of all students sorted by age:" << endl;
          for (Student& student : studentList) {
              student.printStudentInfo();
          }
          break;
      }

      case 4:
      {
          string searchName;
          cout << "Search for a student by name: ";
          cin >> ws;
          getline(cin, searchName);

          auto it = find_if(studentList.begin(), studentList.end(),
                            [&searchName](Student& student) {
                                return student.getName() == searchName;
                            });

          if (it != studentList.end()) {
              cout << "Student found:" << endl;
              it->printStudentInfo();
          } else {
              cout << "Student not found." << endl;
          }
          break;
      }
      default:
          cout<< "Wrong selection, stopping..."<<endl;
          break;
      }
  } while(selection < 5);

return 0;
}
