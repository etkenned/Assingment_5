#include "StudentTree.h"

using namespace std;

StudentTree::StudentTree()
{
  root = NULL;
}
virtual StudentTree::~StudentTree()
{

}

void StudentTree::insert(int id) // add the rest of the student part requirments
{
  //check if student already exists, if no then continue
  StudentNode *node = new StudentNode(id);

  if(isEmpty())
  {
    root = node;
  }
  else//not an empty tree . need to find insertion point
  {
    StudentNode *current = root;
    StudentNode *parent;

    while(true)// iterate throught the tree
    {
      parent = current;

      if(id < current->studentID)
      {
        current = current->left;//go left

        if(current == NULL) //we found the spot
        {
          parent->left = node;
          break;
        }
      }
      else//go right
      {
        current = current->right;
        if(current == NULL)
        {
          parent->right = node;
          break;
        }
      }

    }
  }
}

bool StudentNode::contains(int id)
{

}

bool StudentTree::deleteNode(int id)
{

}

bool StudentTree::isEmpty()
{

}

bool StudentTree::deleteRec()
{

}
/*
StudentNode* getSuccessor(StudentNode* d);
StudentNode* getMin();
StudentNode* getMax();
*/
