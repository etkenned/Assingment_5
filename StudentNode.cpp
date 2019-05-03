#include <iostream>
#include "StudentNode.h"
#include <string>
using namespace std;
StudentNode::StudentNode()
{
  left = NULL;
  right = NULL;
}
StudentNode::StudentNode(int s, string n, string l, string m, double g, int a)
{
  left = NULL;
  right = NULL;
  studentID = s;
  name = n;
  level = l;
  major = m;
  GPA = g;
  advisorID = a;
}
StudentNode::~StudentNode()
{
  //run through and delete everything
}
