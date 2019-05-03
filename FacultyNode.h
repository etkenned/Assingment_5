#include <iostream>
#include <string>
using namespace std;
class FacultyNode {
  public:
    FacultyNode();
    FacultyNode(int f, string n, string l, string d);
    virtual ~FacultyNode();

    int facultyID;
    string name;
    string level;
    string department;
    int* adviseesID;
    FacultyNode *left;
    FacultyNode *right;
};
