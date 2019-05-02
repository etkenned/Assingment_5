#include "Menue.h"

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
    input << cin;

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
      int id = 0;
      cout << "Enter the ID of a student." << endl;
      id << cin;
      findStudent(id);
    }
    else if(input == "4")
    {
      int id = 0;
      cout << "Enter the ID of a faculty member." << endl;
      id << cin;
      findFaculty(id);
    }
    else if(input == "5")
    {
      int id = 0;
      cout << "Enter the ID of the student." << endl;
      id << cin;
      studentAdvisor(id);
    }
    else if(input == "6")
    {
      int id = 0;
      cout << "Enter the ID of the faculty member." << endl;
      id << cin;
      facultyAdvisee(id);
    }
    else if(input == "7")
    {
      addStudent()
    }
    else if(input == "8")
    {
      int id = 0;
      cout << "Enter the ID of a student." << endl;
      id << cin;
      deleteStudent(id);
    }
    else if(input == "9")
    {
      addFaculty();
    }
    else if(input == "10")
    {
      int id = 0;
      cout << "Enter the ID of the faculty member." << endl;
      id << cin;
      deleteFaculty(id);
    }
    else if(input == "11")
    {
      int id1 = 0;
      cout << "Enter the ID of the student." << endl;
      id1 << cin;
      int id2 = 0;
      cout << "Enter the ID of the faculty member." << endl;
      id2 << cin;
      changeStudentAdvisor(id1, id2);
    }
    else if(input == "12")
    {
      int id1 = 0;
      cout << "Enter the ID of the faculty member." << endl;
      id1 << cin;
      int id2 = 0;
      cout << "Enter the ID of the student." << endl;
      id2 << cin;
      removeFacultyAdvisee(id1, id2);
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
  fTree.findFaculty(sTree.findAdvisor(id));
}
void Menue::facultyAdvisee(int id) // 6
{
  sTree.findStudent(ftree.printAdvisees(id));
}
void Menue::addStudent() // 7
{
  int sid = 0;
  string n = "";
  string l = "";
  string m = "";
  double g = 0.0;
  int a = 0;
  cout << "Enter an ID for the student : " << endl;
  sid << cin;
  cout << "Enter the name of the student : " << endl;
  n << cin;
  cout << "Enter level of the student : " << endl;
  l << cin;
  cout << "Enter the major of the student : " << endl;
  m << cin;
  cout << "Enter the GPA of the student : " << endl;
  g << cin;
  cout << "Enter the student's advisor's ID : " << endl;
  a << cin;
  sTree.insert(sid, n, l, m, g, a);// creates the new student and inserts the student into the tree
}
void Menue::deleteStudent(int id) // 8
{
  sTree.deleteNode(id);
}
void Menue::addFaculty() // 9
{
  int sid = 0;
  string n = "";
  string l = "";
  string d = "";
  int[10] advID;
  int a = 0;
  cout << "Enter an ID for the faculty member : " << endl;
  fid << cin;
  cout << "Enter the name of the faculty member : " << endl;
  n << cin;
  cout << "Enter level of the faculty member : " << endl;
  l << cin;
  cout << "Enter the department of the faculty member : " << endl;
  d << cin;

  cout << "How many students are being advised by this faculty member?" << endl;
  int numAdvisees = 0; // number of students the faculty advises and used for setting the for loop
  int newID = 0; // used to add each inputed ID to the array
  numAdvisees << cin;
  for (int i = 0; i < numAdvisees - 1; i++)
  {
    cout << "Enter the ID of a student the faculty member is advising : " << endl;
    newID << cin;
    advID[i] = newID;
  }

  fTree.insert(fid, n, l, d, advID);// creates the new faculty member and inserts them into the tree
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
