#include "StudentTree.h"
#include <fstream>
using namespace std;

StudentTree::StudentTree()
{
  root = NULL;
}

virtual StudentTree::~StudentTree()
{

}

void StudentTree::insert(int s, string n, string l, string m, double g, int a) // add the rest of the student part requirments
{
  //check if student already exists, if no then continue
  StudentNode *node = new StudentNode(s, n, l, m, g, a);

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

      if(s < current->studentID)
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

void StudentTree::print()
{
  recPrint(root);
}

void StudentTree::recPrint(StudentNode * node) // recursive print
{
    if(node == NULL)
    {
      return;
    }
    recPrint(node->left);
    cout << node->studentID << " " << node->name << " " << node->level << " " << node->major << " " << node->GPA << " " << node-> advisorID << endl;
    recPrint(node->right);
}

void StudentTree::saveTree()
{
  recSave(root);
}

void StudentTree::recSave(StudentNode * node)
{
  if(node == NULL)
  {
    return;
  }
  fstream stSaveFile("StudentSaveData.txt");
  if(stSaveFile.is_open()) // recursively reads through the tree and writes all the data to a text file
  {
    recSave(node->left);
    stSaveFile << node->studentID << " " << node->name << " " << node->level << " " << node->major << " " << node->GPA << " " << node-> advisorID << endl;
    recSave(node->right);
  }

}

bool StudentTree::contains(int id)
{
  if(isEmpty())
  {
   return false;
  }
  else// not an empty tree
  {
    StudentNode *current = root;

    while(current->studentID != id)
    {
      if(id < current->studentID)//go left
      {
        current = current->left;
      }
      else
      {
         current = curent->right;
       }
       if(current == NULL)
         return false;
     }
   }
   return true;
}

bool StudentTree::isEmpty()
{
  return root == NULL;
}

bool StudentTree::deleteNode(StudentNode * node)
{
  deleteRec(node->studentID);
}

bool StudentTree::deleteRec(int id)
{
  if(contains(id))
  {
    studentNode * parent = root;
    studentNode * current = root;
    bool isLeft = true;
    while(current->studentID != id)
    {
      parent = current;
      if(current->studentID > id)
      {
        isLeft = true;
        current = current->left;
      }
      else
      {
        isLeft = false;
        current = current->right;
      }
      if(current == NULL)
      {
        return false;
      }
    }
    if(current->left == NULL && current->right == NULL)
    {
      if(parent == current)
      {
        root = NULL;
        return true;
      }
      else if(isLeft)
      {
        parent->left = NULL;
        return true;
      }
      else
      {
        parent->right = NULL;
        return true;
      }
      delete current;
    }
    else if(current->left != NULL && current->right == NULL)
    {
      if(parent == current)
      {
        root = current->left;
        return true;
      }
      else if(isLeft)
      {
        parent->left = current->left;
        return true;
      }
      else if(!isLeft)
      {
        parent->right = current->left;
        return true;
      }
      current->left = NULL;
      delete current;
    }
    else if(current->right != NULL && current->left == NULL)
    {
      if(parent == current)
      {
        root = current->right;
        return true;
      }
      else if(isLeft)
      {
        parent->left = current->right;
        return true;
      }
      else if(!isLeft)
      {
        parent->right = current->right;
        return true;
      }
      current->right = NULL;
      delete current;
    }
    else
    {
      studentNode* successor = getSuccessor(current);
      if(current == root)
      {
        root = successor;
      }
      else if(isLeft)
      {
        parent->left = successor;
        return true;
      }
      else
      {
        parent->right = successor;
        return true;
      }
      successor->left = current->left;
    }
    return true;
  }
  else
  {
    return false;
  }
}

StudentNode* getSuccessor(StudentNode* d)
{
  StudentNode *sp = d; //successors parent
  StudentNode *successor = d;
  StudentNode *current = d->right;

  while(current != NULL)//
  {
    sp = successor;
    sucessor = current;
    current = current->left;
  }
  if(sucessor != d->right)
  {
    sp->left = successor->right;
    successor->right = current->right;
  }
  return sucessor;
}

void StudentTree::changeAdvisor(int sid, int fid)
{
  if(contains(sid))
  {
    StudentNode *current = root;

    while(current->studentID != sid)
    {
      if(sid < current->studentID)//go left
      {
        current = current->left;
      }
      else
      {
         current = curent->right;
       }
     }
     current->advisorID = fid;
     cout << "Change complete";
   }
   else
   {
     cout << "Student Not Found";
   }
    // changes students current advisors ID to the one inputed
}

void StudentTree::printStudentData(int id)
{
  if(contains(id))
  {
    StudentNode *current = root;

    while(current->studentID != id)
    {
      if(id < current->studentID)//go left
      {
        current = current->left;
      }
      else
      {
         current = curent->right;
       }
     }
     cout << current->studentID << " " << current->name << " " << current->level << " " << current->major << " " << current->GPA << " " << current->advisorID << endl; // prints all the students data
   }
   else
   {
     cout << "Student Not Found";
   }
}

int StuddentTree::findAdvisor(int sid)
{
  if(contains(sid))
  {
    StudentNode *current = root;

    while(current->studentID != sid)
    {
      if(sid < current->studentID)//go left
      {
        current = current->left;
      }
      else
      {
         current = curent->right;
       }
     }
    return (current->advisorID);
   }
   else
   {
     cout << "Student Not Found";
     return 0;
   }
}

void StudentTree::loadSave()
{

}
