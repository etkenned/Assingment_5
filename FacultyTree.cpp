#include "FacultyTree.h"
#include <fstream>
#include <string>
using namespace std;

FacultyTree::FacultyTree()
{
  root = NULL;
}

FacultyTree::~FacultyTree()
{

}

void FacultyTree::insert(int s, string n, string l, string m) // add the rest of the Faculty part requirments
{
  //check if Faculty already exists, if no then continue
  FacultyNode *node = new FacultyNode(s, n, l, m);

  if(isEmpty())
  {
    root = node;
  }
  else//not an empty tree . need to find insertion point
  {
    FacultyNode *current = root;
    FacultyNode *parent;

    while(true)// iterate throught the tree
    {
      parent = current;

      if(s < current->facultyID)
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

void FacultyTree::print()
{
  recPrint(root);
}

void FacultyTree::recPrint(FacultyNode * node) // recursive print
{
    if(node == NULL)
    {
      return;
    }
    recPrint(node->left);
    cout << node->facultyID << " " << node->name << " " << node->level << " " << node->department << " " << node->adviseesID << endl;
    recPrint(node->right);
}

void FacultyTree::saveTree()
{
  recSave(root);
}

void FacultyTree::recSave(FacultyNode * node)
{

  if(node == NULL)
  {
    return;
  }
  fstream stSaveFile("FacultySaveData.txt");
  if(stSaveFile.is_open()) // recursively reads through the tree and writes all the data to a text file
  {
    recSave(node->left);
    stSaveFile << node->facultyID << " " << node->name << " " << node->level << " " << node->department << " " << node->adviseesID << endl;
    recSave(node->right);
  }

}

bool FacultyTree::contains(int id)
{
  if(isEmpty())
  {
   return false;
  }
  else// not an empty tree
  {
    FacultyNode *current = root;

    while(current->facultyID != id)
    {
      if(id < current->facultyID)//go left
      {
        current = current->left;
      }
      else
      {
         current = current->right;
       }
       if(current == NULL)
         return false;
     }
   }
   return true;
}

bool FacultyTree::isEmpty()
{
  return root == NULL;
}

bool FacultyTree::deleteNode(FacultyNode * node)
{
  deleteRec(node->facultyID);
}

bool FacultyTree::deleteRec(int id)
{
  if(contains(id))
  {
    FacultyNode * parent = root;
    FacultyNode * current = root;
    bool isLeft = true;
    while(current->facultyID != id)
    {
      parent = current;
      if(current->facultyID > id)
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
      FacultyNode* successor = getSuccessor(current);
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

FacultyNode* FacultyTree::getSuccessor(FacultyNode* d)
{
  FacultyNode *sp = d; //successors parent
  FacultyNode *successor = d;
  FacultyNode *current = d->right;

  while(current != NULL)//
  {
    sp = successor;
    successor = current;
    current = current->left;
  }
  if(successor != d->right)
  {
    sp->left = successor->right;
    successor->right = current->right;
  }
  return successor;
}

void FacultyTree::removeAdvisee(int fid, int sid)
{
  if(contains(fid))
  {
    FacultyNode *current = root;

    while(current->facultyID != fid)
    {
      if(fid < current->facultyID)//go left
      {
        current = current->left;
      }
      else
      {
         current = current->right;
      }
    }

    int * adviseeArray = current->adviseesID; // saves a copy of the advisee array

    for(int i = 0; i < 9; i++) // removes the student from the list
    {
      if(adviseeArray[i] == sid)
      {
        adviseeArray[i] == 0;
      }
    }
    current->adviseesID = adviseeArray;// replaces array with new updated list.
  }
}

void FacultyTree::printFacultyData(int id)
{
  if(contains(id))
  {
    FacultyNode *current = root;

    while(current->facultyID != id)
    {
      if(id < current->facultyID)//go left
      {
        current = current->left;
      }
      else
      {
         current = current->right;
      }
    }

    cout << current->facultyID << " " << current->name << " " << current->level << " " << current->department << " " << endl;
    int * adviseeArray = current->adviseesID; // saves a copy of the advisee array

    for(int i = 0; i < 9; i++) // prints the list of advisees
    {
      if(adviseeArray[i] == id)
      {
        cout << adviseeArray[i];
      }
    }
  }
}

int FacultyTree::printAdvisees(int id)
{
  if(contains(id))
  {
    FacultyNode *current = root;

    while(current->facultyID != id)
    {
      if(id < current->facultyID)//go left
      {
        current = current->left;
      }
      else
      {
         current = current->right;
      }
    }
    int * adviseeArray = current->adviseesID; // saves a copy of the advisee array
    return adviseeArray[0];
  }
  else
  {
    return 0;
  }
}
