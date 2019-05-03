#include "Menue.h"
#include <string>
using namespace std;

Menue::Menue()
{
  string input = "";
  while(true)
  {
    cout << "How would you like to manipulate the database? Enter the coresponding number : " << endl;
    cout << "(1) Print all students and their information" << endl;
    cout << "(2) Print all faculty and their information" << endl;
    cout << "(3) Find and display student information given the students id" << endl;
    cout << "(4) Find and display faculty information given the faculty id" << endl;
    cout << "(5) Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "(6) Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "(7) Add a new student" << endl;
    cout << "(8) Delete a student given the id" << endl;
    cout << "(9) Add a new faculty member" << endl;
    cout << "(10) Delete a faculty member given the id." << endl;
    cout << "(11) Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "(12) Remove an advisee from a faculty member given the ids" << endl;
    cout << "(13) Rollback" << endl;
    cout << "(14) Exit" << endl;
    getline(cin, input);

    if(input == "1")
    {
      printStudents();
    }
    else if(input == "2")
    {
      printFaculty();
    }
    else if(input == "3")
    {
      string id;
      cout << "Enter the ID of a student." << endl;
      getline(cin, id);
      findStudent(stoi(id));
    }
    else if(input == "4")
    {
      string id;
      cout << "Enter the ID of a faculty member." << endl;
      getline(cin, id);
      findFaculty(stoi(id));
    }
    else if(input == "5")
    {
      string id;
      cout << "Enter the ID of the student." << endl;
      getline(cin, id);
      studentAdvisor(stoi(id));
    }
    else if(input == "6")
    {
      string id;
      cout << "Enter the ID of the faculty member." << endl;
      getline(cin, id);
      facultyAdvisee(stoi(id));
    }
    else if(input == "7")
    {
      addStudent();
    }
    else if(input == "8")
    {
      string id;
      cout << "Enter the ID of a student." << endl;
      getline(cin, id);
      deleteStudent(stoi(id));
    }
    else if(input == "9")
    {
      addFaculty();
    }
    else if(input == "10")
    {
      string id;
      cout << "Enter the ID of the faculty member." << endl;
      getline(cin, id);
      deleteFaculty(stoi(id));
    }
    else if(input == "11")
    {
      string id1;
      cout << "Enter the ID of the student." << endl;
      getline(cin, id1);
      string id2;
      cout << "Enter the ID of the faculty member." << endl;
      getline(cin, id2);
      changeStudentAdvisor(stoi(id1), stoi(id2));
    }
    else if(input == "12")
    {
      string id1;
      cout << "Enter the ID of the faculty member." << endl;
      getline(cin, id1);
      string id2;
      cout << "Enter the ID of the student." << endl;
      getline(cin, id2);
      removeFacultyAdvisee(stoi(id1), stoi(id2));
    }
    else if(input == "13")
    {

    }
    else if(input == "14")
    {
      break;
    }
    else
    {
      cout << "invalid input, please try again" << endl;
    }
  }
}
Menue::~Menue()
{

}

void Menue::printStudents() // 1
{
  sTree.print();
}
void Menue::printFaculty() // 2
{
  fTree.print();
}
void Menue::findStudent(int id) // 3
{
  sTree.printStudentData(id);
}
void Menue::findFaculty(int id) // 4
{
  fTree.printFacultyData(id);
}
void Menue::studentAdvisor(int id) // 5
{
  fTree.printFacultyData(sTree.findAdvisor(id));
}
void Menue::facultyAdvisee(int id) // 6
{
  sTree.printStudentData(fTree.printAdvisees(id));
}
void Menue::addStudent() // 7
{
  string sid;
  string n = "";
  string l = "";
  string m = "";
  string g;
  string a;
  cout << "Enter an ID for the student : " << endl;
  getline(cin, sid);
  cout << "Enter the name of the student : " << endl;
  getline(cin, n);
  cout << "Enter level of the student : " << endl;
  getline(cin, l);
  cout << "Enter the major of the student : " << endl;
  getline(cin, m);
  cout << "Enter the GPA of the student : " << endl;
  getline(cin, g);
  cout << "Enter the student's advisor's ID : " << endl;
  getline(cin, a);
  sTree.insert(stoi(sid), n, l, m, stod(g), stoi(a));// creates the new student and inserts the student into the tree
}
void Menue::deleteStudent(int id) // 8
{
  sTree.deleteRec(id);
}
void Menue::addFaculty() // 9
{
  string fid;
  string n = "";
  string l = "";
  string d = "";
  cout << "Enter an ID for the faculty member : " << endl;
  getline(cin, fid);
  cout << "Enter the name of the faculty member : " << endl;
  getline(cin, n);
  cout << "Enter level of the faculty member : " << endl;
  getline(cin, l);
  cout << "Enter the department of the faculty member : " << endl;
  getline(cin, d);

  fTree.insert(stoi(fid), n, l, d);// creates the new faculty member and inserts them into the tree
}
void Menue::deleteFaculty(int id) // 10
{
  fTree.deleteRec(id);
}
void Menue::changeStudentAdvisor(int sid, int fid) // 11
{
  sTree.changeAdvisor(sid, fid);
}
void Menue::removeFacultyAdvisee(int fid, int sid) // 12
{
  fTree.removeAdvisee(fid, sid);
}
void Menue::rollback() // 13
{
  //load the previous save file
}
