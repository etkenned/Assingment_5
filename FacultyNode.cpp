#include "FacultyNode.h"
#include <iostream>
#include <string>
using namespace std;
FacultyNode::FacultyNode()
{
  left = NULL;
  right = NULL;
}
FacultyNode::FacultyNode(int f, string n, string l, string d)
{
  left = NULL;
  right = NULL;
  facultyID = f;
  name = n;
  level = l;
  department = d;

  cout << "How many students are being advised by this faculty member? : " << endl;
  int numAdvisees = 0;
  string input = "";
  getline(cin, input);
  numAdvisees = stoi(input);
  string tempID = "";
  for(int i = 0; i < numAdvisees; i ++)
  {
    cout << "Enter the student's ID : " << endl;
    getline(cin, tempID);
    adviseesID[i] = stoi(tempID);
  }

}
FacultyNode::~FacultyNode()
{
  //run through and delete everything
}
