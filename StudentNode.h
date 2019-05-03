#include <iostream>
#include <string>
using namespace std;

class StudentNode
{
  public:
    StudentNode();
    StudentNode(int s, string n, string l, string m, double g, int a);
    virtual ~StudentNode();

    int studentID;
    string name;
    string level;
    string major;
    double GPA;
    int advisorID;
    StudentNode *left;
    StudentNode *right;
};
