#include "StudentNode.h"

StudentNode::StudentNode()
{
  left = NULL;
  right = NULL;
}
StudentNode::StudentNode(int s, string n, string l, string m, double g, int a)
{
  left = NULL;
  right = NULL;
  studentID = sid;
  name = n;
  level = l;
  major = m;
  GPA = g;
  advisorID = a;
  
}
studentNode::~studentNode()
{
  //run through and delete everything
}
